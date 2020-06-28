//测试大端小端
#include<stdio.h>
void CheckSystem1()
{
	int a = 1;
	int num = (*(char*)&a);//&a 取出a的地址；  (char*)&a 代表a变量地址的第一个字节的地址
	printf("%d\n", num);//(*(char*)&a) 解引用取出第一个字节保存的内容打印
	if (num == 1)
		printf("小端\n");
	else
		printf("大端\n");
}
int main()
{
	CheckSystem1();
	getchar();
	return 0;
}
//2.联合体特性
int CheckSystem2()
{
	union check
	{
		int num;
		char a;//2个变量公用一块内存空间，并且2个变量的首地址相等
	}b;
	b.num = 1;//1存放在变量num的低位
	return (b.a == 1);//当变量a=1，相当于将数据的低位存到了内存的低地址处，即小端模式
}
int main()
{
	int c = CheckSystem2();
	printf("c : %d\n", c);
	getchar();
	return 0;
}