//����һ���������飬�ж��Ƿ�����ظ�Ԫ�ء�
//
//����κ�ֵ�������г����������Σ��������� true�����������ÿ��Ԫ�ض�����ͬ
//�򷵻� false��
//
//ʾ�� 1:
//
//���� : [1, 2, 3, 1]
//��� : true
//
//	 ��Դ�����ۣ�LeetCode��
// ���ӣ�https ://leetcode-cn.com/problems/contains-duplicate
//	 ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution 
{
public:
	bool containsDuplicate(vector<int>& nums) 
	{
		map<int, int>tmp;
		for (auto &i : nums)
		{
			tmp[i]++;
		}
		for (auto &i : tmp)
		{
			if (i.second >= 2)
			{
				return true;
			}
		}
		return false;
	}
};