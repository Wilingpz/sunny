#include <iostream>
using namespace std;
//ϣ������
#include<iostream>

using namespace std;
const int INCRGAP = 2;
void shellSort(int a[], int len)
{
	int insertNum = 0;
	unsigned gap = len / INCRGAP; // ������ʼ��,ע�������len<INCRGAPʱ��gapΪ0������Ϊ�˱�֤����ѭ����gap����Ϊ1������
	while (gap) // while gap>=1
	{
		for (unsigned i = gap; i < len; ++i) // ���飬��ÿ���������н��в�������
		{
			insertNum = a[i];//����ǰ��Ԫ��ֵ�ȴ���������������
			unsigned j = i;
			while (j >= gap && insertNum < a[j - gap])//Ѱ�Ҳ���λ��
			{
				a[j] = a[j - gap];
				j -= gap;
			}
			a[j] = insertNum;
		}
		gap = gap / INCRGAP;
	}
}
int main2()
{
	int array[10] = { 9,1,4,3,11,6,5,7,8,10};
	shellSort(array, 10);
	for (auto it : array)
	{
		cout << it << endl;
	}
	system("pause");
	return 0;
}