#include<stdio.h>
#include<stdlib.h>

int check_sys()
{
	union 
	{
		int i;
		char c;  //�����干��һ�δ洢�ռ�
	}t;
	t.i = 1;
	return t.c;
}

//int check_sys()
//{
//	int i = 1;
//	return (*(char*)&i);
//}
int main1()
{
	int ret = check_sys();
	if (ret == 1)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}
	system("pause");
	return 0;
}

int main2()
{
	char* pstr = "hello bit.";//�����ǰ�һ���ַ����ŵ�pstrָ�����������
	printf("%s\n", pstr);
	return 0;
}//ֻ�ǽ�"hello bit"�����ַ���ַ�Ž���*pstr����
