#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution
{
public:
	bool isPalindrome(string s)
	{
		vector<char>tmp;
		for (auto &i : s)
		{
			if ((i >= 'a' && i<='z') || (i>='0' && i <= '9'))
			{
				tmp.push_back(i);
			}
			if (i>='A' && i <= 'Z')
			{
				tmp.push_back(i - 'A' + 'a');
			}
		}
		for (int i = 0; i < tmp.size()/2; i++)
		{
			if (tmp[i] != tmp[tmp.size() - 1 - i])
			{
				return false;
			}
		}
		return true;
	}
};