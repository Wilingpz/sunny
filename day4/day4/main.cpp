#include<iostream>
#include<vector>
#include<map>
using namespace std;


class Solution 
{
public:
	/**
	* 升序排列
	* @param nums int整型一维数组
	* @param numsLen int nums数组长度
	* @return int整型vector
	*/
	vector<int> ascSort(int* nums, int numsLen) 
	{
		vector<int>res;
		map<int,int>m;
		for (int i = 0; i < numsLen; i++)
		{
			m[nums[i]]++;
		}
		for (auto &i : m)
		{
			res.push_back(i.first);
		}
		for (auto &j : res)
		{
			cout << j << endl;
		}

		return res;
	}
};

int main1()
{
	Solution a;
	int nums[] = { 5, 2, 3, 1 };
	a.ascSort(nums, 4);
	system("pause");
	return 0;
}