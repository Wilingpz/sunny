#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main6()
{
	int i,j;
	int count = 0;//һ��Ҫȡ������λ����count ���м���
	int sum = 0;
	int temp[10] = { 0 };
	for (i = 0; i < 100000000; i++)
	{
		for (j = i; j; j /= 10)//��ÿһλ��������������
		{
			temp[count] = j % 10;
			count++;
		}
		for (j = 1; j <= count; j++)//��֤�Ƿ�Ϊˮ�ɻ���
		{
			sum += pow(temp[j - 1], count);//pow(a,b)����a��b�η��ĺ�����������math.hͷ�ļ���
		}
		if (sum == i)
		{
			printf("%d\n", i);
		}
		count = sum = 0;//ÿ��������ɶ�Ҫ������0��Ϊ��һ��������׼��
	}

	system("pause");
	return 0;
}
