#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROW 9
#define MAX_COL 9
#define MINE_COUNT 10

void Init(char show_map[MAX_ROW][MAX_COL],char mine_map[MAX_ROW][MAX_COL])
{
	for (int row = 0; row < MAX_ROW; ++row)
	{
		for (int col = 0; col < MAX_COL; ++col)
		{
			show_map[row][col] = '*';
		}
	}
	for (int row = 0; row < MAX_ROW; ++row)
	{
		for (int col = 0; col < MAX_COL; ++col)
		{
			mine_map[row][col] = '0';
		}
	}
	int mine_count = MINE_COUNT;
	while (mine_count > 0)
	{
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (mine_map[row][col] == '1')
		{
			continue;
		}
		mine_map[row][col] = '1';
		--mine_count;
	}
}

void PrintMap(char map[MAX_ROW][MAX_COL])
{
	printf("  |");
	for (int col = 0; col < MAX_COL; ++col)
	{
		printf("%d ", col);
	}
	printf("\n");
	for (int col = 0; col < MAX_COL; ++col)
	{
		printf("- -");
	}
	printf("\n");
	for (int row = 0; row < MAX_ROW; ++row)
	{
		printf(" %d|", row);
		for (int col = 0; col < MAX_COL; ++col)
		{
			printf("%c ", map[row][col]);
		}
		printf("\n");
	}
}
void UpdateShowMap(int row, int col,
	char mine_map[MAX_ROW][MAX_COL],
	char show_map[MAX_ROW][MAX_COL])
{
	int count = 0;
	if (row - 1 >= 0 && col - 1 >= 0
		&& mine_map[row - 1][col - 1] == '1')
	{
		++count;
	}
	if (row - 1 >= 0 && col - 1 >= 0
		&& mine_map[row - 1][col] == '1')
	{
		++count;
	}
	if (row - 1 >= 0 && col + 1 < MAX_COL
		&& mine_map[row - 1][col + 1] == '1')
	{
		++count;
	}
	if (col - 1 >= 0
		&& mine_map[row][col - 1] == '1')
	{
		++count;
	}
	if (col + 1 < MAX_COL && mine_map[row][col + 1] == '1')
	{
		++count;
	}
	if (row + 1 < MAX_ROW && col - 1 >= 0
		&& mine_map[row + 1][col - 1] == '1')
	{
		++count;
	}
	if (row + 1 < MAX_ROW && mine_map[row + 1][col] == '1')
	{
		++count;
	}
	if (row + 1 < MAX_ROW && col + 1 < MAX_COL
		&& mine_map[row + 1][col + 1] == '1')
	{
		++count;
	}
	show_map[row][col] = count + '0';//字符0 是48
}
void Game()
{
	//1.创建两个二维数组作为地图
	char show_map[MAX_ROW][MAX_COL];
	char mine_map[MAX_ROW][MAX_COL];
	//2、对两个地图进行初始化
	Init(show_map, mine_map);
	int blank_count = 0;
	while (1)
	{
		//3、打印地图
		PrintMap(show_map);
		//4.提示玩家输入，并且进行校验
		printf("请输入要翻开的位置(row col): ");
		int row = 0;
		int col = 0;
		scanf("%d %d",&row,&col);
		if (row < 0 || row >= MAX_ROW
			|| col < 0 || col >= MAX_COL)
		{
			printf("输入的坐标非法！\n");
			continue;
		}
		if (show_map[row][col] != '*')
		{
			printf(" 输入的坐标已经被翻开!\n");
			continue;
		}
		//5.判定是否踩雷
		if (mine_map[row][col] == '1')
		{
			printf("很遗憾，踩雷了！\n");
			return;
		}
		++blank_count;
		//判定是否是游戏胜利
		if (blank_count == MAX_ROW * MAX_COL - MINE_COUNT)
		{
			printf("恭喜你扫雷成功！\n");
			return;
		}
		//7.告诉玩家当前位置有几个雷
		UpdateShowMap(row, col, mine_map,show_map);
	}
}
int Menu()
{
	printf("===============\n");   //输入字符时显示退出程序？
	printf(" 1. 开始游戏 \n");
	printf(" 0. 结束游戏 \n");
	printf("===============\n");
	printf("请输入你的选择: ");
		int choice = 0;
		scanf("%d", &choice);
		return choice;
}
int main()
{
	srand((unsigned int)time(0));//从1970年1月1日0时0刻开始作为基准时间，计算当前时间和基准时间的秒数之差  叫做：时间戳
	while (1){
		int choice = Menu();
		if (choice == 1)
		{
			Game();
		}
		else if (choice == 0)
		{
			printf("Goodbye!\n");
			break;
		}
		else
		{
			printf("您的输入有误！\n");
		}

	}
	system("pause");
	return 0;
}