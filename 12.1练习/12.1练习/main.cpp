#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int T;
	int n, k;//����������Ƶ�������ϴ�ƵĴ���
	cin >> T;
	while (T)
	{
		cin >> n >> k;//������Ƶ������Լ�ϴ�ƴ��� 
		int sum = 2 * n;
		vector<int>A(sum);
		for (int i = 0; i < sum; i++)//��2n�����ƷŽ�vector������   
		{
			cin >> A[i];
		}
		while (k)//��ϴ�ƴ�������0ʱ����ϴ��
		{
			vector<int>res(A.begin(),A.end());
			for (int i = 0; i < n; i++)
			{
				A[2 * i ] = res[i];
				A[2 * i+1] = res[i + n];
				//�����ǰ��С�ڵ���n���������֣��������´γ��ֵ�λ���� 2*��ǰλ��
				//��֮��Ӧ�ĵ�ǰλ�� + n���������֣�����,�����´γ��ֵ�λ���� 2*��ǰλ�� + 1
			}
			--k;
		}
		for (int i = 0; i <sum-1; i++)
		{
			cout << A[i]<<' ';
		}
		cout << A[sum - 1] << endl;//Ϊ��ʹ���һ���������֮��û�пո�
		--T;
	}
	system("pause");
	return 0;
}