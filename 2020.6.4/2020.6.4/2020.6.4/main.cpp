#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	// ע����������һ��ֵ���Ǵ���Խ�������ıȽϣ�����ο�����Ľ���˼·
	vector<int> a;
	a.resize(n + 1);
	a[n] = 0;
	//��������
	int i = 0;
	for (i = 0; i < n; ++i)
		cin >> a[i];
	i = 0;
	int count = 0;
	while (i < n)
	{
		// �ǵݼ�������
		if (a[i] < a[i + 1])
		{
			while (i < n && a[i] <= a[i + 1])
				i++;
			count++;
			i++;
		}
		else if (a[i] == a[i + 1])
		{
			i++;
		}
		else // �ǵ���������
		{
			while (i < n && a[i] >= a[i + 1])
				i++;
			count++;
			i++;
		}
	}
	cout << count << endl;
	return 0;
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int>temp(n+1);
		//temp.resize(n+1);
		temp[n] = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> temp[i];
		}
		int i = 0;
		int count = 0;
		while (i < n )
		{
			if (temp[i] > temp[i + 1])
			{
				while (temp[i] >= temp[i + 1] && i < n)
				{
					++i;
				}
				count++;
				++i;
			}
			else if (temp[i] == temp[i + 1])
			{
				++i;
			}
			else 
			{
				while (temp[i] <= temp[i + 1] && i < n)
				{
					++i;
				}
				count++;
				i++;
			}
		}
		cout << count << endl;
		system("pause");
	}
	return 0;
}