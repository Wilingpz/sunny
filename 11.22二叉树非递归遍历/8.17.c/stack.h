//头文件
#ifndef Stack_H_
#define Stack_H_
#include <stdio.h>
#include<stdlib.h>
#include<assert.h>//判空
#include "Btree.h"
typedef BTNode* StDataType;

typedef struct Stack//一个结构体
{
	StDataType* array;  // 指向动态开辟的数组     
	size_t size;       // 有效数据个数     
	size_t capicity;   // 容量空间的大小 
}Stack;

// 基本增删查改接口 
void StackInit(Stack* psl, size_t capicity);
void StackDestory(Stack* psl);

void StackPush(Stack* psl, StDataType x);
void StackPop(Stack* psl);
int StackIsEmpty(Stack* psl);

#endif //Stack_H_//函数功能
