//走迷宫
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int bfs(vector<vector<char>> & map)
{
	struct pos
	{
		int x, y, level;//当前的位置和经过的步数
	};
	const int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
	//表示上下左右四个方向
	queue <pos>que;//广度优先遍历，保存所经路径
	int m = map.size(), n = map[0].size();
	vector<vector<bool>>visit(m, vector<bool>(n, false));//对走过的路径进行标记
	pos start{ 0, 1, 0 }, end{ 9, 8, 0 };//表示入口和出口
	que.push(start);
	visit[start.x][start.y] = true;//给经过的点置位
	while (!que.empty())
	{
		pos cur = que.front(), next;//定义cur和next
		que.pop();//从队列里取出当前位置进行标记，只要队列不为空
		//计算该位置的上下左右四个方向，计算要走的下一步
		for (int i = 0; i < 4; i++)
		{
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];
			next.level = cur.level + 1;
			if (next.x == end.x && next.y == end.y)
				//若next在出口位置，已找到并返回所走步数level
			{
				return next.level;
			}
			//否则：若该位置有效且没有走过，将该位置放入队列，在继续其他几个方向
			if (next.x >= 0 && next.x < m && next.y >= 0 && next.y <n &&
				!visit[next.x][next.y] && map[next.x][next.y] == '.')
			{
				que.push(next);
				visit[next.x][next.y] = true;
			}
		}
	}
	return 0;
}





int main()
{
	vector<vector<char>>map(10, vector<char>(10));
	while (cin>>map[0][0])
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (i == 0 && j == 0) continue;
				cin >> map[i][j];
			}
		}
		cout << bfs(map) << endl;
	}
	return 0;
}

