//���Ժ���
#include "seqList.h"

int main()
{
	SeqList test;
	SeqListInit(&test, 10);//�ѵ�ַ���ĸ������Ӻ���
	//�Ӷ����Զ�����в���
	SeqListPushBack(&test, 1);
	SeqListPushBack(&test, 2);
	SeqListPushBack(&test, 3);
	SeqListPushBack(&test, 4);
	SeqListPushBack(&test, 5);
	SeqListPushBack(&test, 6);
	SeqListPushBack(&test, 7);
	SeqListPushBack(&test, 8);
	SeqListPushFront(&test, 10);
	SeqListPushFront(&test, 10);
	SeqListPushFront(&test, 10);
	SeqListPopBack(&test);
	
	SeqListInsert(&test, 1, 16);//��ĳ��λ�ò���һ������
	SeqListErase(&test, 2);
	SeqListRemove(&test, 4);
	SeqListModify(&test,5,6);
	SeqListPrint(&test);
    SeqListDestory(&test);
	system("pause");
	return 0;
}