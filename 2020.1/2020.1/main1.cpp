#include<iostream>
using namespace std;
int main()
{
	int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int count = sizeof(array) / sizeof(int);//���Ϊ10
	cout << count << endl;
	system("pause");
	return 0;
}
//Strlen��sizeof������
//1��strlen�Ǻ�����sizeof�������
//2��strlen���������ַ�����ʵ�ʳ��ȣ���\0��������sizeof���������ַ�����Ĵ�С
//3��strlen�Ľ��Ҫ���е�ʱ����ܼ�����������󲿷ֱ�������ڱ���ĵĽ׶ξͰ�sizeof������������ͻ����Ǳ����ĳ��ȡ�
//4���������Ӻ����У�sizeof��Ѵ��������д��������ַ����鵱��ָ��������ָ��Ĵ�С���ɻ����������ģ���������Ϊ�����ġ�
//5������
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
//�����
//str1 : hello
//str2 : hello
//str3 : hello�����������hello
//str1 : 5
//str2 : 5
//str3 : 21
//�������ֽ����ԭ���ַ�������\0Ϊ������־�ģ�����str1��Ч��str2����str3��һֱ�����׵�ַ����ȥֱ���ҵ�\0�Ż������
//6������
//Char s1[] = ��hello��;
//Char *s2 = ��hello��; (char* s2��һ��ָ��)
//Char s3[10] = ��hello����
//Sizeof��s1�� = 5;
//sizeof(s2) = 4��ָ����32λϵͳ��ռ4�ֽڣ���64λϵͳ��ռ8�ֽڣ�
//sizeof(s3) = 10
//Strlen(s1) = 5
//strlen(s2) = 5
//strien(s3) = 5;
