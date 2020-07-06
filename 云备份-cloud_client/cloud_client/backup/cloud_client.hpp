#pragma once
#define _SCL_SECURE_NO_WARNINGS
#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<unordered_map>
#include<boost/filesystem.hpp>
#include<boost/algorithm/string.hpp>//split��ͷ�ļ�
#include"httplib.h"


class FileUtil
{
public:
	static bool Read(const std::string &name, std::string *body)
	{ //���ļ��ж�ȡ��������
		std::ifstream fs(name, std::ios::binary);
		if (fs.is_open() == false)
		{
			std::cout << "open file " << name << " failed!\n";
			return false;
		}
		//boost::filesystem::file_size()��ȡ�ļ���С
		int64_t fsize = boost::filesystem::file_size(name);
		body->resize(fsize);
		fs.read(&(*body)[0], fsize);//��Ϊbody��һ��ָ��,�Ƚ�����
		if (fs.good() == false)
		{
			std::cout << "file " << name << "read data failed!\n";
			return false;
		}
		fs.close();
		return true;
	}
	static bool Write(const std::string &name, const std::string &body)
	{
		//�����--ofstreamĬ�ϴ��ļ���ʱ������ԭ�ļ���������
		//����д��
		std::ofstream ofs(name, std::ios::binary);//�򿪵�ʱname�ļ������д��name�ļ�
		if (ofs.is_open() == false)
		{
			std::cout << "open file" << name << " failed\n";
			return false;
		}
		ofs.write(&body[0], body.size());//��body���������д���ļ�
		if (ofs.good() == false)
		{
			std::cout << "file " << name << " write data filed!\n";
			return false;
		}
		ofs.close();
		return true;
	}
};

class DataManager
{
	std::string _store_file;//�־û��洢����
	std::unordered_map<std::string, std::string>_backup_list;//����
public:
	DataManager(const std::string &filename) :_store_file(filename)
	{}
	~DataManager()
	{}
	bool Insert(const std::string &key, const std::string &val)//�ļ�����etag��Ϣ
	{
		_backup_list[key] = val;
		Storage();
		return true;
	}
	bool GetEtag(const std::string  &key,std::string *val)
	{
		auto it = _backup_list.find(key);
		if (it == _backup_list.end())
		{
			return false;
		}
		*val = it->second;
		return true;
	}
	bool Storage()//�־û��洢
	{
		//�־û��洢��Ҫ������֯�������л���filename etage\r\n
		std::stringstream tmp;
		auto it = _backup_list.begin();
		for (; it != _backup_list.end(); ++it)
		{
			tmp << it->first << " " << it->second << "\r\n";
		}
		FileUtil::Write(_store_file, tmp.str());
		return true;
	}
	bool InitLoad()
	{
		//����ʱ��ʼ������ԭ������	
		std::string body;
		if (FileUtil::Read(_store_file, &body) == false)
		{
			return false;
		}
		std::vector<std::string>list;
		boost::split(list, body, boost::is_any_of("\r\n"), boost::token_compress_off);
		for (auto &i : list)
		{
			size_t pos = i.find(" ");
			if (pos == std::string::npos)
			{
				continue;
			}
			std::string key = i.substr(0, pos);
			std::string val = i.substr(pos + 1);
			Insert(key, val);
		}
	}
};

//Ŀ¼���ģ��
class CloudClient
{
	std::string _listen_dir;//��ص�ָ��Ŀ¼
	DataManager data_manage;
	std::string _srv_ip;
	uint16_t _srv_port;
public:
	CloudClient(const std::string &filename,const std::string &store_file,const std::string &srv_ip,boost::uint16_t srv_port) : 
		_listen_dir(filename),data_manage(store_file),_srv_ip(srv_ip),_srv_port(srv_port){}
	bool Start()
	{
		data_manage.InitLoad();
		std::vector<std::string>list;
		
		while (1)
	{
		GetBackupFileList(&list);//��ȡ��������Ҫ���ݵ��ļ�����
		for (int i = 0; i < list.size(); i++)
		{
			std::string name = list[i];//���ļ���
			std::string pathname = _listen_dir + name;//�ļ�·����
			std::cout << pathname << "is need to backup\n";
			//��ȡ�ļ���Ϊ��������
			std::string body;
			FileUtil::Read(pathname, &body);
			httplib::Client client(_srv_ip.c_str(), _srv_port);//����˵ĵ�ַ�ͷ���˵Ķ˿�
			std::string req_path = "/" + name;//�õ�����·��
			auto rsp = client.Put(req_path.c_str(), body,"application/octet-stream");
			//���������ļ��ϴ�������·��
			if (rsp == NULL || (rsp!=NULL && rsp->status != 200))
			{
				std::cout << pathname << "backup failed!\n";
				//�ļ��ϴ�ʧ���ˣ����������ݣ��´�ѭ����ʱ���ٴβ���
				continue;
			}
			std::string etag;
			GetEtag(pathname, &etag);
			data_manage.Insert(name, etag);
			//���ݳɹ�����룬������Ϣ
			std::cout << pathname << " backup success\n";
		}
		Sleep(1000);//����1000ms���¼��
	}
		return true;
}
	bool GetBackupFileList(std::vector<std::string>*list)
	{//1������Ŀ¼����أ���ȡָ��Ŀ¼�������ļ�����
	 //2������ļ���������ǰetag
	 //3����data_manage�б����ԭ��etag���жԱ�
		//1.û���ҵ�ԭ��etag���жԱ�
		//2.�ҵ�ԭ��etag�����ǵ�ǰetag��ԭ��etag����ȣ���Ҫ����
		//3.�ҵ�ԭ��etag�������뵱ǰetag�������Ҫ����
		if (boost::filesystem::exists(_listen_dir) == false)
		{
			boost::filesystem::create_directory(_listen_dir);
			//�ļ�·���������򴴽��ļ�·��
		}
		boost::filesystem::directory_iterator begin(_listen_dir);
		boost::filesystem::directory_iterator end;
		for (; begin != end; ++begin)
		{
			if (boost::filesystem::is_directory(begin->status()))
			{
				//����Ŀ¼ֱ��Խ��
				continue;
			}
			std::string pathname = begin->path().string();
			std::string name = begin->path().filename().string();
			std::string cur_etag,old_etag;
			GetEtag(pathname, &cur_etag);//���㵱ǰetag
			data_manage.GetEtag(name, &old_etag);//�ѱ����ļ���etag
			if (cur_etag != old_etag)
			{
				list->push_back(name);//��qi�Ž���Ҫ�����б���
			}
		}
		return true;
	}
	static bool GetEtag(std::string &pathname, std::string *etag)//�����ļ���etag��Ϣ
	{// etag:�ļ���С-�ļ����һ���޸�ʱ��
		//��ϣ�������ʹ��
		int64_t fsize = boost::filesystem::file_size(pathname);//�ļ���С
		time_t mtime = boost::filesystem::last_write_time(pathname);//�ļ����һ���޸�ʱ��
		*etag = std::to_string(fsize) + "-" + std::to_string(mtime);
		return true;
	}
};