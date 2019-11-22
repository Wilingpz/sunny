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
	QueueNode * cur = (QueueNode *)malloc(sizeof(QueueNode));//申请了一个结点大小的空间
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
void QueuePop(Queue* plist)//头删操作，如果头是空的则没有必要进行头删操作
{
	assert(plist);//断言它不为空
	QueueNode * tmp;
	if (plist->_head)//如果头不是空才继续进行下列的操作
	{
		tmp = plist->_head;//用一个结点将旧头存储起来
		plist->_head = plist->_head->_next;//仅进行这一步操作会找不到旧头
		free(tmp);
	}
}
//单链表的释放
void QueueDestory(Queue* plist)
{
	QueueNode * tmp;//不断进行头删操作
	while (plist->_head)//头为空时跳出循环
	{
		tmp = plist->_head;//用一个结点将旧头存储起来
		plist->_head = plist->_head->_next;//仅进行这一步操作会找不到旧头
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