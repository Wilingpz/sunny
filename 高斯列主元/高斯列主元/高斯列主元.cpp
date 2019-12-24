#include <iostream>
#include<cmath>
#include<cstdlib>
#define M 10

using namespace std;


int main()
{
	void Gauss(double A[M][M], double b[M], double x[M], int n);
	int i, j, n;
	double A[M][M], b[M], x[M];
	cout << "������δ֪������n" << endl;
	cin >> n;
	if (n > M)
	{
		cout << "�����¶�����ų���M��ֵ" << endl;
	}
	for (i = 0; i < n; i++)
	{
		cout << "������A��" << i + 1 << "��";
		for (j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}

	cout << "������b:";
	for (i = 0; i < n; i++)
	{

		cin >> b[i];
	}
	Gauss(A, b, x, n);
	cout << "��������";
	for (i = 0; i < n; i++)
	{
		cout << x[i] << " ";
	}
	system("pause");
	return 0;
}

double A[M][M], b[M][M], Mat[M][M + 1], s;//����ȫ�ֱ���
void Gauss(double A[M][M], double b[M], double x[M], int n)
{
	int i, i1, j, k;
	double Mat[M][M + 1], max, temp, l;
	//����Mat����
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			Mat[i][j] = A[i][j];
			Mat[i][n] = b[i];
		}
	}
	//������Ԫ
	for (i1 = 0; i1 < n - 1; i1++)
	{
		max = fabs(Mat[i1][i1]);//fabs(double x)ȡ˫�������ľ���ֵ
		k = i1;//������¼�������Ԫ�����е�
		for (i = i1; i < n; i++)
		{
			if (max < fabs(Mat[i][i1]))
			{
				max = fabs(Mat[i][i1]);
				k = i;
			}
		}
		for (j = i1; j < n + 1; j++)//����
		{
			temp = Mat[i1][j];
			Mat[i1][j] = Mat[k][j];
			Mat[k][j] = temp;
		}
		//��˹��Ԫ���Ե�i1��Ϊ�����д������¸���
		for (k = i1 + 1; k < n; k++)//�����k��ʾ������
		{
			l = Mat[k][i1] / Mat[i1][i1];
			for (j = i1; j < n + 1; j++)//�����j��ʾ������
			{
				Mat[k][j] = Mat[k][j] - l*Mat[i1][j];//��ϵ��������б任
			}

		}
	}
	//�ش����
	x[n - 1] = Mat[n - 1][n] / Mat[n - 1][n - 1];//�������һ��ֱ�ӻش���⣬��b/x[n-1]
	for (i = n - 2; i >= 0; i--)//�������һ��֮ǰ�Ļش����
	{
		s = 0;
		for (j = i + 1; j < n; j++)
		{
			s = s + (Mat[i][j] * x[j]);//�����֪���ֵ
			x[i] = (Mat[i][n] - s) / Mat[i][i];//b��ȥ��֪���ֵ�ټ���δ֪��
		}
	}
}

