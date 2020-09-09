//函数功能
#include"seqList.h"

//初始化
void SeqListInit(SeqList* psl, size_t capicity)
{
	assert(psl);//断言该结构体存在

	psl->capicity = capicity;
	psl->array = (SLDataType *)malloc(capicity * sizeof(SLDataType));
	//malloc 不一定可以申请到空间，所以要进行判空
	assert(psl->array);
	psl->size = 0;
}
//销毁
void SeqListDestory(SeqList* psl)
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
//判断是否要扩容
	void CheckCapacity(SeqList* psl)
	{
		assert(psl);
		if (psl->size == psl->capicity)//如果上限和大小相等，则需要扩容
		{
			psl->capicity *= 2;
			psl->array = (SLDataType *)realloc(psl->array, psl->capicity * sizeof(SLDataType));
		}
	}
	//尾插
	void SeqListPushBack(SeqList* psl, SLDataType x) 
	{
		assert(psl);
		CheckCapacity(psl);
		psl->array[psl->size] = x;
		psl->size++;

	}
	//尾删
	void SeqListPopBack(SeqList* psl)//释放尾部元素
	{
		assert(psl || psl->size);
		psl->size--;//直接--即可，数据在，但是不属于它了，下次尾插可以直接覆盖该数据
	}
	//头插，将后面元素往后移
	void SeqListPushFront(SeqList* psl, SLDataType x)
	{
		//逆向遍历数组，将数组元素往后移
		assert(psl);
		CheckCapacity(psl);

		int i;
		for (i = psl->size -1; i >= 0; i--)
		{
			psl->array[i + 1] = psl->array[i];
		}
			psl->array[0] = x;
			psl->size++;
	}

	//头删，向前覆盖
	void SeqListPopFront(SeqList* psl)
	{
		assert(psl);
		int i;
		psl->size--;//例如七个数只需要移动六次即可
		for (i = 0; i < psl->size; i++)
		{
			psl->array[i] = psl->array[i + 1];
		}
	}
	//打印
	void SeqListPrint(SeqList* psl)
	{
		assert(psl);
		int i;
		for (i = 0; i < psl->size; i++)
		{
			printf("%d",psl->array[i]);
		}   
		putchar('\n');
	}
	//查找
	int SeqListFind(SeqList* psl, SLDataType x)
	{
		assert(psl);
		int i;
		for (i = 0; i < psl->size; i++)
		{
			if (psl->array[i] == x)
			{
				return i;
			}
		}
		return -1;
	}
	//在某个位置插入一个数据
	void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
	{
		assert(psl && pos <= psl->size);//=表示尾插
		CheckCapacity(psl);
		int i;
		for (i = psl->size - 1; i >= pos; i--)
		{
			psl->array[i + 1] = psl->array[i];
		}
		psl->array[pos] = x;
		psl->size++;
	}
	//删除指定位置的数
	void SeqListErase(SeqList* psl, size_t pos)
	{
		assert(psl || pos < psl->size);
		psl->size--;//例如七个数只需要移动六次即可
		int i;
		for (i = pos; i < psl->size; i++)
		{
			psl->array[i] = psl->array[i + 1];
		}
	}
	//删除某个指定元素
	void SeqListRemove(SeqList* psl, SLDataType x)
	{
		assert(psl);

		int pos = SeqListFind(psl, x);//找到这个要删除的元素的所在位置
		if (pos >= 0)
		{
			SeqListErase(psl, pos);
		}
	}
	//修改指定位置的元素值
	void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
	{
		assert(psl || pos < psl->size);
		psl->array[pos - 1] = x;//减1是为了让它按照个数改而不是数组下标
	}
	//冒泡排序
void SeqListBubbleSort(SeqList* psl)
	{
	assert(psl);
	int i, j;
	SLDataType tmp;
	for (i = 0; i < psl->size - 1; i++)
	{
		for (j = 0; j < psl->size - 1 - i; j++)
		{
			if (psl->array[j] > psl->array[j+1])
			{
tmp = psl->array[j];
psl->array[j] = psl->array[j + 1];
psl->array[j + 1] = tmp;
 	}
 }
 }
}
	//二分查找
int SeqListBinaryFind(SeqList* psl, SLDataType x)
{
	assert(psl);
	int left = 0;
	int right = psl->size - 1;//for(int i = 0;;)尽量不要这么写，一般情况下
	//将定义的变量直接写在最上面即可。
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (psl->array[mid] < x)
		{
			left = mid + 1;
		}
		else if (psl->array[mid] > x)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}