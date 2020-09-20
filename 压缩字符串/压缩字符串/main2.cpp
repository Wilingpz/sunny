#include<iostream>
#include<vector>
using namespace std;


class Solution 
{
public:
	/**
	* ����λ��
	* @param array int����vector ��������
	* @param value int���� ��Ҫ���ҵ�ֵ
	* @return int����
	*/
	int FindNumber(vector<int>& array, int value) 
	{
		int left = 0;
		int right = array.size() - 1;
		int mid = (left + right) / 2;
	 while (left <= right)
	 {
		 if (array[mid] == value)
		 {
			 return mid;
		 }
	 	if (array[mid] > value)
	 	{
			if (array[0] < array[array.size() - 1])
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
			
	 	}
	 	else if (array[mid] < value)
	 	{
			if (array[0] < array[array.size() - 1])
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}	
	 	}
		mid = (left + right) / 2;
	 }
	 return -1;
	}
};


int main()
{
	Solution a;
	vector<int>array = { 8,6,5,4,3,2 };
	int value = 5;
	cout << a.FindNumber(array, value) << endl;;
	system("pause");
	return 0;
}