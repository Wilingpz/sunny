//�����������飬��дһ���������������ǵĽ�����
//
//ʾ�� 1:
//
//���� : nums1 = [1, 2, 2, 1], nums2 = [2, 2]
//��� : [2]
#include<iostream>
#include<set>
#include<vector>
using namespace std;

class Solution 
{
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
	{
		vector<int>res;
		set<int>s1(nums1.begin(), nums1.end());
		for (auto &i : nums2)
		{
			if (s1.erase(i))
			{
				res.push_back(i);
			}
		}
		return res;
	}
};