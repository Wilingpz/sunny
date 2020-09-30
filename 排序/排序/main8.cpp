#include<iostream>
using namespace std;

void _MergeSort(int*a, int begin, int end, int* tmp)
{
	if (begin >= end)
	{
		return;
	}
	//先划分
	int mid = (begin + end) >> 1;//除以2就是右移一位
	//[begin,mid][mid+1,end] 如何让左右都有序？
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	//归并两段有序空间
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int index = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}
	if (begin1 <= end1)
	{
		while (begin1 <= end1)
		{
			tmp[index++] = a[begin1++];
		}
	}
	else
	{
		while (begin2 <= end2)
		{
			tmp[index++] = a[begin2++];
		}
	}
	memcpy(a + begin, tmp + begin, sizeof(int)*(end - begin + 1));
	//将数据从tmp拷贝回去

}


void MergeSort(int* a, int n)
{
	int * tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1,tmp);
	free(tmp);
}

void TestMerageSort()
{
	int a[] = {3,3,2,5,7,9,8,6,1,5};
	MergeSort(a, sizeof(a)/sizeof(int));
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		cout << a[i];
	}
	cout << endl;

}

int main()
{
	TestMerageSort();
	system("pause");
	return 0;
}