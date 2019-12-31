#include<cstdlib>
#include<iostream>
using namespace std;
//Ԥ�ȶ����ֵ�ڵ�ĸ���Ϊ1000��
//���ݿ���̨����ĸ���num�Ӷ�ȷ����ֵ�ڵ�ĸ���
const int N = 1000;

//arrX[N],arrY[N]�ֱ��ŵ��ǲ�ֵ�ڵ�(Xi,Yi)�е�Xi,Yi
//����nΪ��ֵ�ڵ�ĸ�����������xΪ�����Ĳ�ֵ�ڵ��Xֵ
float Lagrange(float arrX[], float arrY[], int n, float x)
{
	//��������ֵΪ�������Ĳ�ֵ�ڵ�x��Ӧ��yֵ
		//ע�����������漰�ı���������ѭ������Ϊint�⣬������Ϊfloat
	float yResult = 0.0;

	//LValue[N]��ŵ���ÿ�����Ĳ�ֵ��������ͨ��
	float LValue[N];

	//ѭ������k,m
	int k, m;
	//��ֵ�������е������۳�temp1,temp2
	float temp1, temp2;

	for (k = 0; k<n; k++)
	{
		temp1 = 1.0;//���Ӻͷ�ĸ����Ϊ0�����Գ�ʼ��Ϊ1.0
		temp2 = 1.0;
		for (m = 0; m<n; m++)
		{
			if (m == k)
			{
				continue;
			}
			temp1 *= (x - arrX[m]);//��ֵ��ʽ�ķ��Ӳ��֡�(x-x1)(x-x2)
			temp2 *= (arrX[k] - arrX[m]);//��ֵ��ʽ�ķ�ĸ����(x0-x1)(x1-x2)
		}

		LValue[k] = temp1 / temp2;//���������ʽ������
	}

	for (int i = 0; i<n; i++)
	{
		yResult += arrY[i] * LValue[i];//�����
	}

	return yResult;
}

int main()
{
	float arrX[N], arrY[N];
	int num;
	cout << "�����ֵ�ڵ�ĸ���(С��" << N << "��):";
	cin >> num;

	cout << "\n--������������Щ��ֵ�ڵ�(������X�������Ӧ��Y)--\n";
	for (int i = 0; i < num; i++)
	{
		cout << "��" << i + 1 << "���ڵ��Xֵ:";
		cin >> arrX[i];
		cout << "��" << i + 1 << "���ڵ��Yֵ:";
		cin >> arrY[i];
	}

	float X;
	cout << "\n--����������Ĳ�ֵ�ڵ��Xֵ--\n";
	cin >> X;

	float Res = Lagrange(arrX, arrY, num, X);
	cout << "\n--��ֵ���Ϊ:" << Res << endl;
	system("pause");
	return 0;
}