#include "BTree.h"
#include "queue.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
BTNode* BinaryTreeCreate(BTDataType* src)//int* pi)//pi用于传下标
{
	static int s_n = 0;//局部可见的全局变量，局部静态变量
	//为了进行下面的递归调用所以用了static来修饰这个变量
	if (src[s_n] == '#')
	{
		s_n++;
		return NULL;
	}
	//申请一个新的结点
	BTNode* cur = (BTNode*)malloc(sizeof(BTNode));
	cur->data = src[s_n];
	s_n++;
	cur->lchild = BinaryTreeCreate(src);//递归调用
	cur->rchild = BinaryTreeCreate(src);
	return cur;
}
void BinaryTreeDestory(BTNode* root)//销毁
{
	if (root)
	{
		BinaryTreeDestory(root->lchild);
		BinaryTreeDestory(root->rchild);
		free(root);
	}
}
int BinaryTreeSize(BTNode* root)//求二叉树的所有结点数
{
	static int size = 0;
	if (root)
	{
		size++;
		BinaryTreeSize(root->lchild);//递归
		BinaryTreeSize(root->rchild);
	}
	return size;
}
int BinaryTreeLeafSize(BTNode* root)//统计叶子结点的个数
{
	if (root == NULL)//根节点为空时
	{
		return 0;
	}
	else if (root->lchild == NULL && root->rchild == NULL)//根节点为叶子结点时
	{
		return 1;
	}
	else
		return BinaryTreeLeafSize(root->lchild) + BinaryTreeLeafSize(root->rchild);
}
int BinaryTreeLevelKSize(BTNode* root, int k)//求第k层有多少个结点
{

}
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
void BinaryTreePrevOrder(BTNode* root)//先序遍历
{
	if (root)
	{
	putchar(root->data);
	BinaryTreePrevOrder(root->lchild);//递归
	BinaryTreePrevOrder(root->rchild);
	}
}
void BinaryTreeInOrder(BTNode* root)//中序
{
	if (root)
	{
		BinaryTreeInOrder(root->lchild);
		putchar(root->data);
		BinaryTreeInOrder(root->rchild);
	}
}
void BinaryTreePostOrder(BTNode* root)//后序
{
	if (root)
	{
		BinaryTreeInOrder(root->lchild);
		BinaryTreeInOrder(root->rchild);
		putchar(root->data);
	}
}

// 非递归遍历 
// 层序遍历 
void BinaryTreeLevelOrder(BTNode* root) //非递归的层序遍历
{
	Queue qu;
	BTNode * cur;
	QueueInit(&qu);
    QueuePush(&qu, root);
	while (!QueueIsEmpty(&qu));//队列不为空的时候进入循环
	{
		cur = QueueTop(&qu);//取队顶打印
		putchar(cur->data);
		if (cur->lchild)//如果做孩子存在就入队左孩子
		{
			QueuePush(&qu,cur->lchild);
		}
		if (cur->rchild)//如果右孩子存在就入队右孩子
		{
			QueuePush(&qu, cur->rchild);
		}
		QueuePop(&qu);//根节点出队
	}
	QueueDestory(&qu);
}
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)//判断二叉树是否为完全二叉树
{
	Queue qu;
	BTNode * cur;
	QueueInit(&qu);
	QueuePush(&qu, root);
	int tag = 0;
	while (!QueueIsEmpty(&qu));
	{
		cur = QueueTop(&qu);
		putchar(cur->data);
		if (cur->rchild && !cur->lchild)
		{
			return 0;
		}
		if (tag && (cur->lchild || cur->rchild))//tag置位情况下为叶子结点，直接return0
		{
			return 0;
		}
		if (cur->lchild)
		{
			QueuePush(&qu, cur->lchild);
		}
		if (cur->rchild)
		{
			QueuePush(&qu, cur->rchild);
		}
		else
		{
			tag = 1;
		}
		QueuePop(&qu);
	}
	QueueDestory(&qu);
	return 1;
}
void BinaryTreePrevOrderNonR(BTNode* root)//非递归的先序遍历
{
	Stack st;
	BTNode * cur = root;
	StackInit(&st, 100);
	while (cur)
	{
		putchar(cur->data);//cur不为空的时候打印data
		if (cur->rchild)
		{
			StackPush(&st, cur->rchild);//右孩子存在则右孩子入队
		}
		if (cur->lchild)
		{
			cur = cur->lchild;//访问左孩子
		}
		else
		{
			cur = StackTop(&st);//取出栈顶元素
			StackPop(&st);//栈顶元素出栈，但是这里的cur=栈顶元素
		} 
	}
	StackDestory(&st);
}
void BinaryTreeInOrderNonR(BTNode* root)//非递归的中序遍历
{
	Stack st;
	BTNode * cur = root;
	StackInit(&st, 100);
	//1、从当前结点开始遍历左子树，将所有的结点入栈，直到左子树变为空
	//2、取出并打印栈顶，访问他的右孩子，如果有右孩子，重复1过程，如果没有
	//右孩子，重复2过程
	while (1)
	{
		for (; cur; cur = cur->lchild)
		{
			StackPush(&st, cur);//如果其左孩子存在，则入栈
		}
		cur = StackTop(&st);//没有左孩子则取栈顶
		if (!cur)//如果cur为空则跳出
		{
			break;
		}
		putchar(cur->data);//打印栈顶元素
		StackPop(&st);//栈顶元素出栈,这里的cur仍然是已出队的cur
		cur = cur->rchild;
	}
	StackDestory(&st);
}
void BinaryTreePostOrderNonR(BTNode* root)//非递归的后序遍历
//1、从当前结点开始遍历左子树，将所有的结点入栈，且清空LT标志，直到左子树变为空；
//LT：左子树访问标记
//2、取出栈顶，置位他的LT标记，访问他的右子树，如果右子树存在，重复一过程，如果右子树不存在
//进入三过程
//3、取出栈顶，打印，然后检测他的父节点的LT是否被置位，如果是，则一并打印，直到找到第一个
//LT标记为清空状态的节点位置，然后回到过程2 
{
	char tag[64];
	Stack st;
	BTNode * cur = root;
	StackInit(&st, 100);
	do
	{
		for (; cur; cur = cur->lchild)//将当前结点及左孩子们入栈
		{
			StackPush(&st, cur);//如果其左孩子存在，则入栈
			tag[st.size - 1] = 0;//重置左子树的访问标记
		}
		while (!StackIsEmpty(&st) && tag[st.size - 1])//只在循环跳出的时候生效
		{
			cur = StackTop(&st);
			putchar(cur->data);
			StackPop(&st);//pop里面包含着size--  
		}
		if (!StackIsEmpty(&st))//前面的条件条件只在最后一次循环跳出的时候生效
			//后面的条件分为两个情况：
			//1、当cur为空时，上面的for不进，此条件不成立
			//2、当cur不为空时，前面的for循环进，则此条件不成立
			//
		{
			cur = StackTop(&st);
			//如果上面的while进了，那么证明左子树访问完毕，给LT置位
			//如果while没进，那么证明左子树不存在，给LT置位
			tag[st.size - 1] = 1;
			cur = cur->rchild;
		}
	} while (!StackIsEmpty(&st));//由于后序遍历根节点时最后出栈的，
		StackDestory(&st);
}
void TestBinaryTree();