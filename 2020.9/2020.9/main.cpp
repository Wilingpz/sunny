//����һ���ǿ����飬���ش������е������������������ڣ�
//�򷵻���������������Ҫ���㷨ʱ�临�Ӷȱ�����O(n)��
//
//ʾ�� 1:
//
//���� : [3, 2, 1]
//
//��� : 1
//
// ���� : ����������� 1.
//
//	  ��Դ�����ۣ�LeetCode��
//  ���ӣ�https ://leetcode-cn.com/problems/third-maximum-number
//	 ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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
		sort(nums.begin(), nums.end());//��nums��������(��С����)
		vector<int> newNums(1);//��ʼ��newNums
		newNums[0] = nums[0];//��nums[0]����newNums[0]
		for (int i = 1; i < nums.size(); i++)//����nums
		if ((newNums.back()) != nums[i])//��nums�����һ����������nums[i]Ϊ��ȥ��
			newNums.push_back(nums[i]);//β��

		if (newNums.size() == 2) return newNums[1];
		else if (newNums.size() == 1) return newNums[0];
		else return newNums[newNums.size() - 3];
	}
};

