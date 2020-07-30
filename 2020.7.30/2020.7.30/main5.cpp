#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//大数加法 写博客
class Solution 
{
public:
	string addStrings(string num1, string num2) 
	{
		int len1 = num1.size();
		int len2 = num2.size();
		int diff = abs(len1 - len2);
		int maxlen = len1 > len2 ? len1 : len2;
		if (len1 > len2)
		{
			num2.insert(0, diff,'0');//从0位置开始，插入diff个0
		}
		else
		{
			num1.insert(0, diff, '0');
		}

		string ret;//存结果
		ret.resize(maxlen);

		int res = 0;//进位

		for (int i = maxlen - 1; i >= 0; i--)
		{
			//化成数字相加，结果再换成字符
			ret[i] = ((num1[i] - '0') + (num2[i] - '0') + res)+'0';
			if (ret[i] > '9')
			{
				ret[i] -= 10;
				res = 1;
			}
			else
			{
				res = 0;
			}
		}
		if (res == 1)
		{
			ret.insert(0, 1, '1');
		}
		return ret;
	}
};

