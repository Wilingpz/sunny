#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
#if 0
class Solution 
{
public:
	string reverseStr(string s, int k)
	{
		for (int i = 0; i < s.size(); i += 2 * k)
		{
			int start = i;
			int j = min(int(s.size() - 1), start + k - 1);
			if (i < j)
			{
				reverse(s.begin() + start, s.begin() + j + 1);
			}
		}
		return s;
	}
};
#else
class Solution 
{
public:
	string reverseStr(string s, int k) 
	{
		int mod = s.size() % (2 * k);
		int ret = s.size() / (2 * k);
		int len = s.size() - mod;
			
	    int start = 0, end = start + k;
		while (ret)
		{
			reverse(s.begin() + start, s.begin() + end);
			start = end + k;
			end = start + k;
			ret--;
		}
	    
		if (mod!=0 &&mod < k)
		{
			reverse(s.begin() + len, s.end());

		}
		else if (mod!=0 && mod>=k)
		{
			reverse(s.begin() + len, s.begin() + (len + k));
		}
		return s;
	}
};
#endif
int main7()
{
	string s("abcdefg");
	int k = 2;
	Solution a;
	cout << a.reverseStr(s,k) << endl;
	system("pause");
	return 0;
}