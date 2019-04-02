#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <windows.h>
#include <stdlib.h>
void print(int n)
{
	for (int x = 1; x <= n; x++)
	{
		for (int y = 1; y <= x; y++)
		{
			int z = 0;
			z = x*y;
			printf("%d*%d=%2d ", y, x, z);
		}
		printf("\n");
	}
	return;
}

int main1()
{
	int n = 0;
	printf("ÇëÊäÈëÐÐÊý£º");
	scanf("%d", &n);
	print(n);
	system("pause");
	return 0;
}
