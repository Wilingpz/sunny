#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int w, h;
	while (cin >> w >> h)
	{
		vector<vector<int>> map;
		map.resize(w);//申请空间
		for (auto &i : map)
		{
			i.resize(h, 1);//给每个位置置1
		}
		int count = 0;
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < h; j++)
			{
				if (map[i][j] == 1)//根据欧几里得原理让不能放蛋糕的地方置0
				{
					count++;
					if (i + 2 < w)
					{
						map[i + 2][j] = 0;
					}
					if (j + 2 < h)
					{
						map[i][j + 2] = 0;
					}
				}
			}
		}
		cout << count << endl;
		system("pause");
	}
	return 0;
}