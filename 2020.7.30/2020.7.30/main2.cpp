#include<iostream>
#include<string>
using namespace std;

#if 0
class Solution
{
public:
	bool isPalindrome(string s)
	{
		if (s.empty())
		{
			return true;
		}
		//只考虑数字和字母，标点空格大小写等忽略掉
		string s1;
		for (auto &i : s)
		{
			if (isdigit(i) || (i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z'))
			{
				s1.push_back(i);
			}
		}
		int i = 0, j = s1.size()-1;
		while (j > i && (s1[i] == s1[j] || s1[i] - s1[j] == 32 || s1[j] - s1[i] == 32))
		{
			i++, j--;
		}
		if (i == j || i - 1 == j)
		{
			return true;
		}
		return false;
	}
};
#else
//写博客
class Solution 
{
public:
	bool isPalindrome(string s) 
	{
		if (s.empty())
		{
			return true;
		}
		string s1;
		for (auto &i : s) {
			if (islower(i) || isdigit(i))
			{
				s1.push_back(i);
			}
			else if (isupper(i))
			{
				s1.push_back(i + 32);
			}
		}
		int i = 0, j = s1.size() - 1;
		while (i < j) 
		{
			if (s1[i] != s1[j])
			{
				return false;
			}
			i++;
			j--;
		}
		return true;
	}
};

#endif
int main3()
{
	string s;
	while (getline(cin, s))
	{
		Solution a;
		cout << a.isPalindrome(s) << endl;
	}
	system("pause");
	return 0;
}