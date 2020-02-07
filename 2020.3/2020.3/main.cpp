//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
//如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//
//你可以假设数组中无重复元素。
//
//示例 1:
//
//输入 : [1, 3, 5, 6], 5
//输出 : 2
//
//	 来源：力扣（LeetCode）


#include<iostream>
#include<vector>
using namespace std;
#if 0
class Solution 
{
public:
	int searchInsert(vector<int>& nums, int target) 
	{
		 if (target < nums[0])
		{
			int j = 0;
			return j;
		}
		 if (target > nums[nums.size() - 1])
		{
			return nums.size() - 1;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == target)
			{
				return i;
			}
			else if (target<nums[i] && target>nums[i + 1])
			{
				return i+1;
			}
		}
		return 0;
	}
};
#else
class Solution
{
public:
	int searchInsert(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1;
		while (left<=right)
		{
			int mid = (left + right) / 2;//二分法
			if (target == nums[mid])
			{
				return mid;
			}
			else if (nums[mid]<target)
			{
				 left=mid+1;//注意边界
			}
			else 
			{
				 right=mid-1;//注意边界
			}
		}
		return left;
	}
};
#endif
