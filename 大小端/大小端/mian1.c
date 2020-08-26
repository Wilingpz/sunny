#include<stdio.h>
//一维数组传参
//void test(int arr[])//ok?
//{}
//void test(int arr[10])//ok?
//{}
//void test(int *arr)//ok?
//{}
//void test2(int *arr[20])//ok?
//{}
void test2(int **arr)//ok?
{}
int main2()
{
	int arr[10] = { 0 };
	int *arr2[20] = { 0 };
	test(arr);//可以传arr[]、可以传arr[10]、可以传*arr
	test2(arr2);//可以传*arr[20],也可以传**arr
	system("pause");
	return 0;
}


