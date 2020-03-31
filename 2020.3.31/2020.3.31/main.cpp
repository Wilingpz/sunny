//斐波那契凤尾
#include<iostream>
#include<cstdio>
using namespace std;

int main1()
{
	int Fib[100001];
	 Fib[0] = 1;
	 Fib[1] = 1;
	 for (int i = 2; i <= 100000; i++)
	 {
		 Fib[i] = Fib[i - 1] + Fib[i - 2];
		 Fib[i] = Fib[i] % 1000000;//当这个数超过六位的时候，留下后六位 
		 //因为超过六位后会只剩下后面六位，并不影响加法
	 }
	int k;
	while (cin >> k)
	{
		if (k < 29)//小于六位的时候
		{
			printf("%d\n", Fib[k]);
		}
		else
		{//大于六位的时候
			printf("%06d\n", Fib[k]);//%06d表示按照六位输出，不满六位的用0补齐
		}
	}
	return 0;
}