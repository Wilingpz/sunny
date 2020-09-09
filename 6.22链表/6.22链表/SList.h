#ifndef _SLIST_H_
#define _SLIST_H_
/*单向无头链表如何遍历
for (cur = _head;cur;cur = cur->next)//令cur=头，当cur不为空时，继续使cur+1
//当cur的next等于空时跳出结构
{
      cur;
}
双向循环链表的遍历

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
SListNode* SListFind(SList* plist, SLTDataType x); // 在pos的后面进行插入 
void SListInsertAfter(SListNode* pos, SLTDataType x); // 在pos的前面进行插入 
void SListEraseAfter(SListNode* pos);
void SListRemove(SList* plist, SLTDataType x);
void SListPrint(SList* plist); 
void TestSList();

#endif
