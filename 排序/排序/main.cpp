#include <iostream>
using namespace std;

//��������
void CreateArry(int arry[], int len)
{
	cout << "���������Ԫ�ء�����" << endl;
	//int key;
	for (int i = 0; i < len; i++)
	{
		//cin >> key;
		cin>>arry[i];
	}
}
//ֱ�Ӳ�������
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
				arry[j + 1] = arry[j];    //�������б��б�tempֵ���Ԫ�غ���            
			}
			else { break; }//temp����������е����һλ����Ҫ�ƶ�
		}
		arry[j + 1] = temp;//�����ڲ�ѭ��������ں��ʵ�λ��
	}
}

//��ӡ����
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