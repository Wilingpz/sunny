#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1;
	while (getline(cin, s1))
	{
		int count = 0;
		for (int i = 0; i < s1.size();i++)
		{
			if (s1[i] == ' ')
			{
				count++;
			}
			if (s1[i] =='"')//˫��������Ŀո�����
			{
				do
				{
					i++;
				} while (s1[i] != '"');
			}
		}
		cout << count + 1 << endl;//ʵ��count�����count�ո��һ��
		int flag = 1;//ͨ��flag��ʶȷ���ո���˫��������Ļ��������
		for (int i = 0; i < s1.size(); i++)
		{
			//���Ǵ�ӡ,��˫������Ҫ��ӡ�ո�
			if (s1[i] == '"')
			{
				flag ^= 1;
			}
			if (s1[i] != ' ' && s1[i] != '"')
			{
				cout << s1[i];
			}
			if (s1[i] == ' ' && flag == 0)
			{
				cout << s1[i];
			}
			if (s1[i] == ' ' && flag != 0)
			{
				cout << endl;
			}
		}

		return 0;
	}
}