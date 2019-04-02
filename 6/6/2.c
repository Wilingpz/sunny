#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int a = 0;
	int b = 0;
	printf("请输入两个数字：");
	scanf("%d %d", &a, &b);
	swap(&a, &b);
	printf("a = %d  b = %d", a, b);
	system("pause");
}


