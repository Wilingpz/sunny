//给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，
//使得 num1 成为一个有序数组。
//
//说明 :
//
//初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
//你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
//示例 :
//
//输入 :
//	nums1 = [1, 2, 3, 0, 0, 0], m = 3
//	nums2 = [2, 5, 6], n = 3
//
//输出 : [1, 2, 2, 3, 5, 6]
//
//	 来源：力扣（LeetCode）
// 链接：https ://leetcode-cn.com/problems/merge-sorted-array
//   著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
	{
		vector<int> nums11(nums1.begin(), nums1.begin() + m);
		vector<int> nums22(nums2.begin(), nums2.begin() + n);//为了把多余的0去掉
		vector<int> nums_temp(nums1.begin(), nums1.begin() + m);
		nums_temp.insert(nums_temp.end(), nums2.begin(), nums2.begin() + n);
	    sort(nums_temp.begin(), nums_temp.end());//利用sort函数对其进行排序
		nums1.clear();
		nums1.insert(nums1.begin(), nums_temp.begin(), nums_temp.end());
		//将该数组重新放回nums1中
	}
};

