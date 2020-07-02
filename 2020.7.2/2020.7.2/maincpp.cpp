#include<iostream>
#include<vector>
using namespace std;


class Solution 
{
public:
	/**
	*  奇数位上都是奇数或者偶数位上都是偶数
	*  输入：数组arr，长度大于2
	*  len：arr的长度
	*  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
	*/
	//提高效率
	void oddInOddEvenInEven(vector<int>& arr, int len)
	{
		long i = 0, j = 1;
		while (i < len && j < len)
		{
			if ((arr[i] % 2) == 0)//偶数位上的数是偶数
			{
				i += 2;//自加2到下一个
				continue;
			}
			if ((arr[i] % 2)!=0)//奇数位上的是奇数
			{
				i += 2;//自加2到下一个
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