#include <iostream>
using namespace std;

//创建数组
void CreateArry(int arry[], int len)
{
	cout << "输入数组的元素。。。" << endl;
	//int key;
	for (int i = 0; i < len; i++)
	{
		//cin >> key;
		cin>>arry[i];
	}
}
//直接插入排序
void Inert_Sort(int arry[], int len)
{
	int i, j;
	for (i = 1; i < len; ++i)
	{
		int temp = arry[i];
		for (j = i - 1; j >= 0; --j)
		{
			if (temp < arry[j])
			{
				arry[j + 1] = arry[j];    //在有序列表中比temp值大的元素后羿            
			}
			else { break; }//temp大于有序表中的最后一位则不需要移动
		}
		arry[j + 1] = temp;//跳出内层循环后插入在合适的位置
	}
}

//打印数组
void Print1(int arry[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arry[i] << " ";
	}
	cout << endl;
}



void test01()
{
	int arry[5];
	int len = sizeof(arry) / sizeof(arry[0]);
	CreateArry(arry, len);
	Inert_Sort(arry, len);
	Print1(arry, len);
}

int main1()
{
	test01();

	system("pause");
	return 0;
}