#include<iostream>
#include<vector>
using namespace std;


class Solution 
{
public:
	/**
	*  ����λ�϶�����������ż��λ�϶���ż��
	*  ���룺����arr�����ȴ���2
	*  len��arr�ĳ���
	*  ��arr����������λ�϶�����������ż��λ�϶���ż��
	*/
	//���Ч��
	void oddInOddEvenInEven(vector<int>& arr, int len)
	{
		long i = 0, j = 1;
		while (i < len && j < len)
		{
			if ((arr[i] % 2) == 0)//ż��λ�ϵ�����ż��
			{
				i += 2;//�Լ�2����һ��
				continue;
			}
			if ((arr[i] % 2)!=0)//����λ�ϵ�������
			{
				i += 2;//�Լ�2����һ��
				continue;
			}
			swap(arr[i], arr[j]);
		}
	}
};
int main1()
{
	vector<int>arr = { 1, 2, 3, 4 };
	Solution a;
	a.oddInOddEvenInEven(arr,arr.size());
	for (auto &i : arr)
	{
		cout << i << endl;
	}
	system("pause");
	return 0;
}