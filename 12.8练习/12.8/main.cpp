#include<iostream>//写一个函数求两整数之和，不可以用任何算数运算符
using namespace std;

class Solution 
{
public:
	int Add(int num1, int num2)
	{
		int sum1 = 0;
		int sum2 = 0;
		/*
		while (num2!=0)
		{
			sum1 = num1^ num2;//不加进位的相加结果
			sum2 = (num1&num2) << 1;//进位的结果
			num1 = sum1;
			num2 = sum2;
		}
		return num1;
		*/

		sum1 = num1^ num2;
		sum2=(num1&num2) << 1;
		if (sum2 == 0)
		{
			return sum1;
		}
		while (num2 != 0)
		{
			num1 = sum1;
			num2 = sum2;
			sum1 = num1^ num2;
			sum2 = (num1&num2) << 1;
		}
		return num1;
	}
};
