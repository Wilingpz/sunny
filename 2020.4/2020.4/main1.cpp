//�ж�һ�������Ƿ��ǻ���������������ָ���򣨴������ң��͵��򣨴�������
//������һ����������
//
//ʾ�� 1:
//
//���� : 121
//��� : true
#include<iostream>
using namespace std;

class Solution 
{
public:
	bool isPalindrome(int x) //����Ǹ�����һ�����ǻ�����
	{
		if (x < 0 || (x%10==0 && x!=0))//������һλΪ0���һλ����Ϊ0����ֻ��0
		{
			return false;
		}
		int temp = 0;//��ת��������
		while (x>temp)
		{
			temp = (temp * 10) + (x % 10);//�������ֵĴ�С
			x /= 10;
		}
		if (x == temp || x == temp / 10)//���x��ż�������η�ת��temp�Ƿ����
			//xǰ��Σ���x���������򿴺��η�ת��temp/10�Ƿ����xǰ���
		{
			return true;
		}
		return false;
	}
};



