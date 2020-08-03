#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"string1.h"

using namespace std;

int main()
{
	pz::test_str();
	system("pause");
	return 0;
	
	
}



//若new一个char空间会有一个/0在里面

//string的迭代器是原生指针

/*
关于 strlen 与 sizeof 的区别：

1. strlen 是函数，sizeof 是运算符。

2. strlen 测量的是字符的实际长度，以'\0' 结束（不包含'\0' ）。
而sizeof 测量的是字符的分配大小，如果未分配大小，则遇到'\0' 结束
（包含'\0' ，也就是strlen测量的长度加1），如果已经分配内存大小，返回的就是分配的内存大小。

char s[] = { "hello world!" };
char s1[100] = { "hello world!" };
cout << strlen(s) << endl;  //12
cout << sizeof(s) << endl;  //13 有\0
cout << sizeof(s1) << endl; //100

3.在子函数中，sizeof 会把从主函数中传进来的字符数组当作是指针来处理。
  指针的大小又是由机器来决定，而不是人为的来决定的。

4.sizeof是一个运算符，而strlen是一个函数，trlen的结果要运行的时候才能计算出来，
而大部分编译程序在编译的的阶段就把sizeof计算过了是类型或者是变量的长度。


*/

/*
char *strstr(const char *haystack, const char *needle) 
在字符串 haystack 中查找第一次出现字符串 needle 的位置，
不包含终止符 '\0'。*/


/*
C 库函数 char *strcpy(char *dest, const char *src) 把src所指向的字符串复制到 dest。
*/


/*
C语言 strcmp() 函数用于对两个字符串进行比较（区分大小写）。

头文件：string.h

语法/原型：

int strcmp(const char* stri1，const char* str2);
参数 str1 和 str2 是参与比较的两个字符串。

strcmp() 会根据 ASCII 编码依次比较 str1 和 str2 的每一个字符，直到出现不到的字符，或者到达字符串末尾（遇见\0）。

返回值：

如果返回值 < 0，则表示 str1 小于 str2。
如果返回值 > 0，则表示 str2 小于 str1。
如果返回值 = 0，则表示 str1 等于 str2。

*/