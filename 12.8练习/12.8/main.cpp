#include<iostream>//дһ��������������֮�ͣ����������κ����������
using namespace std;

class Solution 
{
public:
	int Add(int num1, int num2)
	{
		int sum1 = 0;
		int sum2 = 0;
		/*
		while (num2!=0)
		{
			sum1 = num1^ num2;//���ӽ�λ����ӽ��
			sum2 = (num1&num2) << 1;//��λ�Ľ��
			num1 = sum1;
			num2 = sum2;
		}
		return num1;
		*/

		sum1 = num1^ num2;
		sum2=(num1&num2) << 1;
		if (sum2 == 0)
		{
			return sum1;
		}
		while (num2 != 0)
		{
			num1 = sum1;
			num2 = sum2;
			sum1 = num1^ num2;
			sum2 = (num1&num2) << 1;
		}
		return num1;
	}
};
