#include <iostream>
using namespace std;

void Print2(int a[], int n, int i) 
{
	cout << "��" << i + 1 << "�� : ";
	for (int j = 0; j<8; j++) 
	{
		cout << a[j] << "  ";
	}
	cout << endl;
}
/**
* �������Сֵ
*
* @return int ����ļ�ֵ
*/
int SelectMinKey(int a[], int n, int i)
{
	int k = i;
	for (int j = i + 1; j< n; ++j) 
	{
		if (a[k] > a[j]) 
			k = j;
	}
	return k;
}

/**
* ѡ������
*
*/
void SelectSort(int a[], int n)
{
	int key, tmp;
	for (int i = 0; i < n - 1; ++i) 
	{
		key = SelectMinKey(a, n, i);           //ѡ����С��Ԫ��  
		if (key != i) 
		{
			tmp = a[i];  
			a[i] = a[key]; 
			a[key] = tmp; //��СԪ�����iλ��Ԫ�ػ���  
		}
		Print2(a, n, i);
	}
}
int main3() 
{
	int a[8] = { 3, 1, 5, 7, 2, 4, 9, 6 };
	cout << "��ʼֵ��";
	for (int j = 0; j<8; j++) 
	{
		cout << a[j] << "  ";
	}
	cout << endl << endl;
	SelectSort(a, 8);
	Print2(a, 8, 8);
	system("pause");
	return 0;
}