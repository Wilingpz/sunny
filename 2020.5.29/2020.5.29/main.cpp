//É¾³ý¹«¹²×Ö·û´®
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str1, str2;
	while (getline(cin,str1) && getline(cin,str2))
	{
		int Hash[256] = { 0 };
		for (long long i = 0; i < str2.size(); i++)
		{
			Hash[str2[i]]++;
		}
		string ret;
		for (long long i = 0; i < str1.size(); i++)
		{
			if (Hash[str1[i]] == 0)
			{
				ret += str1[i];
			}
		}
		cout << ret << endl;
	}
	system("pause");
	return 0;
}