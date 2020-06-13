#include<iostream>
#include<vector>
using namespace std;
//考虑当相加结果等于3时
class Board {
public:
	bool checkWon(vector<vector<int> > board) 
	{
		//行
		for (int i = 0; i < 3; i++)
		{
			int sum = 0;
			for (int j = 0; j < 3; j++)
			{
				sum += board[i][j];
			}
			if (sum == 3)
			{
				return true;
			}
		}
		//列
		
		for (int i = 0; i < 3; i++)
		{
			int sum1 = 0;
			for (int j = 0; j < 3; j++)
			{
				sum1 += board[j][i];
			}
			if (sum1 == 3)
			{
				return true;
			}
		}
		//正对角
		int sum2 = 0;
		for (int i = 0; i < 3; i++)
		{
			sum2 += board[i][i];
		}
		//反对角
		int sum3 = 0;
		sum3 = board[2][0] + board[1][2] + board[0][2];
		if (sum3 == 3 || sum2 == 3)
		{
			return true;
		}
		return false;
	}
};