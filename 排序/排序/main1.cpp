#include <iostream>
using namespace std;
//希尔排序
#include<iostream>

using namespace std;
const int INCRGAP = 2;
void shellSort(int a[], int len)
{
	int insertNum = 0;
	unsigned gap = len / INCRGAP; // 步长初始化,注意如果当len<INCRGAP时，gap为0，所以为了保证进入循环，gap至少为1！！！
	while (gap) // while gap>=1
	{
		for (unsigned i = gap; i < len; ++i) // 分组，在每个子序列中进行插入排序
		{
			insertNum = a[i];//将当前的元素值先存起来方便后面插入
			unsigned j = i;
			while (j >= gap && insertNum < a[j - gap])//寻找插入位置
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