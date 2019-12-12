//小东所在公司要发年终奖，而小东恰好获得了最高福利，
//他要在公司年会上参与一个抽奖游戏，游戏在一个6 * 6的棋盘上进行，
//上面放着36个价值不等的礼物，每个小的棋盘上面放置着一个礼物，
//他需要从左上角开始游戏，每次只能向下或者向右移动一步，到达右下角停止，
//一路上的格子里的礼物小东都能拿到，请设计一个算法使小东拿到价值最高的礼物。
//给定一个6 * 6的矩阵board，其中每个元素为对应格子的礼物价值, 
//左上角为[0, 0], 请返回能获得的最大价值，保证每个礼物价值大于100小于1000。

#include<iostream>
#include<algorithm>
#include<vector>//不能往回走的情况下
using namespace std;

class Bonus 
{
public:
	int getMost(vector<vector<int> > board) 
	{
		//看成m*n个小方格,m行n列
		int length = board.size();//board[0]到board[m]
		int width = board[0].size();//board[0][0]到board[0][n]
		vector<vector<int> > value;//用与存储每一步的最大值
		for (int i = 0; i < length; i++)
		{
			vector<int>temp(width, 0);//初始化这个value
			value.push_back(temp);
		}
		value[0][0] = board[0][0];
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (i == 0 && j == 0)
				{
					continue;//在起始点，则其最大值就是board[0][0]
				}
				 if (i == 0)//如果是第一行，且j不等于0，
					//所以这个格子的最大数一定来自其左边（不允许往回走）
				{
					value[i][j] = value[i][j - 1] + board[i][j];//我的前一个
					//格子加上我自己的值
				}
				else if (j == 0)//如果是第一列的格子，那么一定是向下走的
				{
					value[i][j] = value[i - 1][j] + board[i][j];
				}
				else//这里格子里的数可以从上面来，也可以从左面来，选择最大的即可
				{
					value[i][j] = max(value[i][j - 1], value[i - 1][j]) + board[i][j];
				}
			}
		}
		return value[length- 1][width - 1];
	}
};
