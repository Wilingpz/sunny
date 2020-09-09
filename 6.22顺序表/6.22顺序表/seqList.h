//头文件
#ifndef SEQLIST_H_   //#ifndef的意思是如果未定义则定义，防止多次编译
#define SEQLIST_H_   
/*
把头文件的内容都放在#ifndef和#endif中吧。
不管你的头文件会不会被多个文件引用，你都要加上这个。
一般格式是这样的：

#ifndef <标识>
#define <标识>

…
…

#endif
*/
#include <stdio.h>
#include<stdlib.h>
#include<assert.h>//判空
typedef int SLDataType;

typedef struct SeqList//一个结构体
{
	SLDataType* array;  // 指向动态开辟的数组     
	size_t size;       // 有效数据个数     
	size_t capicity;   // 容量空间的大小 
}SeqList;

// 基本增删查改接口 
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
//冒泡排序
void SeqListBubbleSort(SeqList* psl);
#endif //SEQLIST_H_