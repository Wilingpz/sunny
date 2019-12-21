//题目描述
//问题描述：在计算机中，通配符一种特殊语法，
//广泛应用于文件搜索、数据库、正则表达式等领域。
//现要求各位实现字符串通配符的算法。
//要求：
//实现如下2个通配符：
//*：匹配0个或以上的字符（字符由英文字母和数字0 - 9组成，不区分大小写。下同）
//？：匹配1个字符
//
//输入：
//通配符表达式；
//一组字符串。
//
//输出：
//返回匹配的结果，正确输出true，错误输出false
//输入描述 :
//先输入一个带有通配符的字符串，再输入一个需要匹配的字符串
//输出描述 :
//返回匹配的结果，正确输出true，错误输出false
#include<iostream>
#include<string>
using namespace std;

bool StringMatch(const char*parttern, const char*str)
{
	if (*parttern == '\0'&&*str == '\0')
	{
		return true;
	}
	if ((*parttern == '\0') || (*str == '\0'))
	{
		return false;
	}
	if (*parttern == '?')
	{
		return StringMatch(parttern + 1, str + 1);
	}
	else if (*parttern == '*')
	{
		return (StringMatch(parttern + 1, str) || StringMatch(parttern + 1, str + 1) || StringMatch(parttern, str + 1));
	}
	else if (*parttern == *str)
	{
		return  StringMatch(parttern + 1, str + 1);
	}
		return false;
}

int main()
{
	string parttern, str;
	while (cin >> parttern >> str)
	{
		bool ret = StringMatch(parttern.c_str(), str.c_str());
		/*const char* c_str() 包含于 string 头文件里
			返回一个常量c字符串，内容与本string串相同
			但是当本string串内容改变或者被析构后，返回字符串也不会改变
			因为返回的字符串是从新通过new char[]出来的*/
		if (ret)
		{
			cout << "true" << endl;
		}
		else
		{
			cout << "false" << endl;
		}
	}
	system("pause");
	return 0;
}