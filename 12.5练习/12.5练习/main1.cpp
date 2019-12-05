#include<iostream>//青蛙跳台阶
using namespace std;
//F(0) 一次性跳上去令其 == 1
//F(1) 一个台阶：1
//F(2) 两个台阶：1，1 / 2
//F(3) 三个台阶：1，2 / 1，1，1 / 2，1 / 3
//F(4) 四个台阶：1，3 / 1，1，2 / 2，2 / 1，2 ，1 / 1，1 ，1，1 / 2，1，1 / 3，1 / 4
//………………
//转移方程： F(I) = F(I - 1) + F(I - 2) + ……… + F(0)
//又因为F(I - 1) = F(I - 2) + …… + F(0)
//则F(I) = F(I - 1) + F(I - 1)
class Solution 
{
public:
	int jumpFloorII(int number)
	{
		int sum = 1;
		if (number <= 0)
		{
			return 0;
		}
		for (int i = 0; i < number; i++)
		{
			sum *= 2;
		}
		 return sum;
	}
};