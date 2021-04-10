#include<iostream>
#include<vector>
using namespace std;

//变态青蛙跳台阶
/*
如果现在已经跳上了i阶台阶，那么前一步
（1）还差一阶就跳上i阶    则到达该阶的方法共有 f(n-1)种
（2）还差两阶就跳上i阶    则到达该阶的方法共有f(n-2)种
	...	
（3）如果一步就跳上去i阶，还差0阶就跳上i阶     则到达该阶的方法共有f(0)=1
则 f(n)=f(n-1)+f(n-2)+f(n-3)+....+f(0)
f(0)=1
f(1)=f(0)=1
f(2)=f(0)+f(1)=2

*/

#if 0
class Solution 
{
public:
	int jumpFloorII(int number)
	{
		if (number == 0 || number == 1)
		{
			return 1;
		}
		vector<int>tmp(number+1,0);//初始化
		tmp[0] = tmp[1] = 1;

		for (int i = 2;i<=number; i++)
		{
			for (int j = 0; j < i; j++)
			{
				tmp[i] += tmp[j];
			}
		}
		return tmp[number];
	}
};
#else
class Solution
{
public:
int jumpFloorII(int number)
{
	if (number==0||number==1)
	{
		return 1;
	}
	vector<int>f(number + 1, 0);
	f[0] = f[1] = 1;
	for (int i = 2; i <= number; i++)
	{
		f[i] = 2 * f[i - 1];
	}
	return f[number];
}
};
#endif

int main1()
{
	Solution a;
	int b = 3;
	cout << a.jumpFloorII(b) << endl;
	system("pause");
	return 0;
}