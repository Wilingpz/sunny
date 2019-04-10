#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main2()
{
	int n;
	scanf("%d", &n);
	for (int i= 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			putchar('*');
		}
		putchar('\n');
    }
	system("pause");
	return 0;

}