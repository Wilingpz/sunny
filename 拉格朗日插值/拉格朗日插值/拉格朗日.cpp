#include<cstdlib>
#include<iostream>
using namespace std;
//预先定义插值节点的个数为1000个
//根据控制台输入的个数num从而确定插值节点的个数
const int N = 1000;

//arrX[N],arrY[N]分别存放的是插值节点(Xi,Yi)中的Xi,Yi
//参数n为插值节点的个数，而参数x为待求解的插值节点的X值
float Lagrange(float arrX[], float arrY[], int n, float x)
{
	//函数返回值为求解出来的插值节点x对应的y值
		//注意整个过程涉及的变量，除了循环变量为int外，其他均为float
	float yResult = 0.0;

	//LValue[N]存放的是每次求解的插值基函数的通项
	float LValue[N];

	//循环变量k,m
	int k, m;
	//插值基函数中的上下累乘temp1,temp2
	float temp1, temp2;

	for (k = 0; k<n; k++)
	{
		temp1 = 1.0;//分子和分母不能为0，所以初始化为1.0
		temp2 = 1.0;
		for (m = 0; m<n; m++)
		{
			if (m == k)
			{
				continue;
			}
			temp1 *= (x - arrX[m]);//插值公式的分子部分。(x-x1)(x-x2)
			temp2 *= (arrX[k] - arrX[m]);//插值公式的分母部分(x0-x1)(x1-x2)
		}

		LValue[k] = temp1 / temp2;//求出各个分式并保存
	}

	for (int i = 0; i<n; i++)
	{
		yResult += arrY[i] * LValue[i];//求出和
	}

	return yResult;
}

int main()
{
	float arrX[N], arrY[N];
	int num;
	cout << "输入插值节点的个数(小于" << N << "个):";
	cin >> num;

	cout << "\n--接下来输入这些插值节点(先输入X再输入对应的Y)--\n";
	for (int i = 0; i < num; i++)
	{
		cout << "第" << i + 1 << "个节点的X值:";
		cin >> arrX[i];
		cout << "第" << i + 1 << "个节点的Y值:";
		cin >> arrY[i];
	}

	float X;
	cout << "\n--请输入待求解的插值节点的X值--\n";
	cin >> X;

	float Res = Lagrange(arrX, arrY, num, X);
	cout << "\n--插值结果为:" << Res << endl;
	system("pause");
	return 0;
}