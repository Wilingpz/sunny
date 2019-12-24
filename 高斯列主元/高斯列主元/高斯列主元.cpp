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
	cout << "请输入未知量个数n" << endl;
	cin >> n;
	if (n > M)
	{
		cout << "请重新定义符号常量M的值" << endl;
	}
	for (i = 0; i < n; i++)
	{
		cout << "请输入A的" << i + 1 << "行";
		for (j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}

	cout << "请输入b:";
	for (i = 0; i < n; i++)
	{

		cin >> b[i];
	}
	Gauss(A, b, x, n);
	cout << "输出结果：";
	for (i = 0; i < n; i++)
	{
		cout << x[i] << " ";
	}
	system("pause");
	return 0;
}

double A[M][M], b[M][M], Mat[M][M + 1], s;//定义全局变量
void Gauss(double A[M][M], double b[M], double x[M], int n)
{
	int i, i1, j, k;
	double Mat[M][M + 1], max, temp, l;
	//构造Mat矩阵
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			Mat[i][j] = A[i][j];
			Mat[i][n] = b[i];
		}
	}
	//找列主元
	for (i1 = 0; i1 < n - 1; i1++)
	{
		max = fabs(Mat[i1][i1]);//fabs(double x)取双精度数的绝对值
		k = i1;//用来记录最大列主元所在行的
		for (i = i1; i < n; i++)
		{
			if (max < fabs(Mat[i][i1]))
			{
				max = fabs(Mat[i][i1]);
				k = i;
			}
		}
		for (j = i1; j < n + 1; j++)//交换
		{
			temp = Mat[i1][j];
			Mat[i1][j] = Mat[k][j];
			Mat[k][j] = temp;
		}
		//高斯消元，以第i1行为工具行处理以下各行
		for (k = i1 + 1; k < n; k++)//这里的k表示的是行
		{
			l = Mat[k][i1] / Mat[i1][i1];
			for (j = i1; j < n + 1; j++)//这里的j表示的是列
			{
				Mat[k][j] = Mat[k][j] - l*Mat[i1][j];//给系数矩阵进行变换
			}

		}
	}
	//回代求解
	x[n - 1] = Mat[n - 1][n] / Mat[n - 1][n - 1];//矩阵最后一行直接回代求解，用b/x[n-1]
	for (i = n - 2; i >= 0; i--)//矩阵最后一行之前的回代求解
	{
		s = 0;
		for (j = i + 1; j < n; j++)
		{
			s = s + (Mat[i][j] * x[j]);//算出已知项的值
			x[i] = (Mat[i][n] - s) / Mat[i][i];//b减去已知项的值再计算未知项
		}
	}
}

