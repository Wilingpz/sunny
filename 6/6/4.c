#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//ʵ��һ���������ж�һ�����ǲ��������� 
void IsPrime(int number) {
	int x;
	if (number == 1) {
		printf("��������\n");
	}
	else {
		for (x = 2; x <= sqrt(number); x++) {
			if (number % x == 0) {
				printf("��������\n");
				return;
			}
		} 
			printf("������\n");
	}
}
int main4() {
	int number;
	int x = 0;
	printf("������һ����:");
	scanf("%d", &number);
	IsPrime(number);
	system("pause");
	return 0;
}
