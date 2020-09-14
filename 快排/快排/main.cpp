#include<iostream>
#include<vector>
using namespace std;

#if 1
void QuckSort(int left, int right, vector<int>& v)
{
	if (left >= right)
		return;

	int i, j, base;
	i = left;
	j = right;
	base = v[left];

	while (i < j)
	{
		while (i < j && v[j] >= base)
		{
			j--;
		}
		v[i]=v[j];
		while (i < j && v[i]<=base)
		{
			i++;
		}
		v[j]=v[i];
	}
	v[i] = base;
	//递归左边和右边
    QuckSort(left,i-1,v);
    QuckSort(i+1,right,v);
}

#else
void quickSort(int left, int right, vector<int>& arr)
{
	if (left >= right)
		return;

	int i, j, base, temp;
	i = left, j = right;
	base = arr[left];  //取最左边的数为基准数
	while (i < j)
	{
		while (arr[j] >= base && i < j)
			j--;
		while (arr[i] <= base && i < j)
			i++;
		if (i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	//基准数归位
	arr[left] = arr[i];
	arr[i] = base;
	quickSort(left, i - 1, arr);//递归左边  
	quickSort(i + 1, right, arr);//递归右边
}
#endif

int main()
{
	vector<int>a{ 2,2,5,1,3 };
	int left = 0;
	int right = 4;
	QuckSort(left, right, a);

	for (auto &i : a)
	{
		cout << i << ' ';
	}
	cout << endl;
	system("pause");
	return 0;
}