#include<iostream>
#include<vector>
#include<map>
using namespace std;


class Solution 
{
public:
	/**
	* ��������
	* @param nums int����һά����
	* @param numsLen int nums���鳤��
	* @return int����vector
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