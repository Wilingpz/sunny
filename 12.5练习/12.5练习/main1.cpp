#include<iostream>//������̨��
using namespace std;
//F(0) һ��������ȥ���� == 1
//F(1) һ��̨�ף�1
//F(2) ����̨�ף�1��1 / 2
//F(3) ����̨�ף�1��2 / 1��1��1 / 2��1 / 3
//F(4) �ĸ�̨�ף�1��3 / 1��1��2 / 2��2 / 1��2 ��1 / 1��1 ��1��1 / 2��1��1 / 3��1 / 4
//������������
//ת�Ʒ��̣� F(I) = F(I - 1) + F(I - 2) + ������ + F(0)
//����ΪF(I - 1) = F(I - 2) + ���� + F(0)
//��F(I) = F(I - 1) + F(I - 1)
class Solution 
{
public:
	int jumpFloorII(int number)
	{
		int sum = 1;
		if (number <= 0)
		{
			return 0;
		}
		for (int i = 0; i < number; i++)
		{
			sum *= 2;
		}
		 return sum;
	}
};