//���Թ�
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int bfs(vector<vector<char>> & map)
{
	struct pos
	{
		int x, y, level;//��ǰ��λ�ú;����Ĳ���
	};
	const int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
	//��ʾ���������ĸ�����
	queue <pos>que;//������ȱ�������������·��
	int m = map.size(), n = map[0].size();
	vector<vector<bool>>visit(m, vector<bool>(n, false));//���߹���·�����б��
	pos start{ 0, 1, 0 }, end{ 9, 8, 0 };//��ʾ��ںͳ���
	que.push(start);
	visit[start.x][start.y] = true;//�������ĵ���λ
	while (!que.empty())
	{
		pos cur = que.front(), next;//����cur��next
		que.pop();//�Ӷ�����ȡ����ǰλ�ý��б�ǣ�ֻҪ���в�Ϊ��
		//�����λ�õ����������ĸ����򣬼���Ҫ�ߵ���һ��
		for (int i = 0; i < 4; i++)
		{
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];
			next.level = cur.level + 1;
			if (next.x == end.x && next.y == end.y)
				//��next�ڳ���λ�ã����ҵ����������߲���level
			{
				return next.level;
			}
			//��������λ����Ч��û���߹�������λ�÷�����У��ڼ���������������
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

