#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	string s1;
	while (getline(cin,s1))//考虑输入有空格的情况
	{
		int i = 0;
		string res;
		while (i < s1.size())
		{
			if (isdigit(s1[i]) != 0)
			{
				string tmp;
				while (isdigit(s1[i]) != 0 && i<s1.size())
				{  
					tmp += s1[i];
					i++;
				}
				if (tmp.size()>res.size())
				{
					res = tmp;
				}
			}
			i++;
		}
		cout << res << endl;
		system("pause");
	}
	return 0;
}