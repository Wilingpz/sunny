#include "slist.h"

//单链表
void SListInit(SList* plist)//初始化
{
	assert(plist);
	plist->_head = NULL;
}

void SListDestory(SList* plist)//单链表销毁
{
	SListNode * tmp;
	while (plist->_head)//头结点不为空的情况
	{
		tmp = plist->_head;
		plist->_head = plist->_head->_next;//换头
		free(tmp);//释放头结点
	}
}
//头插
void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);

	SListNode * cur = (SListNode *)malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = plist->_head;//换头操作
	plist->_head = cur;
}
//头删
void SListPopFront(SList* plist)
{
	assert(plist);

	SListNode * tmp;
	if (plist->_head)
	{
		tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}
//打印
void SListPrint(SList* plist)
{
	assert(plist);

	SListNode * cur;
	for (cur = plist->_head; cur; cur = cur->_next)
	{
		printf("%d->", cur->_data);
	}
	printf("NULL\n");
}
//查找
SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode * cur;

	for (cur = plist->_head; cur; cur = cur->_next)
	{
		if (cur->_data == x)
		{
			return cur;//返回这个结点
		}
	}
	return NULL;
}
//在值确定的某个结点前进行插入
void SListInsertFront(SList* plist, SLTDataType x, SLTDataType src)
{
	assert(plist);
	SListNode * cur;
	SListNode * newdata = (SListNode *)malloc(sizeof(SListNode));

	if (plist->_head->_data == x)//如果该结点是头结点，直接进行头插
	{
		SListPushFront(plist, src);
		return;
	}
	for (cur = plist->_head; cur->_next; cur = cur->_next)//找到这个结点
	{
		if (cur->_next->_data == x)//注意这里查的是cur的下一个结点等于x
		{
			break;
		}
	}
	newdata->_data = src;//进行插入
	newdata->_next = cur->_next;
	cur->_next = newdata;
}

//在某结点后进行插入
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode * cur = (SListNode *)malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = pos->_next;
	pos->_next = cur;
}

//删除某个位置的结点
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	SListNode * tmp = pos->_next;

	pos->_next = tmp->_next;
	free(tmp);
}