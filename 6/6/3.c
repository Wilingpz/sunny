#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int is_leap(int year)
{
	if (year % 4 == 0 || year % 100 == 0 && year % 400 == 0)
		printf("������\n");
	else
		printf("��������\n");
}
int main3()
{
	int year = 0;
	printf("��������Ҫ��ѯ����ݣ�");
	scanf("%d", &year);
	is_leap(year);
	system("pause");
}