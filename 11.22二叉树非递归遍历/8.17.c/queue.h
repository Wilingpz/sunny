#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "BTree.h"

typedef BTNode * QuDataType;//层序遍历需要根据根节点找到其左右孩子结点
//所以应该设置为结点类型

typedef struct QueueNode//队列结点的结构
{
	QuDataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue 
{//头指针和尾指针
	QueueNode * _head;
	QueueNode * _rear;
}Queue;

void QueueInit(Queue* plist);//初始化
void QueueDestory(Queue* plist);//销毁

void QueuePop(Queue* plist);//删除
void QueuePush(Queue* plist, QuDataType x);//插入
QuDataType QueueTop(Queue* plist);//队首元素

int QueueIsEmpty(Queue* plist);//判空函数

#endif //_QUEUE_H_