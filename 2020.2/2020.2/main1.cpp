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
// ���ӣ�https ://leetcode-cn.com/problems/search-insert-position
//	 ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
//
#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
	int searchInsert(vector<int>& nums, int target) 
	{
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == target)
			{
				return i;
			}
			else if (nums[i]<target && nums[i+1]>target)
			{
				return i + 1;
			}
		}
	}
};