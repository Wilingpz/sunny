//��Ŀ����:
//��һֻ���ӣ��ӳ������3������ÿ���¶���һֻ���ӣ�
//С���ӳ����������º�ÿ��������һֻ���ӣ�
//�������Ӷ���������ÿ���µ���������Ϊ���٣�
//�������е��������������ϸ��µ����������ϱ����²�����������
//������ǰ��������������֮��
#include<iostream>
using namespace std;
 
int main()
{
	int month;
	while (cin >> month)
	{
		if (month == 1 || month == 2)
		{
			cout << 1 << endl;
		}
		int first = 1;
		int second = 1;
		int sum = 0;
		if (month >= 3)
		{
			for (int i = 3; i <= month; i++)
			{
				sum = first + second;
				first = second;
				second = sum;
			}
			cout << second << endl;
		}	
	}
	system("pause");
	return 0;
}