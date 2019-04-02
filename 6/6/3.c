#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int is_leap(int year)
{
	if (year % 4 == 0 || year % 100 == 0 && year % 400 == 0)
		printf("是闰年\n");
	else
		printf("不是闰年\n");
}
int main3()
{
	int year = 0;
	printf("请输入您要查询的年份：");
	scanf("%d", &year);
	is_leap(year);
	system("pause");
}