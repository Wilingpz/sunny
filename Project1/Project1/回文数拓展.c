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
	for (i = n; i; i /= sn)//ѭ������Ϊi��i������0��ʱ��һֱ�����ù���
	{
		tmp = i % sn;
		sum = sum * sn + tmp;//�������
	}
	if (n == sum)
	{
		printf("%d��%d�������ǻ�����\n", n, sn);
	}
	else
	{
		printf("%d��%d�����²��ǻ�����\n", n, sn);
	}
	system("pause");
	return 0;
}