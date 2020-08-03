#include<iostream>
#include<string>

using namespace std;
//字符串相乘
class Solution 
{
public:
	string multiply(string num1, string num2) 
	{
		if (num1 == "0" || num2 == "0")
		{
			return num1 == "0" ? num1 : num2;
		}
		if (num1.size() > num2.size())
		{
			swap(num1, num2);//确保num2的size小
		}
		string res(256,'0');//存放结果

		//两数乘积的位数等于两数位数相加和或者和减1；
		int ssize = num1.size() + num2.size() - 1;
		int tmp = 0;

		for (int i = num2.size()-1; i >= 0; i--)
		{
			for (int j = num1.size() - 1; j >= 0; j--)
			{
				tmp = (num2[i]-'0')* (num1[j]-'0') + (res[i + j]-'0');
				res[i + j]  = (tmp % 10)+'0';
				if (i + j - 1 >= 0)
				{
					res[i + j - 1] = ((res[i + j - 1]-'0')+(tmp/10))+'0';
				}
				else if ((i + j - 1 < 0) && (tmp / 10>0))
				{
					res.insert(0, to_string(tmp / 10));
					ssize++;
				}
			}
		}
		res.erase(res.begin()+ssize,res.end());
		return res;
	}
};



int main10()
{
	string num1("12345");
	string num2("0");
	Solution a;
	cout<<a.multiply(num1, num2)<<endl;
	system("pause");
	return 0;
}