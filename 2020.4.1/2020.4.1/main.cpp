//�����������ҵڶ����ַ����ڵ�һ���ַ����г����˼��Σ�
#include<iostream>
#include<string>
using namespace std;
int main1()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		int pos = 0;
		int count = 0;
		while ((pos = str1.find(str2, pos))!=string::npos)//find(Ҫ�ҵ��ַ��������ĸ�λ�ÿ�ʼ)
		{
			pos += str2.size();//�ҵ����λ�ú󣬴�������һ��λ�ÿ�ʼ
			count++;
		}
		cout << count << endl;
	}
	system("pause");
	return 0;
}