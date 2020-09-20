#include<iostream>
#include<vector>
using namespace std;


class Solution 
{
public:
	/**
	* 查找位置
	* @param array int整型vector 有序数组
	* @param value int整型 需要查找的值
	* @return int整型
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