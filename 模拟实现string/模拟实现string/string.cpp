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



//��newһ��char�ռ����һ��/0������

//string�ĵ�������ԭ��ָ��

/*
���� strlen �� sizeof ������

1. strlen �Ǻ�����sizeof ���������

2. strlen ���������ַ���ʵ�ʳ��ȣ���'\0' ������������'\0' ����
��sizeof ���������ַ��ķ����С�����δ�����С��������'\0' ����
������'\0' ��Ҳ����strlen�����ĳ��ȼ�1��������Ѿ������ڴ��С�����صľ��Ƿ�����ڴ��С��

char s[] = { "hello world!" };
char s1[100] = { "hello world!" };
cout << strlen(s) << endl;  //12
cout << sizeof(s) << endl;  //13 ��\0
cout << sizeof(s1) << endl; //100

3.���Ӻ����У�sizeof ��Ѵ��������д��������ַ����鵱����ָ��������
  ָ��Ĵ�С�����ɻ�������������������Ϊ���������ġ�

4.sizeof��һ�����������strlen��һ��������trlen�Ľ��Ҫ���е�ʱ����ܼ��������
���󲿷ֱ�������ڱ���ĵĽ׶ξͰ�sizeof������������ͻ����Ǳ����ĳ��ȡ�


*/

/*
char *strstr(const char *haystack, const char *needle) 
���ַ��� haystack �в��ҵ�һ�γ����ַ��� needle ��λ�ã�
��������ֹ�� '\0'��*/


/*
C �⺯�� char *strcpy(char *dest, const char *src) ��src��ָ����ַ������Ƶ� dest��
*/


/*
C���� strcmp() �������ڶ������ַ������бȽϣ����ִ�Сд����

ͷ�ļ���string.h

�﷨/ԭ�ͣ�

int strcmp(const char* stri1��const char* str2);
���� str1 �� str2 �ǲ���Ƚϵ������ַ�����

strcmp() ����� ASCII �������αȽ� str1 �� str2 ��ÿһ���ַ���ֱ�����ֲ������ַ������ߵ����ַ���ĩβ������\0����

����ֵ��

�������ֵ < 0�����ʾ str1 С�� str2��
�������ֵ > 0�����ʾ str2 С�� str1��
�������ֵ = 0�����ʾ str1 ���� str2��

*/