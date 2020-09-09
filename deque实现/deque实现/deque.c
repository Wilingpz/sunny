#include "deque.h"

//初始化
void dequeInit(deque * qu)
{
	qu->_head = qu->_tail = qu->_data;
	qu->_size = 0;
}

//判空操作
void dequeEmpty(deque * qu)
{
	qu->_head = qu->_tail;
	qu->_size = 0;
}

//插入操作
int dequePush(deque * qu, DataType x)
{
	*qu->_tail = x;//因为这里->比*的优先级要高，所以没加括号
	//*(qu->_tail)=x;

	if (qu->_tail + 1 == qu->_head ||             //插入前队列已满
		(qu->_tail + 1 - qu->_data == QUEUENUM &&
		qu->_head == qu->_data))
	{
		return -1;
	}

	qu->_tail++;
	if (qu->_tail - qu->_data == QUEUENUM)//插入后已满
	{
		qu->_tail = qu->_data;
	}

	qu->_size++;
	return 0;
}

//删除操作
int dequePop(deque * qu)
{
	if (dequeIsEmpty(qu))
	{
		return -1;
	}

	qu->_head++;
	if (qu->_head - qu->_data == QUEUENUM)
	{
		qu->_head = qu->_data;
	}

	qu->_size--;
	return 0;
}

//返回头结点值
DataType dequeFront(deque * qu)
{
	return *qu->_head;
}

//返回尾结点的值
DataType dequeBack(deque * qu)
{
	if (qu->_tail == qu->_data)
	{
		return qu->_data[QUEUENUM - 1];
	}
	return qu->_tail[-1];
}

//判空
int dequeIsEmpty(deque * qu)
{
	return qu->_head == qu->_tail;
}

//返回size大小
size_t dequeSize(deque * qu)
{
	return qu->_size;
}