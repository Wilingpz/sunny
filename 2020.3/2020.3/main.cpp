//����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ����������������
//���Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
//
//����Լ������������ظ�Ԫ�ء�
//
//ʾ�� 1:
//
//���� : [1, 3, 5, 6], 5
//��� : 2
//
//	 ��Դ�����ۣ�LeetCode��


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
			int mid = (left + right) / 2;//���ַ�
			if (target == nums[mid])
			{
				return mid;
			}
			else if (nums[mid]<target)
			{
				 left=mid+1;//ע��߽�
			}
			else 
			{
				 right=mid-1;//ע��߽�
			}
		}
		return left;
	}
};
#endif
