﻿//给定一个非负整数数组 A，返回一个数组，在该数组中， 
//A 的所有偶数元素之后跟着所有奇数元素。
//
//你可以返回满足此条件的任何数组作为答案。
//
//
//
//示例：
//
//输入：[3, 1, 2, 4]
//输出：[2, 4, 3, 1]
//输出[4, 2, 3, 1]，[2, 4, 1, 3] 和[4, 2, 1, 3] 也会被接受。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/sort-array-by-parity
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include<iostream>
#include<vector>
using namespace std;


class Solution 
{
public:
	vector<int> sortArrayByParity(vector<int>& A) 
	{
		int left= 0;
		int right = A.size()-1;
		while (left < right)
		{
			if ((A[left] % 2 != 0) && (A[right] % 2 == 0))
			{
				swap(A[left], A[right]);
				left++;
				right--;
			}
			if ((A[left] % 2 == 0) && (A[right] % 2 == 0))
			{
				left++;
			}
			if ((A[left] % 2 == 0) && (A[right] % 2 != 0))
			{
				left++;
				right--;
			}
			if ((A[left] % 2 != 0) && (A[right] % 2 != 0))
			{
				right--;
			}
		}
		return A;
	}
};