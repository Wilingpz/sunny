#include<iostream>
#include<vector>
using namespace std;
//重建二叉树
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
		//排除异常情况
		int vinlen = vin.size();
		if (vinlen == 0)
		{
			return NULL;
		}
		//申请新的头结点
		vector<int>pre_left, pre_right, vin_left, vin_right;
		TreeNode* head = new TreeNode(pre[0]);
		//在中序里找根节点
		int tmp = 0;
		for (int i = 0; i < vinlen; i++)
		{
			if (vin[i] == pre[0])
			{
				tmp = i;
				break;
			}
		}
		//分别将左右子树存放在对应位置，进行递归
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
		//递归分别得到左子树和右子树
		head->left = reConstructBinaryTree(pre_left, vin_left);
		head->right = reConstructBinaryTree(pre_right, vin_right);

		return head;
	}
};