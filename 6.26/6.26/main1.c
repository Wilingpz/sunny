#include<stdio.h>

int Add(int a, int b)
{
	return a + b;
}

double Add(double a, double b)
{
	return a + b;
}

int main()
{
	int a = 1, b = 2;
	printf("%d",Add(a, b));
	system("pause");
	return 0;
}