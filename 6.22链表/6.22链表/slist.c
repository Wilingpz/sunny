#include "slist.h"

//������
void SListInit(SList* plist)//��ʼ��
{
	assert(plist);
	plist->_head = NULL;
}

void SListDestory(SList* plist)//����������
{
	SListNode * tmp;
	while (plist->_head)//ͷ��㲻Ϊ�յ����
	{
		tmp = plist->_head;
		plist->_head = plist->_head->_next;//��ͷ
		free(tmp);//�ͷ�ͷ���
	}
}
//ͷ��
void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);

	SListNode * cur = (SListNode *)malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = plist->_head;//��ͷ����
	plist->_head = cur;
}
//ͷɾ
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
//��ӡ
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
//����
SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode * cur;

	for (cur = plist->_head; cur; cur = cur->_next)
	{
		if (cur->_data == x)
		{
			return cur;//����������
		}
	}
	return NULL;
}
//��ֵȷ����ĳ�����ǰ���в���
void SListInsertFront(SList* plist, SLTDataType x, SLTDataType src)
{
	assert(plist);
	SListNode * cur;
	SListNode * newdata = (SListNode *)malloc(sizeof(SListNode));

	if (plist->_head->_data == x)//����ý����ͷ��㣬ֱ�ӽ���ͷ��
	{
		SListPushFront(plist, src);
		return;
	}
	for (cur = plist->_head; cur->_next; cur = cur->_next)//�ҵ�������
	{
		if (cur->_next->_data == x)//ע����������cur����һ��������x
		{
			break;
		}
	}
	newdata->_data = src;//���в���
	newdata->_next = cur->_next;
	cur->_next = newdata;
}

//��ĳ������в���
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode * cur = (SListNode *)malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = pos->_next;
	pos->_next = cur;
}

//ɾ��ĳ��λ�õĽ��
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	SListNode * tmp = pos->_next;

	pos->_next = tmp->_next;
	free(tmp);
}