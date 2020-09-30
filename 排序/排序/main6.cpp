#include <iostream>
using namespace std;
//Ã°ÅİÅÅĞò
void Print3(int *arr, int n, int i) 
{
	cout << i << ": ";
	for (int j = 0; j < n; ++j) 
	{
		cout << arr[j] << " ";
	}
	cout << endl;
}

void BubbleSort(int *arr, int n) 
{
	for (int i = 0; i < n - 1; ++i) 
	{
		for (int j = 0; j < n - i - 1; ++j) 
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
		Print3(arr, 10, i);
	}
}

int main6()
{
	int arr[10] = { 5, 9, 6, 2, 1, 4, 7, 3, 8, 0 };
	BubbleSort(arr, 10);
	Print3(arr, 10, 10);

	system("pause");
	return 0;
}