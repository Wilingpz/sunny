//쳲�������β
#include<iostream>
#include<cstdio>
using namespace std;

int main1()
{
	int Fib[100001];
	 Fib[0] = 1;
	 Fib[1] = 1;
	 for (int i = 2; i <= 100000; i++)
	 {
		 Fib[i] = Fib[i - 1] + Fib[i - 2];
		 Fib[i] = Fib[i] % 1000000;//�������������λ��ʱ�����º���λ 
		 //��Ϊ������λ���ֻʣ�º�����λ������Ӱ��ӷ�
	 }
	int k;
	while (cin >> k)
	{
		if (k < 29)//С����λ��ʱ��
		{
			printf("%d\n", Fib[k]);
		}
		else
		{//������λ��ʱ��
			printf("%06d\n", Fib[k]);//%06d��ʾ������λ�����������λ����0����
		}
	}
	return 0;
}