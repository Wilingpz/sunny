#include "List.h"

//初始化
void ListInit(List* plist)
{
	plist->_head = (ListNode *)malloc(sizeof(ListNode));//申请头结点
	memset(&plist->_head->_data, 0, sizeof(LTDataType));
	/*
	# include <string.h>
	void *memset(void *s, int c, unsigned long n);
	将指针变量 s 所指向的前 n 字节的内存单元用一个“整数” c 替换，注意 c 是 int 型。
	s 是 void* 型的指针变量，所以它可以为任何类型的数据进行初始化。
	*/
	plist->_head->_next = plist->_head->_prev = plist->_head;
}

//尾插
void ListPushBack(List* plist, LTDataType x)
{
	ListNode *cur = (ListNode *)malloc(sizeof(ListNode));
	cur->_data = x;

	
	plist->_head->_prev->_next = cur;//建立和插入前的最后一个结点的联系
	cur->_prev = plist->_head->_prev;
	plist->_head->_prev = cur;//建立和头结点的联系
	cur->_next = plist->_head;
}

//尾删
void ListPopBack(List* plist)
{
	ListNode *tmp = plist->_head->_prev;

	if (tmp != plist->_head)
	{
		tmp->_prev->_next = tmp->_next;
		tmp->_next->_prev = tmp->_prev;
		free(tmp);
	}
}
//头插
void ListPushFront(List* plist, LTDataType x)
{
	ListNode *cur = (ListNode *)malloc(sizeof(ListNode));
	cur->_data = x;

	plist->_head->_next->_prev = cur;//建立cur和头结点的下一个结点的联系
	cur->_next = plist->_head->_next;
	plist->_head->_next = cur;//建立head和cur的联系
	cur->_prev = plist->_head;
}
//头删
void ListPopFront(List* plist)
{
	ListNode *tmp = plist->_head->_next;

	if (tmp != plist->_head)
	{
		tmp->_prev->_next = tmp->_next;
		tmp->_next->_prev = tmp->_prev;
		free(tmp);
	}
}

//打印
void ListPrint(List* plist)
{
	ListNode * cur;
	printf("head<-->");
	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next)
	{
		printf("%d<-->", cur->_data);
	}
	printf("head\n");
}
//销毁
void ListDestroy(List* plist)
{
	ListNode *tmp = plist->_head->_next;

	while (tmp != plist->_head)
	{
		tmp->_prev->_next = tmp->_next;
		tmp->_next->_prev = tmp->_prev;
		free(tmp);

		tmp = plist->_head->_next;
	}

	free(plist->_head);//最后释放头结点
	plist->_head = NULL;
}