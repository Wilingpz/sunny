//ͷ�ļ�
#ifndef SEQLIST_H_   //#ifndef����˼�����δ�������壬��ֹ��α���
#define SEQLIST_H_   
/*
��ͷ�ļ������ݶ�����#ifndef��#endif�аɡ�
�������ͷ�ļ��᲻�ᱻ����ļ����ã��㶼Ҫ���������
һ���ʽ�������ģ�

#ifndef <��ʶ>
#define <��ʶ>

��
��

#endif
*/
#include <stdio.h>
#include<stdlib.h>
#include<assert.h>//�п�
typedef int SLDataType;

typedef struct SeqList//һ���ṹ��
{
	SLDataType* array;  // ָ��̬���ٵ�����     
	size_t size;       // ��Ч���ݸ���     
	size_t capicity;   // �����ռ�Ĵ�С 
}SeqList;

// ������ɾ��Ľӿ� 
void SeqListInit(SeqList* psl, size_t capicity);
void SeqListDestory(SeqList* psl);
void CheckCapacity(SeqList* psl);
void SeqListPushBack(SeqList* psl, SLDataType x);
void SeqListPopBack(SeqList* psl);
void SeqListPushFront(SeqList* psl, SLDataType x);
void SeqListPopFront(SeqList* psl);
int SeqListFind(SeqList* psl, SLDataType x);
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);
void SeqListErase(SeqList* psl, size_t pos);
void SeqListRemove(SeqList* psl, SLDataType x);
void SeqListModify(SeqList* psl, size_t pos, SLDataType x);
void SeqListPrint(SeqList* psl);
//ð������
void SeqListBubbleSort(SeqList* psl);
#endif //SEQLIST_H_