#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

int main1()
{
	string tmp;
	getline(cin, tmp);

	unordered_set<char>s;
	
	for (auto &i : tmp)
	{
		if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
		{
			s.insert(i);
		}
	}//����û�а취��unordered_set����Ϊ�������˳�����ݹ�ϣ������������ֻ��ȥ�ض���

	for (auto &i : s)
	{
		cout << i;
	}
	cout << endl;
	
	system("pause");
	return 0;
}