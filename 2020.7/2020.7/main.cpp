//����һ�����ǵݼ�˳��������������� A������ÿ�����ֵ�ƽ����ɵ������飬
//Ҫ��Ҳ���ǵݼ�˳������
//
//
//
//ʾ�� 1��
//
//���룺[-4, -1, 0, 3, 10]
//�����[0, 1, 9, 16, 100]
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/squares-of-a-sorted-array
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
public:
	vector<int> sortedSquares(vector<int>& A) 
	{
		vector<int>result;
		for (int i = 0; i < A.size();i++)
		{
		  A[i]*=A[i];
		}
		sort(A.begin(), A.end());
		return A;
	}
};