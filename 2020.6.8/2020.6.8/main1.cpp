#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int w, h;
	while (cin >> w >> h)
	{
		vector<vector<int>> map;
		map.resize(w);//����ռ�
		for (auto &i : map)
		{
			i.resize(h, 1);//��ÿ��λ����1
		}
		int count = 0;
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < h; j++)
			{
				if (map[i][j] == 1)//����ŷ�����ԭ���ò��ܷŵ���ĵط���0
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