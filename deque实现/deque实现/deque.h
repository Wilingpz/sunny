#ifndef _deque_H_
#define _deque_H_

#include <stdio.h>
#include <stdlib.h>

#define QUEUENUM 5
typedef int DataType;

typedef struct{
	DataType _data[QUEUENUM];
	DataType * _head;//头指针
	DataType * _tail;//尾指针
	size_t _size;//大小
}deque;

void dequeInit(deque * qu);
void dequeEmpty(deque * qu);
int dequePush(deque * qu, DataType x);
int dequePop(deque * qu);
DataType dequeBack(deque * qu);
size_t dequeSize(deque * qu);
int dequeIsEmpty(deque * qu);
size_t dequeSize(deque * qu);


#endif //_deque_H_