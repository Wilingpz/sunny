#include<iostream>
#include<vector>
using namespace std;
//二维数组中的查找

/*
class Solution
{
public:
	bool Find(int target, vector<vector<int> > array)
	{
		//暴力搜索
		for (auto &i : array)
		{
			for (auto &j : i)
			{
				if (j == target)
				{
					return true;
				}
			}
		}
		return false;
	}
};
*/


//二分查找法
class Solution
{
public:
bool Find(int target, vector<vector<int> > array)
{
	int r = 0;
	int l = array[0].size()-1;

	
	while (r<array.size() && l>=0)
	{
		if (target == array[r][l])
		{
			return true;
		}
		else if (target > array[r][l])
		{
			++r;
		}
		else
		{
			--l;
		} 
	}
	return false;
 }
};

int main1()
{
	int t = 7;
	vector<vector<int>>array = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 3 }, { 6, 8, 11, 15 } };
	Solution k;
	cout << k.Find(t, array) << endl;
	system("pause");
	return 0;
}


