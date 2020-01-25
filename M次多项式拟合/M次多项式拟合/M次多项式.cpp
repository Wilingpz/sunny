#include <iostream>
#include<cmath>
#define m 10
#define n 50
using namespace std;

double A[m][m], b[m], Aug[m][m + 1], s;
void Gauss(double A[m + 1][m + 1], double b[m + 1], double x[m + 1], int n2)//定义求解x(i)函数,高斯消元
{
	int i, i1, j, k;
	double Aug[m + 1][m + 2], max, temp, l;
	//构造Aug
	for (i = 0; i<n2; i++)
	{
		for (j = 0; j<n2; j++)
			Aug[i][j] = A[i][j];
		Aug[i][n2] = b[i];
	}

	for (i1 = 0; i1<n2 - 1; i1++)
	{
		max = fabs(Aug[i1][i1]); k = i1;
		for (i = i1; i<n2; i++)
		if (max<fabs(Aug[i][i1]))
		{
			max = fabs(Aug[i][i1]);
			k = i;
		}
		//换行
		for (j = i1; j<n2 + 1; j++)
		{
			temp = Aug[i1][j];
			Aug[i1][j] = Aug[k][j];
			Aug[k][j] = temp;
		}
		//高斯消元，以第i1行为工具行处理一下各行
		for (k = i1 + 1; k<n2; k++)
		{
			l = -Aug[k][i1] / Aug[i1][i1];
			for (j = i1; j<n2 + 1; j++)
				Aug[k][j] = Aug[k][j] + l*Aug[i1][j];
		}
	}
	//回代求解
	x[n2 - 1] = Aug[n2 - 1][n2] / Aug[n2 - 1][n2 - 1];
	for (i = n2 - 2; i >= 0; i--)
	{
		s = 0;
		for (j = i + 1; j<n2; j++)
			s = s + Aug[i][j] * x[j];
		x[i] = (Aug[i][n2] - s) / Aug[i][i];
	}
}
void mafit(double x[n], double y[n], double a[m + 1], int m1, int n1)
//m1为输入点的个数，n1为多项式次数
{
	double A[m + 1][m + 1], b[m + 1], s;
	int i, k, p;
	for (k = 0; k<m1 + 1; k++)
	{
		for (p = 0; p<m1 + 1; p++)
		{
			s = 0;
			for (i = 0; i<n1; i++)
				s = s + pow(x[i], k + p);
			A[k][p] = s;//用A把每一个x输入后得到x直到三次方存起来作为系数矩阵
		}
	
		s = 0;
		for (i = 0; i<n1; i++)
			s = s + pow(x[i], k)*y[i];//将输入的每一个y用b[]存储起来
		b[k] = s;
	}
	Gauss(A, b, a, m1 + 1);//调用Gauss列主元消去法，求解Aa=b
}



int main()
{
	int i, m1, n1;
	double x[n], y[n], a1[m + 1];
	cout << "输入点的个数:";
	cin >> n1;
	cout << endl;
	cout << "输入多项式的次数:";
	cin >> m1;
	cout << "请输入x:";
	for (i = 0; i<n1; i++)
		cin >> x[i];
	cout << endl;
	cout << "请输入y:";
	for (i = 0; i<n1; i++)
		cin >> y[i];
	mafit(x, y, a1, m1, n1);
	cout << "拟合多项式的系数为:";
	for (i = 0; i<m1 + 1; i++)
		cout << a1[i] << "   ";
	cout << endl;
	system("pause");
	return 0;
}
