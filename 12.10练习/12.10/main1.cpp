#include <iostream>//��һ�������������Ƕ���
#include<math.h>
using namespace std;
int main()
{
	int num;
	int k = 0;
	int i = 2;
	while (cin >> num)
	{
		for (; i <= sqrt(num); i++)
		{
			if ((num % i) == 0) 
			{
				while ((num % i) == 0)
				{
					num = num / i;
				}
				k++;
			}
		}
		if (num != 1)
		{
			k++;
		}
		cout << k << endl;
	}
	system("pause");
	return 0;
}

