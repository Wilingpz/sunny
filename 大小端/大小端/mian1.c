#include<stdio.h>
//һά���鴫��
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
	test(arr);//���Դ�arr[]�����Դ�arr[10]�����Դ�*arr
	test2(arr2);//���Դ�*arr[20],Ҳ���Դ�**arr
	system("pause");
	return 0;
}


