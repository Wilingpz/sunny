//���ʵ�֣�
//һ��������ֻ�����������ǳ���һ�Σ�
//
//�����������ֶ����������Ρ�
//
//�ҳ�������ֻ����һ�ε����֣����ʵ�֡�
#include <stdio.h>
void findnum(int * src, int n, int* pnuml, int* pmun2)
{
	int i;
	int sum = 0;
	for (i = 0; i < n; i++)
	{
		sum ^= src[i];//һ��������������β��䣬�ʿɵ�ֻ����һ�ε����������������
	}
	int pos;//��ͨ��pos�ҵ�ֻ������һ�ε��������Ϊ1��λ��
	int num1 = 0, num2 = 0;
	for (pos = 0; !(sum & 1 << pos); pos++);//1����posλ��sum���������
	for (i = 0; i < n; i++)
	{
		if (src[i] & 1 << pos)//���ݽ�����Ԫ�ط��飬��ʱ���ҵ�������������ͬһ��
		{
			num1 ^= src[i];//���������ֻ������һ�ε���
		}
		else
		{
			num2 ^= src[i];
		}
	}
	*pnuml = num1;
	*pmun2 = num2;//����ֵ��ȥ
}
int main()
{
	int arr[] = { 5, 3, 9, 1, 7, 5, 4, 7, 4, 2, 9, 2 };
	int num1, num2;
	findnum(arr, sizeof(arr) / sizeof(arr[0]), &num1, &num2)
		return 0;
}
