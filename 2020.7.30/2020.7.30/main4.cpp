#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
public:
	string reverseWords(string s)
	{
		int pos = s.find(' ',0), start = 0;
		while (pos != string::npos)
		{
			reverse(s.begin() + start, s.begin() + pos);
			start = pos + 1;
			pos = s.find(' ', start);
		}
		reverse(s.begin() + start, s.end());
		return s;
	}
};
int main4()
{
	string s("Let's take LeetCode contest");
	Solution a;
	cout << a.reverseWords(s) << endl;
	system("pause");
	return 0;
}