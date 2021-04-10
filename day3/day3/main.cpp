#include<iostream>
#include<vector>
using namespace std;

//��̬������̨��
/*
��������Ѿ�������i��̨�ף���ôǰһ��
��1������һ�׾�����i��    �򵽴�ý׵ķ������� f(n-1)��
��2���������׾�����i��    �򵽴�ý׵ķ�������f(n-2)��
	...	
��3�����һ��������ȥi�ף�����0�׾�����i��     �򵽴�ý׵ķ�������f(0)=1
�� f(n)=f(n-1)+f(n-2)+f(n-3)+....+f(0)
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
		vector<int>tmp(number+1,0);//��ʼ��
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