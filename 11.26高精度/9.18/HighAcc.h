#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstring>//memset
using namespace std;

#define MAXSIZE 10000
class hightAcc{
	char m_data[MAXSIZE];//�߾��ȴ���һ��charһλ
	size_t m_size;//���ֳ���
public:
	hightAcc(string s) ://��string ���͵Ĳ�������
		m_size(s.size())
	{
		memset(m_data, 0, MAXSIZE);//����
		string::reverse_iterator i;//�������������Ҫ����������ַ�����洢
		//�Ƚ����׽��м��㣩
		int j = 0;
		for (i = s.rbegin(); i != s.rend(); i++){
			m_data[j] = *i - '0';//�����Ϊ���֣�����m_data��
			j++;
		}
	}

	hightAcc() ://�޲ι���
		m_size(1)
	{
		memset(m_data, 0, MAXSIZE);
	}

	hightAcc operator +(const hightAcc &s) const//����+  ��һ��const��ʾ&s���ܸı�
		//�ڶ���const��ʾ������thisָ��ָ�򲻿��Ըı�
	{
		hightAcc res;//�洢����ı���
		size_t maxsize = m_size > s.m_size ? m_size : s.m_size;
		int i, tmp;

		for (i = 0; i < maxsize; i++){
			tmp = m_data[i] + s.m_data[i] + res.m_data[i];//res.m_data[]
			//�����޲ι���Ϊ0�ˣ�ÿһλ���
			res.m_data[i] = tmp % 10;//ȡ����λ
			res.m_data[i + 1] = tmp / 10;//��λ
		}
		res.m_size = maxsize + res.m_data[i];//���λΪ1��1�������0
		return res;
	}

	hightAcc operator *(const hightAcc &s) const{
		hightAcc res;
		int i, j, tmp;

		if (m_size == 1 && m_data == 0 ||
			s.m_size == 1 && s.m_data == 0){
			return res;
		}

		for (i = 0; i < m_size; i++){
			for (j = 0; j < s.m_size; j++){
				tmp = m_data[j] * s.m_data[j] + res.m_data[i + j];
				res.m_data[i + j] = tmp % 10;
				res.m_data[i + j + 1] += tmp / 10;
			}
		}
		res.m_size = m_size + s.m_size - !res.m_data[i + j - 1];
	}

	operator string (){//ǿת����������أ������з���ֵ
		string s;
		int i;
		for (i = m_size - 1; i >= 0; i--){
			s.push_back(m_data[i] + '0');//ת��Ϊ�ַ����д�ӡ
		}
		return s;
	}
};
