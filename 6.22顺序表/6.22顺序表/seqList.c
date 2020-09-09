//��������
#include"seqList.h"

//��ʼ��
void SeqListInit(SeqList* psl, size_t capicity)
{
	assert(psl);//���Ըýṹ�����

	psl->capicity = capicity;
	psl->array = (SLDataType *)malloc(capicity * sizeof(SLDataType));
	//malloc ��һ���������뵽�ռ䣬����Ҫ�����п�
	assert(psl->array);
	psl->size = 0;
}
//����
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
//�ж��Ƿ�Ҫ����
	void CheckCapacity(SeqList* psl)
	{
		assert(psl);
		if (psl->size == psl->capicity)//������޺ʹ�С��ȣ�����Ҫ����
		{
			psl->capicity *= 2;
			psl->array = (SLDataType *)realloc(psl->array, psl->capicity * sizeof(SLDataType));
		}
	}
	//β��
	void SeqListPushBack(SeqList* psl, SLDataType x) 
	{
		assert(psl);
		CheckCapacity(psl);
		psl->array[psl->size] = x;
		psl->size++;

	}
	//βɾ
	void SeqListPopBack(SeqList* psl)//�ͷ�β��Ԫ��
	{
		assert(psl || psl->size);
		psl->size--;//ֱ��--���ɣ������ڣ����ǲ��������ˣ��´�β�����ֱ�Ӹ��Ǹ�����
	}
	//ͷ�壬������Ԫ��������
	void SeqListPushFront(SeqList* psl, SLDataType x)
	{
		//����������飬������Ԫ��������
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

	//ͷɾ����ǰ����
	void SeqListPopFront(SeqList* psl)
	{
		assert(psl);
		int i;
		psl->size--;//�����߸���ֻ��Ҫ�ƶ����μ���
		for (i = 0; i < psl->size; i++)
		{
			psl->array[i] = psl->array[i + 1];
		}
	}
	//��ӡ
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
	//����
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
	//��ĳ��λ�ò���һ������
	void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
	{
		assert(psl && pos <= psl->size);//=��ʾβ��
		CheckCapacity(psl);
		int i;
		for (i = psl->size - 1; i >= pos; i--)
		{
			psl->array[i + 1] = psl->array[i];
		}
		psl->array[pos] = x;
		psl->size++;
	}
	//ɾ��ָ��λ�õ���
	void SeqListErase(SeqList* psl, size_t pos)
	{
		assert(psl || pos < psl->size);
		psl->size--;//�����߸���ֻ��Ҫ�ƶ����μ���
		int i;
		for (i = pos; i < psl->size; i++)
		{
			psl->array[i] = psl->array[i + 1];
		}
	}
	//ɾ��ĳ��ָ��Ԫ��
	void SeqListRemove(SeqList* psl, SLDataType x)
	{
		assert(psl);

		int pos = SeqListFind(psl, x);//�ҵ����Ҫɾ����Ԫ�ص�����λ��
		if (pos >= 0)
		{
			SeqListErase(psl, pos);
		}
	}
	//�޸�ָ��λ�õ�Ԫ��ֵ
	void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
	{
		assert(psl || pos < psl->size);
		psl->array[pos - 1] = x;//��1��Ϊ���������ո����Ķ����������±�
	}
	//ð������
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
	//���ֲ���
int SeqListBinaryFind(SeqList* psl, SLDataType x)
{
	assert(psl);
	int left = 0;
	int right = psl->size - 1;//for(int i = 0;;)������Ҫ��ôд��һ�������
	//������ı���ֱ��д�������漴�ɡ�
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