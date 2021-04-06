#include<iostream>
#include<vector>
using namespace std;
//�ؽ�������
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;

	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution 
{
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) 
	{
		//�ų��쳣���
		int vinlen = vin.size();
		if (vinlen == 0)
		{
			return NULL;
		}
		//�����µ�ͷ���
		vector<int>pre_left, pre_right, vin_left, vin_right;
		TreeNode* head = new TreeNode(pre[0]);
		//���������Ҹ��ڵ�
		int tmp = 0;
		for (int i = 0; i < vinlen; i++)
		{
			if (vin[i] == pre[0])
			{
				tmp = i;
				break;
			}
		}
		//�ֱ�������������ڶ�Ӧλ�ã����еݹ�
		for (int j = 0; j < tmp; j++)
		{
			vin_left.push_back(vin[j]);
			pre_left.push_back(pre[j+1]);
		}
		for (int k = tmp + 1; k < vinlen;k++)
		{
			vin_right.push_back(vin[k]);
			pre_right.push_back(pre[k]);
		}
		//�ݹ�ֱ�õ���������������
		head->left = reConstructBinaryTree(pre_left, vin_left);
		head->right = reConstructBinaryTree(pre_right, vin_right);

		return head;
	}
};