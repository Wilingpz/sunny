#include<iostream>
#include<vector>
using namespace std;
/*0000000000000000000000000000000000000000000000000*/
class Solution 
{
public:
	void reverseString(vector<char>& s) 
	{
		int temp=0;
		int l = s.size();
		for (int i = 0; i <l/2;i++)
		{
			temp = s[i];
			s[i]=s[l-i-1];
			s[l - 1-i] = temp;
		}
	}
};
/*00000000000000000000000000000000000000000000*/
class Solution 
{
public:
	void reverseString(vector<char>& s) 
	{
		for (int i = 0; 2 * i + 1 < s.size(); i++)
		{
			swap(s[i], s[s.size() - 1 - i]);
		}
	}
};
/*000000000000000000000000000000000000000000000000000000000*/
#include <algorithm>
#include <iostream>
using namespace std;
class Solution 
{
public:
	void reverseString(vector<char>& s) 
	{
		reverse(s.begin(), s.end());//reverse函数包括于algorithm头文件
		//1.reverse函数反转string
		//2.reverse函数反转字符数组
		//2.自定义reverse函数反转任意类型数组
	}
};

