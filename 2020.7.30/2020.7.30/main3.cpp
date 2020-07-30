#include<iostream>
#include<string>
using namespace std;

#if 0
class Solution
{
public:
	int firstUniqChar(string s)
	{
		int cout[256] = { 0 };
		for (int i = 0; i < s.size(); i++)
		{
			if (s.find(s[i], 0) == s.rfind(s[i], s.size()))
			{
				return i;
			}
		}
		return -1;
	}
};
#else
class Solution
{
public:
	int firstUniqChar(string s)
	{
		//Ð´²©¿Í
		int Hash[26] = { 0 };
		for (auto &i : s)
		{
			Hash[i - 'a']++;
		}

		for (int i = 0; i < s.size(); i++)
		{
			if (Hash[s[i] - 'a'] == 1)
			{
				return i;
			}
		}
		return -1;
	}
};
#endif
int main8()
{
	string s("hello");
	Solution a;
	cout << a.firstUniqChar(s) << endl;
	return 0;
}