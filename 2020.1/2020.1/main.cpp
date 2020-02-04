//题目描述：
//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
//
//示例 1:
//
//输入 : [1, 2, 3, 4, 5, 6, 7] 和 k = 3
//输出 : [5, 6, 7, 1, 2, 3, 4]
// 解释 :
//	向右旋转 1 步 : [7, 1, 2, 3, 4, 5, 6]
//	向右旋转 2 步 : [6, 7, 1, 2, 3, 4, 5]
//	向右旋转 3 步 : [5, 6, 7, 1, 2, 3, 4]
//
//	来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/rotate-array
//	 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
	void rotate(vector<int>& nums, int k) 
	{
		int size = nums.size();
		if (k >= size)
		{
			k%=size;//如果所要右移的位数大于等于nums的长度，
			//需要对k进行变化，因为k=size时相当于没有移动
			//k>size时和k=1，2，3……时情况相同，故k需和size取模
		}
		if (k != 0)
		{
			vector<int>temp(size);
			for (int i = 0; i < size; i++)
			{
				temp[(i + k)%size] = nums[i];
			}
			for (int i = 0; i < size; i++)
			{
				nums[i] = temp[i];
			}
		}
	}
};

