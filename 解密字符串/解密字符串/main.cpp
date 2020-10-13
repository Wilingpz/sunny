#include<iostream>
#include<ctype.h>
#include<string>
using namespace std;

int main1()
{
	string s1;
	cin >> s1;
	string res;
	if (s1.size() > 50 || s1.size()<=0)
	{
		cout << '0' << endl;
	}


	for (auto &i : s1)
	{
		if (isalpha(i))
		{
			if (i >= 'a' && i <= 'z')
			{
				if (i == 'a')
				{
					i = 'Z';
				}
				else
				{
					i -= 33;
				}
			}
		else if (i >= 'A' && i <= 'Z')
			{
				 if (i == 'A')
				{
					i = 'z';
				}
				else
				{
					i += 31;
				}
			}
			res.push_back(i);
		}
		if (isdigit(i))
		{
			if (i == '0')
			{
				i = '9';
			}
			else
			{
				i -= 1;
			}
			res.push_back(i);
		}
	}

	cout << res << endl;
	system("pause");
	return 0;
}
