#include<iostream>
#include<string>
using namespace std;

//表达式合法判断

class ChkExpression
{
public:
	bool chkLegal(string A)
	{
		int num1 = 0, num2 = 0, num3 = 0;
		for (auto &i : A)
		{
			switch (i)
			{
			case ('{') :
				num1++;
				continue;
			case ('(') :
				num2++;
				continue;
			case('[') :
				num3++;
				continue;
			case ('}') :
				num1--;
				continue;
			case (')') :
				num2--;
				continue;
			case(']') :
				num3--;
				continue;
			}
		}
		if (num1 == 0 && num2 == 0 && num3 == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};


int main1()
{
	ChkExpression a;
	string s1 = "[a+b*(5-4)]*{x+b+b*(({1+2}))}";
	if (a.chkLegal(s1) == 1)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}

	system("pause");
	return 0;
}