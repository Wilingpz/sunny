//编程实现：
//一个数组中只有两个数字是出现一次，
//
//其他所有数字都出现了两次。
//
//找出这两个只出现一次的数字，编程实现。
#include <stdio.h>
void findnum(int * src, int n, int* pnuml, int* pmun2)
{
	int i;
	int sum = 0;
	for (i = 0; i < n; i++)
	{
		sum ^= src[i];//一个数连续异或两次不变，故可得只出现一次的这两个数的异或结果
	}
	int pos;//想通过pos找到只出现了一次的两数异或为1的位置
	int num1 = 0, num2 = 0;
	for (pos = 0; !(sum & 1 << pos); pos++);//1左移pos位和sum进行与操作
	for (i = 0; i < n; i++)
	{
		if (src[i] & 1 << pos)//根据将数组元素分组，此时所找的两个数并不在同一组
		{
			num1 ^= src[i];//组内异或找只出现了一次的数
		}
		else
		{
			num2 ^= src[i];
		}
	}
	*pnuml = num1;
	*pmun2 = num2;//反赋值回去
}
int main()
{
	int arr[] = { 5, 3, 9, 1, 7, 5, 4, 7, 4, 2, 9, 2 };
	int num1, num2;
	findnum(arr, sizeof(arr) / sizeof(arr[0]), &num1, &num2)
		return 0;
}
