#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "BTree.h"

typedef BTNode * QuDataType;//���������Ҫ���ݸ��ڵ��ҵ������Һ��ӽ��
//����Ӧ������Ϊ�������

typedef struct QueueNode//���н��Ľṹ
{
	QuDataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue 
{//ͷָ���βָ��
	QueueNode * _head;
	QueueNode * _rear;
}Queue;

void QueueInit(Queue* plist);//��ʼ��
void QueueDestory(Queue* plist);//����

void QueuePop(Queue* plist);//ɾ��
void QueuePush(Queue* plist, QuDataType x);//����
QuDataType QueueTop(Queue* plist);//����Ԫ��

int QueueIsEmpty(Queue* plist);//�пպ���

#endif //_QUEUE_H_