#include<iostream>
using namespace std;
int main()
{
	int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int count = sizeof(array) / sizeof(int);//结果为10
	cout << count << endl;
	system("pause");
	return 0;
}
//Strlen和sizeof的区别：
//1、strlen是函数，sizeof是运算符
//2、strlen测量的是字符串的实际长度，以\0结束，而sizeof测量的是字符分配的大小
//3、strlen的结果要运行的时候才能计算出来，而大部分编译程序在编译的的阶段就把sizeof计算过了是类型或者是变量的长度。
//4、但是在子函数中，sizeof会把从主函数中传进来的字符数组当作指针来处理。指针的大小是由机器来决定的，而不是人为决定的。
//5、例：
//#include <stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//int main()
//{
//	char str1[] = "hello";
//	char str2[] = { 'h', 'e', 'l', 'l', 'o', '\0' };
//	char str3[] = { 'h', 'e', 'l', 'l', 'o' };
//
//	printf("str1:%s\n", str1);
//	printf("str2:%s\n", str2);
//	printf("str3:%s\n", str3);
//
//	printf("str1:%d\n", strlen(str1));
//	printf("str2:%d\n", strlen(str2));
//	printf("str3:%d\n", strlen(str3));
//	system("pause");
//	return 0;
//}
//
//结果：
//str1 : hello
//str2 : hello
//str3 : hello烫烫烫烫烫蘦ello
//str1 : 5
//str2 : 5
//str3 : 21
//出现这种结果的原因：字符串是以\0为结束标志的，所以str1等效于str2，而str3会一直，从首地址找下去直到找到\0才会结束。
//6、例：
//Char s1[] = “hello”;
//Char *s2 = “hello”; (char* s2是一个指针)
//Char s3[10] = “hello”；
//Sizeof（s1） = 5;
//sizeof(s2) = 4（指针在32位系统下占4字节，在64位系统下占8字节）
//sizeof(s3) = 10
//Strlen(s1) = 5
//strlen(s2) = 5
//strien(s3) = 5;
