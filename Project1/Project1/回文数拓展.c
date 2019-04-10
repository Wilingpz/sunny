#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main7()
{
	int n;
	int sn;
	int i;
	int tmp , sum = 0;
	scanf("%d%d", &n,&sn);
	for (i = n; i; i /= sn)//循环条件为i即i不等于0的时候一直继续该过程
	{
		tmp = i % sn;
		sum = sum * sn + tmp;//逆序相加
	}
	if (n == sum)
	{
		printf("%d在%d进制下是回文数\n", n, sn);
	}
	else
	{
		printf("%d在%d进制下不是回文数\n", n, sn);
	}
	system("pause");
	return 0;
}