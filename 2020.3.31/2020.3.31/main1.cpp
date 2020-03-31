#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a = 12345;
	a %= 1000;
	printf("%d\n",a);//345
	printf("%06d\n",a);//000345
	system("pause");
	return 0;
}