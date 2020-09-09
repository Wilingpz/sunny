#ifndef _SLIST_H_
#define _SLIST_H_
/*������ͷ������α���
for (cur = _head;cur;cur = cur->next)//��cur=ͷ����cur��Ϊ��ʱ������ʹcur+1
//��cur��next���ڿ�ʱ�����ṹ
{
      cur;
}
˫��ѭ������ı���

for(cur = head->next;cur != head;cur = cur->next)
{
cur
}

*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;

typedef struct SList
{
	SListNode* _head;
}SList;


void SListInit(SList* plist);
void SListDestory(SList* plist);
SListNode* BuySListNode(SLTDataType x);
void SListPushFront(SList* plist, SLTDataType x);
void SListPopFront(SList* plist);
SListNode* SListFind(SList* plist, SLTDataType x); // ��pos�ĺ�����в��� 
void SListInsertAfter(SListNode* pos, SLTDataType x); // ��pos��ǰ����в��� 
void SListEraseAfter(SListNode* pos);
void SListRemove(SList* plist, SLTDataType x);
void SListPrint(SList* plist); 
void TestSList();

#endif
