#include <stdio.h>

int main()
{
	int i = 3;
	printf("%d %d %d %d", ++i, i++, ++i, i++);//7,5,7,3
	system("pause");
	return 0;
}