#include <stdio.h>
#include <stdio.h >
#include <stdlib.h>
int main()
{
	int n = 9876;
	int i;
	for (i = n; i; i /= 10)
	{
		printf("%d", i % 10);
	}
	system("pause");
	return 0;
}


