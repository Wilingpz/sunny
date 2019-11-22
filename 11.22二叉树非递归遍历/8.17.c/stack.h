//ͷ�ļ�
#ifndef Stack_H_
#define Stack_H_
#include <stdio.h>
#include<stdlib.h>
#include<assert.h>//�п�
#include "Btree.h"
typedef BTNode* StDataType;

typedef struct Stack//һ���ṹ��
{
	StDataType* array;  // ָ��̬���ٵ�����     
	size_t size;       // ��Ч���ݸ���     
	size_t capicity;   // �����ռ�Ĵ�С 
}Stack;

// ������ɾ��Ľӿ� 
void StackInit(Stack* psl, size_t capicity);
void StackDestory(Stack* psl);

void StackPush(Stack* psl, StDataType x);
void StackPop(Stack* psl);
int StackIsEmpty(Stack* psl);

#endif //Stack_H_//��������
