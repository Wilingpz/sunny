#include<iostream>//����һ�������������������������1�ĸ���
using namespace std;
int main()
{
	int num;
	while (cin >> num)//����������������Ϊ0ʱ�Ž���ѭ��������ֱ��return 0
	{
		int i = 0;
		while (num)
		{
			if ((num & 1) == 1)
				i += 1;
			num >>= 1;
		}
		cout << i << endl;
	}
	return 0;
}
