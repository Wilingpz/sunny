#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main6()
{
	int i,j;
	int count = 0;//一共要取出来八位，用count 进行计数
	int sum = 0;
	int temp[10] = { 0 };
	for (i = 0; i < 100000000; i++)
	{
		for (j = i; j; j /= 10)//把每一位都存在数组里面
		{
			temp[count] = j % 10;
			count++;
		}
		for (j = 1; j <= count; j++)//验证是否为水仙花数
		{
			sum += pow(temp[j - 1], count);//pow(a,b)是求a的b次方的函数，包含于math.h头文件里
		}
		if (sum == i)
		{
			printf("%d\n", i);
		}
		count = sum = 0;//每次运算完成都要进行清0，为下一次运算做准备
	}

	system("pause");
	return 0;
}
