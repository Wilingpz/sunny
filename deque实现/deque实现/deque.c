#include "deque.h"

//��ʼ��
void dequeInit(deque * qu)
{
	qu->_head = qu->_tail = qu->_data;
	qu->_size = 0;
}

//�пղ���
void dequeEmpty(deque * qu)
{
	qu->_head = qu->_tail;
	qu->_size = 0;
}

//�������
int dequePush(deque * qu, DataType x)
{
	*qu->_tail = x;//��Ϊ����->��*�����ȼ�Ҫ�ߣ�����û������
	//*(qu->_tail)=x;

	if (qu->_tail + 1 == qu->_head ||             //����ǰ��������
		(qu->_tail + 1 - qu->_data == QUEUENUM &&
		qu->_head == qu->_data))
	{
		return -1;
	}

	qu->_tail++;
	if (qu->_tail - qu->_data == QUEUENUM)//���������
	{
		qu->_tail = qu->_data;
	}

	qu->_size++;
	return 0;
}

//ɾ������
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

//����ͷ���ֵ
DataType dequeFront(deque * qu)
{
	return *qu->_head;
}

//����β����ֵ
DataType dequeBack(deque * qu)
{
	if (qu->_tail == qu->_data)
	{
		return qu->_data[QUEUENUM - 1];
	}
	return qu->_tail[-1];
}

//�п�
int dequeIsEmpty(deque * qu)
{
	return qu->_head == qu->_tail;
}

//����size��С
size_t dequeSize(deque * qu)
{
	return qu->_size;
}