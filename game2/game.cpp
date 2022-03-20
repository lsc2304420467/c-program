#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void printmeun()
{
	printf("**************************\n");
	printf("**************************\n");
	printf("*** 退出选0, 玩游戏选1 ***\n");
	printf("**************************\n");
	printf("**************************\n");
}
//初始化棋盘的
void Initarr(char arr[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for ( i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			arr[i][j] = set;
		}
	}
}

//打印棋盘
void Displayarr(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("---扫雷游戏开始了---\n");
	for ( i = 0; i <=col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for ( i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}

//布置雷
void Setarr(char arr[ROWS][COLS], int row, int col)
{
	int i;
	int j;
	int count =COUNT;
	while (count)
	{
		i = rand() % 9 + 1;
		j = rand() % 9 + 1;
		if (arr[i][j]=='0')
		{
			arr[i][j] = '1';
			count--;
		}
	}
}
static int get_arr_num(char arr[ROWS][COLS], char arr1[ROWS][COLS], int x, int y)
{
	int num=0;
	for (int  i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			num +=( arr[x+i][y+j] - '0');
		}
	}
	return num;
}

//排查雷
void Findarr(char arr[ROWS][COLS], char arr1[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - COUNT)
	{
		printf("请输入你想查的点的坐标\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (arr[x][y] == '1')
			{
				printf("你踩到雷了，游戏结束");
				Displayarr(arr, ROW, COL);
				break;
			}
			else
			{
				arr1[x][y] = (get_arr_num(arr, arr1, x, y) + '0');
				win++;
				Displayarr(arr1, ROW, COL);
			}
		}
		else
		{
			printf("输入的坐标非法，请重新输入\n");
		}
	}
	if (win== row * col - COUNT)
	{
		printf("恭喜你，排雷成功\n");
		Displayarr(arr, row, col);
	}
}