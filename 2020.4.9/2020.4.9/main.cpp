//�õ�һ���ַ����������Ӵ�
//��������Ӵ������У��ʺϽ϶̳��ȣ�
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

# if 0
int main()
{
	string str;
	while (cin >> str)
	{
		for (int i = 0; i < str.size(); i++)
		{
			for (int j = i; j < str.size(); j++)
			{
				cout << str.substr(i, j) << endl;
			}
		}
	}
	system("pause");
	return 0;
}
#else


int main()
{
	string m, n;
	while (cin >> m >> n)
	{
		if (m.length() > n.length())
		{
			string temp;
			temp = m;
			m = n;
			n = temp;
		}
		vector<string>temp;
		int maxlenth = 0;
		//1���õ��ַ���n�������ִ�����vector<string>������
		for (int i = 0; i < n.size(); i++)
		{
			for (int j = i; j < n.size(); j++)
			{
				temp.push_back(n.substr(i, j));
			}
		}
		//2����find���������Ƿ����m�У��������¼���Ĵ��ͳ���
		for (auto &i : temp)
		{
			if ((m.find(i) != string::npos) && (i.length()>maxlenth))
			{
					maxlenth = i.length();	
			}
		}
		//3�����
		cout <<maxlenth<< endl;
	}
	system("pause");
	return 0;
}
#endif

