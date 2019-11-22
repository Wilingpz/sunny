#include "BTree.h"
#include "queue.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
BTNode* BinaryTreeCreate(BTDataType* src)//int* pi)//pi���ڴ��±�
{
	static int s_n = 0;//�ֲ��ɼ���ȫ�ֱ������ֲ���̬����
	//Ϊ�˽�������ĵݹ������������static�������������
	if (src[s_n] == '#')
	{
		s_n++;
		return NULL;
	}
	//����һ���µĽ��
	BTNode* cur = (BTNode*)malloc(sizeof(BTNode));
	cur->data = src[s_n];
	s_n++;
	cur->lchild = BinaryTreeCreate(src);//�ݹ����
	cur->rchild = BinaryTreeCreate(src);
	return cur;
}
void BinaryTreeDestory(BTNode* root)//����
{
	if (root)
	{
		BinaryTreeDestory(root->lchild);
		BinaryTreeDestory(root->rchild);
		free(root);
	}
}
int BinaryTreeSize(BTNode* root)//������������н����
{
	static int size = 0;
	if (root)
	{
		size++;
		BinaryTreeSize(root->lchild);//�ݹ�
		BinaryTreeSize(root->rchild);
	}
	return size;
}
int BinaryTreeLeafSize(BTNode* root)//ͳ��Ҷ�ӽ��ĸ���
{
	if (root == NULL)//���ڵ�Ϊ��ʱ
	{
		return 0;
	}
	else if (root->lchild == NULL && root->rchild == NULL)//���ڵ�ΪҶ�ӽ��ʱ
	{
		return 1;
	}
	else
		return BinaryTreeLeafSize(root->lchild) + BinaryTreeLeafSize(root->rchild);
}
int BinaryTreeLevelKSize(BTNode* root, int k)//���k���ж��ٸ����
{

}
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
void BinaryTreePrevOrder(BTNode* root)//�������
{
	if (root)
	{
	putchar(root->data);
	BinaryTreePrevOrder(root->lchild);//�ݹ�
	BinaryTreePrevOrder(root->rchild);
	}
}
void BinaryTreeInOrder(BTNode* root)//����
{
	if (root)
	{
		BinaryTreeInOrder(root->lchild);
		putchar(root->data);
		BinaryTreeInOrder(root->rchild);
	}
}
void BinaryTreePostOrder(BTNode* root)//����
{
	if (root)
	{
		BinaryTreeInOrder(root->lchild);
		BinaryTreeInOrder(root->rchild);
		putchar(root->data);
	}
}

// �ǵݹ���� 
// ������� 
void BinaryTreeLevelOrder(BTNode* root) //�ǵݹ�Ĳ������
{
	Queue qu;
	BTNode * cur;
	QueueInit(&qu);
    QueuePush(&qu, root);
	while (!QueueIsEmpty(&qu));//���в�Ϊ�յ�ʱ�����ѭ��
	{
		cur = QueueTop(&qu);//ȡ�Ӷ���ӡ
		putchar(cur->data);
		if (cur->lchild)//��������Ӵ��ھ��������
		{
			QueuePush(&qu,cur->lchild);
		}
		if (cur->rchild)//����Һ��Ӵ��ھ�����Һ���
		{
			QueuePush(&qu, cur->rchild);
		}
		QueuePop(&qu);//���ڵ����
	}
	QueueDestory(&qu);
}
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)//�ж϶������Ƿ�Ϊ��ȫ������
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
		if (tag && (cur->lchild || cur->rchild))//tag��λ�����ΪҶ�ӽ�㣬ֱ��return0
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
void BinaryTreePrevOrderNonR(BTNode* root)//�ǵݹ���������
{
	Stack st;
	BTNode * cur = root;
	StackInit(&st, 100);
	while (cur)
	{
		putchar(cur->data);//cur��Ϊ�յ�ʱ���ӡdata
		if (cur->rchild)
		{
			StackPush(&st, cur->rchild);//�Һ��Ӵ������Һ������
		}
		if (cur->lchild)
		{
			cur = cur->lchild;//��������
		}
		else
		{
			cur = StackTop(&st);//ȡ��ջ��Ԫ��
			StackPop(&st);//ջ��Ԫ�س�ջ�����������cur=ջ��Ԫ��
		} 
	}
	StackDestory(&st);
}
void BinaryTreeInOrderNonR(BTNode* root)//�ǵݹ���������
{
	Stack st;
	BTNode * cur = root;
	StackInit(&st, 100);
	//1���ӵ�ǰ��㿪ʼ�����������������еĽ����ջ��ֱ����������Ϊ��
	//2��ȡ������ӡջ�������������Һ��ӣ�������Һ��ӣ��ظ�1���̣����û��
	//�Һ��ӣ��ظ�2����
	while (1)
	{
		for (; cur; cur = cur->lchild)
		{
			StackPush(&st, cur);//��������Ӵ��ڣ�����ջ
		}
		cur = StackTop(&st);//û��������ȡջ��
		if (!cur)//���curΪ��������
		{
			break;
		}
		putchar(cur->data);//��ӡջ��Ԫ��
		StackPop(&st);//ջ��Ԫ�س�ջ,�����cur��Ȼ���ѳ��ӵ�cur
		cur = cur->rchild;
	}
	StackDestory(&st);
}
void BinaryTreePostOrderNonR(BTNode* root)//�ǵݹ�ĺ������
//1���ӵ�ǰ��㿪ʼ�����������������еĽ����ջ�������LT��־��ֱ����������Ϊ�գ�
//LT�����������ʱ��
//2��ȡ��ջ������λ����LT��ǣ�����������������������������ڣ��ظ�һ���̣����������������
//����������
//3��ȡ��ջ������ӡ��Ȼ�������ĸ��ڵ��LT�Ƿ���λ������ǣ���һ����ӡ��ֱ���ҵ���һ��
//LT���Ϊ���״̬�Ľڵ�λ�ã�Ȼ��ص�����2 
{
	char tag[64];
	Stack st;
	BTNode * cur = root;
	StackInit(&st, 100);
	do
	{
		for (; cur; cur = cur->lchild)//����ǰ��㼰��������ջ
		{
			StackPush(&st, cur);//��������Ӵ��ڣ�����ջ
			tag[st.size - 1] = 0;//�����������ķ��ʱ��
		}
		while (!StackIsEmpty(&st) && tag[st.size - 1])//ֻ��ѭ��������ʱ����Ч
		{
			cur = StackTop(&st);
			putchar(cur->data);
			StackPop(&st);//pop���������size--  
		}
		if (!StackIsEmpty(&st))//ǰ�����������ֻ�����һ��ѭ��������ʱ����Ч
			//�����������Ϊ���������
			//1����curΪ��ʱ�������for������������������
			//2����cur��Ϊ��ʱ��ǰ���forѭ�������������������
			//
		{
			cur = StackTop(&st);
			//��������while���ˣ���ô֤��������������ϣ���LT��λ
			//���whileû������ô֤�������������ڣ���LT��λ
			tag[st.size - 1] = 1;
			cur = cur->rchild;
		}
	} while (!StackIsEmpty(&st));//���ں���������ڵ�ʱ����ջ�ģ�
		StackDestory(&st);
}
void TestBinaryTree();