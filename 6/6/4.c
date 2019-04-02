#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//实现一个函数，判断一个数是不是素数。 
void IsPrime(int number) {
	int x;
	if (number == 1) {
		printf("不是素数\n");
	}
	else {
		for (x = 2; x <= sqrt(number); x++) {
			if (number % x == 0) {
				printf("不是素数\n");
				return;
			}
		} 
			printf("是素数\n");
	}
}
int main4() {
	int number;
	int x = 0;
	printf("请输入一个数:");
	scanf("%d", &number);
	IsPrime(number);
	system("pause");
	return 0;
}
