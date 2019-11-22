#ifndef _BTREE_
#define _BTREE_
#include <stdio.h>
#include <stdlib.h>
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* lchild;
	struct BinaryTreeNode* rchild;
}BTNode;

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树 
BTNode* BinaryTreeCreate(BTDataType* src);//int* pi)//pi用于传下标
void BinaryTreeDestory(BTNode** root);
int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root, int k);
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
void BinaryTreePrevOrder(BTNode* root); 
void BinaryTreeInOrder(BTNode* root); 
void BinaryTreePostOrder(BTNode* root);
 
// 非递归遍历 
// 层序遍历 
void BinaryTreeLevelOrder(BTNode* root); 
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);
void BinaryTreePrevOrderNonR(BTNode* root); //先序遍历
void BinaryTreeInOrderNonR(BTNode* root); //中序遍历
void BinaryTreePostOrderNonR(BTNode* root);//后序遍历
void TestBinaryTree();
#endif 


