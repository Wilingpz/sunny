#include<iostream>
#include<string>
using namespace std;


class Solution 
{
public:
    string compress(string s) 
	{
		int count = 0, i = 0;
		char c = s[0];
		string res;
		while (i < s.size())
		{
			while (s[i] == c)
			{
				count++;
				++i;
			}
			count -= 1;
			if (count != 0)
			{
				res += (count + '0');
			}
			res += c;
			c = s[i];
			count = 0;
		}
		return res;
	}
};


int main1()
{
	Solution a;
	string s = "aac";
	string tmp = a.compress(s);
	cout << tmp<< endl;
	system("pause");
	return 0;
}