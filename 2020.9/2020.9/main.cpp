//给定一个非空数组，返回此数组中第三大的数。如果不存在，
//则返回数组中最大的数。要求算法时间复杂度必须是O(n)。
//
//示例 1:
//
//输入 : [3, 2, 1]
//
//输出 : 1
//
// 解释 : 第三大的数是 1.
//
//	  来源：力扣（LeetCode）
//  链接：https ://leetcode-cn.com/problems/third-maximum-number
//	 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution 
{
public:
	int thirdMax(vector<int>& nums) 
	{
		map<int, int>tmp;
		for (auto &i : nums)
		{
			tmp[i]++;
		}
		nums.clear();
		for (auto &i : tmp)
		{
			nums.push_back(i.first);
		}
		if (nums.size() == 2)
		{
			return nums[1];
		}
		else if (nums.size() == 1)
		{
			return nums[0];
		}
		else 
		{
			return nums[nums.size()-3];
		}
	}
};


#include <algorithm>
class Solution 
{
public:
	int thirdMax(vector<int>& nums) 
	{  
		sort(nums.begin(), nums.end());//对nums进行排序(从小到大)
		vector<int> newNums(1);//初始化newNums
		newNums[0] = nums[0];//将nums[0]赋给newNums[0]
		for (int i = 1; i < nums.size(); i++)//遍历nums
		if ((newNums.back()) != nums[i])//若nums的最后一个数不等于nums[i]为了去重
			newNums.push_back(nums[i]);//尾插

		if (newNums.size() == 2) return newNums[1];
		else if (newNums.size() == 1) return newNums[0];
		else return newNums[newNums.size() - 3];
	}
};

