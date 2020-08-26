#include<stdio.h>
#include<stdlib.h>

int check_sys()
{
	union 
	{
		int i;
		char c;  //联合体共用一段存储空间
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
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	system("pause");
	return 0;
}

int main2()
{
	char* pstr = "hello bit.";//这里是把一个字符串放到pstr指针变量里了吗？
	printf("%s\n", pstr);
	return 0;
}//只是将"hello bit"的首字符地址放进了*pstr里面
