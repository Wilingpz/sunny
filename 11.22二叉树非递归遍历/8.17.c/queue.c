#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
void QueueInit(Queue* plist)
{
	assert(plist);
	plist->_head = NULL;
	plist->_rear = NULL;
}
void QueuePush(Queue* plist, QuDataType x)
{
	QueueNode * cur = (QueueNode *)malloc(sizeof(QueueNode));//������һ������С�Ŀռ�
	cur->_data = x;
	cur->_next = NULL;
	if (QueueIsEmpty(plist))
	{
		plist->_head = plist->_rear = cur;
		return;
	}
	plist->_rear->_next = cur;
	plist->_rear = cur;
}
int QueueIsEmpty(Queue* plist)
{
	return plist->_head == NULL;

}
void QueuePop(Queue* plist)//ͷɾ���������ͷ�ǿյ���û�б�Ҫ����ͷɾ����
{
	assert(plist);//��������Ϊ��
	QueueNode * tmp;
	if (plist->_head)//���ͷ���ǿղż����������еĲ���
	{
		tmp = plist->_head;//��һ����㽫��ͷ�洢����
		plist->_head = plist->_head->_next;//��������һ���������Ҳ�����ͷ
		free(tmp);
	}
}
//��������ͷ�
void QueueDestory(Queue* plist)
{
	QueueNode * tmp;//���Ͻ���ͷɾ����
	while (plist->_head)//ͷΪ��ʱ����ѭ��
	{
		tmp = plist->_head;//��һ����㽫��ͷ�洢����
		plist->_head = plist->_head->_next;//��������һ���������Ҳ�����ͷ
		free(tmp);
	}
}
QuDataType QueueTop(Queue*plist)
{
	if (QueueIsEmpty(plist))
	{
		return(QuDataType)0;
	}
	return plist->_head->_data;
}