#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	int hashtable[256] = { 0 };
	for (size_t i = 0; i < s2.size(); ++i)
		//for(auto &i:s2)
	{
		hashtable[s2[i]]++;//��¼ÿһ���ַ����ֵĵĴ���
	}
	string ret;
	for (size_t i = 0; i < s1.size(); ++i)
		//for (auto &i:s1)
	{
		if (hashtable[s1[i]] == 0)
		{
			ret += s1[i];
		}
	}
	cout << ret << endl;
	system("pause");
	return 0;
}



