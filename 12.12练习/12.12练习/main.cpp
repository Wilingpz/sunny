//С�����ڹ�˾Ҫ�����ս�����С��ǡ�û������߸�����
//��Ҫ�ڹ�˾����ϲ���һ���齱��Ϸ����Ϸ��һ��6 * 6�������Ͻ��У�
//�������36����ֵ���ȵ����ÿ��С���������������һ�����
//����Ҫ�����Ͻǿ�ʼ��Ϸ��ÿ��ֻ�����»��������ƶ�һ�����������½�ֹͣ��
//һ·�ϵĸ����������С�������õ��������һ���㷨ʹС���õ���ֵ��ߵ����
//����һ��6 * 6�ľ���board������ÿ��Ԫ��Ϊ��Ӧ���ӵ������ֵ, 
//���Ͻ�Ϊ[0, 0], �뷵���ܻ�õ�����ֵ����֤ÿ�������ֵ����100С��1000��

#include<iostream>
#include<algorithm>
#include<vector>//���������ߵ������
using namespace std;

class Bonus 
{
public:
	int getMost(vector<vector<int> > board) 
	{
		//����m*n��С����,m��n��
		int length = board.size();//board[0]��board[m]
		int width = board[0].size();//board[0][0]��board[0][n]
		vector<vector<int> > value;//����洢ÿһ�������ֵ
		for (int i = 0; i < length; i++)
		{
			vector<int>temp(width, 0);//��ʼ�����value
			value.push_back(temp);
		}
		value[0][0] = board[0][0];
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (i == 0 && j == 0)
				{
					continue;//����ʼ�㣬�������ֵ����board[0][0]
				}
				 if (i == 0)//����ǵ�һ�У���j������0��
					//����������ӵ������һ����������ߣ������������ߣ�
				{
					value[i][j] = value[i][j - 1] + board[i][j];//�ҵ�ǰһ��
					//���Ӽ������Լ���ֵ
				}
				else if (j == 0)//����ǵ�һ�еĸ��ӣ���ôһ���������ߵ�
				{
					value[i][j] = value[i - 1][j] + board[i][j];
				}
				else//���������������Դ���������Ҳ���Դ���������ѡ�����ļ���
				{
					value[i][j] = max(value[i][j - 1], value[i - 1][j]) + board[i][j];
				}
			}
		}
		return value[length- 1][width - 1];
	}
};
