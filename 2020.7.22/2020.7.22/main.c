#include<stdio.h>
#include<stdlib.h>

int main1()
{
	int num = 10;
	int* ptr = NULL;
	ptr=(int*)calloc(num,sizeof(int));//c���Ե���ʽ����ת��
    //ptr=(int*)malloc(num*sizeof(int));
	return 0;
}
//����1��

/*void GetMemory(char *p)
{
	p = (char *)malloc(100);
}
void Test(void)
{
	char *str = NULL;
	GetMemory(str);
	strcpy(str, "hello world");
	printf(str);
}*/

/*�����Ҫ�ı�str,�ı������һ��ָ��,�ı�ָ���ö���ָ��,
���������һ��ָ��,����û�ж�str�д�ŵĵ�ַNULL���иı�,
���Ժ���ִ��strcmp��strcat�����ݻ��ó��������
��2����̬�����ڴ��п���ʧ�ܣ�����Ӧ�������жϡ�
��3����̬�������ڴ�û�ͷš�*/

//�޸�
void GetMemory(char **p)
{
	*p = (char *)malloc(100);
	if (NULL == *p)
	{
		printf("malloc failed!");
	}
}
void Test(void)
{
	char *str = NULL;
	GetMemory(&str);
	strcpy(str, "hello world");
	printf(str);
	free(str);
}

//��չ֪ʶ

void  fun(int  *p)
{
	int  b = 100;
	p = &b;		//	��pָ��b���ı���Ǿֲ�������ֵ��ʵ�β���Ӱ��
}
void  fun2(int  *p)
{
	*p = 100;		// ��pָ��ı�����ֵ100���ı����ʵ��ָ��ָ���ֵ��ʵ�λ��ܵ�Ӱ��	                //
}                   //�ı������һ��ָ��,�ı�ָ���ö���ָ��,

main3()
{
	int  a = 10;
	int  *q;
	q = &a;
	printf("*q=%d\n", *q);		// *q=10
	printf("a=*d\n", a);			// a=10
	fun(q);
	printf("*q%d\n", *q);			// *q=10
	printf("a=*d\n", a);			// a=10
	fun2(q);
	printf("*q%d\n", *q);			// *q=100
	printf("a=*d\n", a);			// a=100
	return  0;
}

void  GetMem1(char  *s) 				// ���ں����з����ڴ�,�ٷ��أ�ͽ���޹�
{
	s = (char  *)malloc(100);		// GetMem1������ʱ�൱����ʵ�γ�ʼ����s��sָ����ʵ�Σ�
	// ֮����ִ��malloc��Ὣ���뵽���ڴ��ַ�ٸ�ֵ��s
	// ��Ȼ��ʵ��û���κ�Ӱ�졣
}

void  GetMem2(char  **s)//char *s��ĵ�ַ��NULL��char**s��ĵ�ַ��*s�ĵ�ַ
{
	*s = (char  *)malloc(100);		// sָ�����ʵ�εĵ�ַ,���Ըı���ʵ��ָ�������.
}

void  main4()
{
	char  *p = NULL;
	GetMem1(p);
	if (p)  free(p);					// p��Ȼָ��NULL
	GetMem2(&p);//ȡָ��p�ĵ�ַ��char**s
	if (p)  free(p);					// pָ������������ڴ��ַ
}

//����2
//char *GetMemory(void)
//{
//	char p[] = "hello world";
//	return p;
//}
//void Test(void)
//{
//	char *str = NULL;
//	str = GetMemory();
//	printf(str);
//}
/*
p��һ���ֲ��������������ý�������ͷţ����Է��ص�ַ����ȷ
��������ȷ��
*/

//������
//void GetMemory(char **p, int num)
//{
//	*p = (char *)malloc(num);
//}
//void Test(void)
//{
//	char *str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//} 
/*������ȷ�������ڴ�й¶,û���ж�malloc�Ƿ�����ɹ���û���ͷ�ָ��str*/

//������
//void Test(void)
//{
//	char *str = (char *)malloc(100);
//	strcpy(str, "hello");
//	free(str);
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//} 
/*���н��Ϊ���룬û�жϿռ��Ƿ�����ɹ����ͷ�ָ���û���ÿգ�
  ʹ���ΪҰָ�룬*/
int main8()
{
	Test();
	system("pause");
	return 0;
	
}
