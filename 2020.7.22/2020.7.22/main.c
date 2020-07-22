#include<stdio.h>
#include<stdlib.h>

int main1()
{
	int num = 10;
	int* ptr = NULL;
	ptr=(int*)calloc(num,sizeof(int));//c语言的隐式类型转换
    //ptr=(int*)malloc(num*sizeof(int));
	return 0;
}
//问题1：

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

/*如果需要改变str,改变变量用一级指针,改变指针用二级指针,
但传入的是一级指针,所以没有对str中存放的地址NULL进行改变,
所以后面执行strcmp和strcat的内容会让程序崩溃。
（2）动态申请内存有可能失败，所以应该增加判断。
（3）动态创建的内存没释放。*/

//修改
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

//拓展知识

void  fun(int  *p)
{
	int  b = 100;
	p = &b;		//	将p指向b，改变的是局部变量的值，实参不受影响
}
void  fun2(int  *p)
{
	*p = 100;		// 将p指向的变量赋值100，改变的是实参指针指向的值，实参会受到影响	                //
}                   //改变变量用一级指针,改变指针用二级指针,

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

void  GetMem1(char  *s) 				// 想在函数中分配内存,再返回，徒劳无功
{
	s = (char  *)malloc(100);		// GetMem1被调用时相当于用实参初始化了s，s指向了实参，
	// 之后再执行malloc则会将申请到的内存地址再赋值给s
	// 显然对实参没有任何影响。
}

void  GetMem2(char  **s)//char *s存的地址是NULL，char**s存的地址是*s的地址
{
	*s = (char  *)malloc(100);		// s指向的是实参的地址,所以改变了实参指向的内容.
}

void  main4()
{
	char  *p = NULL;
	GetMem1(p);
	if (p)  free(p);					// p仍然指向NULL
	GetMem2(&p);//取指针p的地址给char**s
	if (p)  free(p);					// p指向了新申请的内存地址
}

//问题2
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
p是一个局部变量，函数调用结束后会释放，所以返回地址不明确
输出结果不确定
*/

//问题三
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
/*运行正确，但有内存泄露,没有判断malloc是否申请成功，没有释放指针str*/

//问题四
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
/*运行结果为乱码，没判断空间是否申请成功，释放指针后没有置空，
  使其成为野指针，*/
int main8()
{
	Test();
	system("pause");
	return 0;
	
}
