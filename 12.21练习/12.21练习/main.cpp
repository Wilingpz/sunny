//��Ŀ����
//�����������ڼ�����У�ͨ���һ�������﷨��
//�㷺Ӧ�����ļ����������ݿ⡢������ʽ������
//��Ҫ���λʵ���ַ���ͨ������㷨��
//Ҫ��
//ʵ������2��ͨ�����
//*��ƥ��0�������ϵ��ַ����ַ���Ӣ����ĸ������0 - 9��ɣ������ִ�Сд����ͬ��
//����ƥ��1���ַ�
//
//���룺
//ͨ������ʽ��
//һ���ַ�����
//
//�����
//����ƥ��Ľ������ȷ���true���������false
//�������� :
//������һ������ͨ������ַ�����������һ����Ҫƥ����ַ���
//������� :
//����ƥ��Ľ������ȷ���true���������false
#include<iostream>
#include<string>
using namespace std;

bool StringMatch(const char*parttern, const char*str)
{
	if (*parttern == '\0'&&*str == '\0')
	{
		return true;
	}
	if ((*parttern == '\0') || (*str == '\0'))
	{
		return false;
	}
	if (*parttern == '?')
	{
		return StringMatch(parttern + 1, str + 1);
	}
	else if (*parttern == '*')
	{
		return (StringMatch(parttern + 1, str) || StringMatch(parttern + 1, str + 1) || StringMatch(parttern, str + 1));
	}
	else if (*parttern == *str)
	{
		return  StringMatch(parttern + 1, str + 1);
	}
		return false;
}

int main()
{
	string parttern, str;
	while (cin >> parttern >> str)
	{
		bool ret = StringMatch(parttern.c_str(), str.c_str());
		/*const char* c_str() ������ string ͷ�ļ���
			����һ������c�ַ����������뱾string����ͬ
			���ǵ���string�����ݸı���߱������󣬷����ַ���Ҳ����ı�
			��Ϊ���ص��ַ����Ǵ���ͨ��new char[]������*/
		if (ret)
		{
			cout << "true" << endl;
		}
		else
		{
			cout << "false" << endl;
		}
	}
	system("pause");
	return 0;
}