#include "List.h"

//��ʼ��
void ListInit(List* plist)
{
	plist->_head = (ListNode *)malloc(sizeof(ListNode));//����ͷ���
	memset(&plist->_head->_data, 0, sizeof(LTDataType));
	/*
	# include <string.h>
	void *memset(void *s, int c, unsigned long n);
	��ָ����� s ��ָ���ǰ n �ֽڵ��ڴ浥Ԫ��һ���������� c �滻��ע�� c �� int �͡�
	s �� void* �͵�ָ�����������������Ϊ�κ����͵����ݽ��г�ʼ����
	*/
	plist->_head->_next = plist->_head->_prev = plist->_head;
}

//β��
void ListPushBack(List* plist, LTDataType x)
{
	ListNode *cur = (ListNode *)malloc(sizeof(ListNode));
	cur->_data = x;

	
	plist->_head->_prev->_next = cur;//�����Ͳ���ǰ�����һ��������ϵ
	cur->_prev = plist->_head->_prev;
	plist->_head->_prev = cur;//������ͷ������ϵ
	cur->_next = plist->_head;
}

//βɾ
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
//ͷ��
void ListPushFront(List* plist, LTDataType x)
{
	ListNode *cur = (ListNode *)malloc(sizeof(ListNode));
	cur->_data = x;

	plist->_head->_next->_prev = cur;//����cur��ͷ������һ��������ϵ
	cur->_next = plist->_head->_next;
	plist->_head->_next = cur;//����head��cur����ϵ
	cur->_prev = plist->_head;
}
//ͷɾ
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

//��ӡ
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
//����
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

	free(plist->_head);//����ͷ�ͷ���
	plist->_head = NULL;
}