#include<iostream>
#include"vector.h"
using namespace std;


int main()
{

	pz::test();	
	system("pause");
	return 0;
}

/*
memxxx 按字节处理
int a[10];
memset(a,0,sizeof(int)*10); 
memset(a,1,sizeof(int)*10); 
memset(a,1,sizeof(int)*10);


memset()函数原型是
extern void *memset(void *buffer, int c, int count)        
buffer：为指针或是数组,

c：是赋给buffer的值,

count：是buffer的长度.


这个函数在socket中多用于清空数组.如:原型是memset(buffer, 0, sizeof(buffer))



c++　在函数后加const的意义：
　 我们定义的类的成员函数中，常常有一些成员函数不改变类的数据成员，也就是说，这些函数是"只读"函数，
   而有一些函数要修改类数据成员的值。如果把不改变数据成员的函数都加上const关键字进行标识，显然，可提高程序的可读性
*/