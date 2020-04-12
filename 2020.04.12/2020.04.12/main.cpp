//Emacs计算器
#include<iostream>
#include<stack>
#include<string>
#include<cstdlib>
using namespace std;

#if 0
int main()//没有考虑输入的数大于9的情况
{
	int num;
	while (cin >> num)
	{
		if ((num<3) || (num>50))
		{
			return 0;
		}
		stack<int>numcup;
		int num1 = 0;
		int num2 = 0;
		char res;
		for (int i = 0; i < num; i++)
		{
			cin >> res;
			if ((res >= '0') && (res <= '9'))
			{
				numcup.push((res-'0'));
			}
			else if ((numcup.size()==1)&&( res == '+'))
			{
				num1 = numcup.top();
				numcup.pop();
				num2 = numcup.top();
				numcup.pop();
				num2= num2  + num1;
				numcup.push(num2);
			}
			else if ((numcup.size() == 1) && (res == '-'))
			{
				num1 = numcup.top();
				numcup.pop();
				num2 = numcup.top();
				numcup.pop();
				num2 = num2 - num1;
				numcup.push(num2);
			}
			else if ((numcup.size() == 1) && (res == '*'))
			{
				num1 = numcup.top();
				numcup.pop();
				num2 = numcup.top();
				numcup.pop();
				num2 = num2 * num1;
				numcup.push(num2);
			}
			else if ((numcup.size() == 1) && (res == '/'))
			{
				num1 = numcup.top();
				numcup.pop();
				num2 = numcup.top();
				numcup.pop();
				if (num1 == 0)
				{
					return 0;
				}
				num2 = num2 / num1;
				numcup.push(num2);
			}
		}
		cout << numcup.top() << endl;
		system("pause");
	}
	return 0;
}
#else
int main1()
{
	int num;
	while (cin >> num)
	{
		if ((num<3) || (num>50))
		{
			return 0;
		}
		stack<int>numcup;
		int num1 = 0;
		int num2 = 0;
		string res;
		for (int i = 0; i<num; i++)
		{
			cin >> res;
			if ((res[0]>='0') && (res[0] <= '9'))
			{
				numcup.push(atoi(res.c_str()));
				//atoi函数包含在stdlib.h中，将一个字符串（数字类型的）转为数字
				//int atio(const char *nptr)
				//参数类型是char*所以这里要将string转化为c类型的string
			}
			else
			{
				num1 = numcup.top();
				numcup.pop();
				num2 = numcup.top();
				numcup.pop();
				if (res == "+")
				{
					num2 = num2 + num1;
					numcup.push(num2);
				}
				else if (res == "-")
				{
					num2 = num2 - num1;
					numcup.push(num2);
				}
				else if (res == "*")
				{
					num2 = num2 * num1;
					numcup.push(num2);
				}
				else if (res == "/")
				{
					num2 = num2 / num1;
					numcup.push(num2);
				}
			}
		}
		cout << numcup.top() << endl;
		system("pause");
	}
	return 0;
}




#endif