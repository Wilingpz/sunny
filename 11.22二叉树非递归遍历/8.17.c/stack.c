#include"Stack.h"
void StackInit(Stack* psl, size_t capicity)
{
	assert(psl);//断言

	psl->capicity = capicity;
	psl->array = (StDataType *)malloc(capicity * sizeof(StDataType));
	//malloc 不一定可以申请到空间，所以要进行判空
	assert(psl->array);
	psl->size = 0;
}
void StackDestory(Stack* psl)
{
	assert(psl);
	if (psl->array)
	{
		free(psl->array);
		psl->array = NULL;
		psl->size = 0;
		psl->capicity = 0;
	}
}
void CheckCapacity(Stack* psl)
{
	assert(psl);
	if (psl->size == psl->capicity)//如果上限和大小相等，则需要扩容
	{
		psl->capicity *= 2;
		psl->array = (StDataType *)realloc(psl->array, psl->capicity * sizeof(StDataType));
	}

}
void StackPush(Stack* psl, StDataType x) // 尾插
{
	assert(psl);
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;

}
void StackPop(Stack* psl)//释放尾部元素
{
	assert(psl || psl->size);
	psl->size--;//直接--即可，数据在，但是不属于它了，下次尾插可以直接覆盖该数据
}
StDataType StackTop(Stack* psl)
{
	if (StackIsEmpty(psl))
	{
		return (StDataType)0;
	}
	return psl->array[psl->size - 1];
}

int StackIsEmpty(Stack* psl)
{
	return psl->size == 0;
}
