#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void printCaiDan()
{
	printf("**********************************************\n");
	printf("*************玩游戏输入1,退出输入0************\n");
	printf("**********************************************\n");
	printf("**********************************************\n");
}
void Initarr(char arr[ROW][COW], int row, int cow)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < cow; j++)
		{
			arr[i][j] = ' ';
		}
	}
}
void printQiPan(char arr[ROW][COW], int row, int cow)
{
	/*int i = 0;
	for ( i = 0; i <row; i++)
	{
		printf(" %c | %c | %c \n", arr[i][0], arr[i][1], arr[i][2]);
		if (i<row-1)
		{
			printf("---|---|---\n");
		}
	}*/
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < cow; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j < cow - 1)
			{
				printf("|");
			}

		}
		printf("\n");
		if (i<row-1)
		{

		int j = 0;
		for ( j = 0; j < cow; j++)
		{
			printf("---");
			if (j<cow-1)
			{
				printf("|");
			}
		}
		printf("\n");
		}
	}
}
void PlayerMove(char arr[ROW][COW], int row, int cow)
{
	int i = 0;
	int j = 0;
	printf("玩家开始下棋\n");
	while (1)
	{
		printf("请输入你想下棋的坐标——>\n");
		scanf("%d%d", &i, &j);
		if (i >= 1 && j >= 1 && i <= row && j <= cow)
		{
			if (arr[i - 1][j - 1] == ' ')
			{
				arr[i - 1][j - 1] = '*';
				break;
			}
			else
			{
				printf("这个坐标已经被占用，请重新输入\n");
			}

		}
		else
		{
			printf("输入坐标非法，请重新输入\n");
		}
	}
}
void ComputerMove(char arr[ROW][COW], int row, int cow)
{
	int i = 0;
	int j = 0;
	printf("电脑开始下棋\n");
	while (1)
	{
		i = rand() % ROW;
		j = rand() % COW;
		if (arr[i ][j ] == ' ')
		{
			arr[i ][j ] = '#';
			break;
		}
	}
}
char IsFull(char arr[ROW][COW], int row, int cow)
{
	int i = 0;
	int j = 0;
	for ( i = 0; i <row; i++)
	{
		for ( j = 0; j < cow; j++)
		{
			if (arr[i][j] == ' ')
			{
				return 'C';
			}
		}
	}
	return 'P';
}
char IsWin(char arr[ROW][COW], int row, int cow)
{
	int i = 0;
	int j = 0;
	for ( i = 0; i < row; i++)//判断三行
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ')
		{
			return arr[i][0];
		}
	}
	for (i = 0; i < cow; i++)//判断三列
	{
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != ' ')
		{
			return arr[0][i];
		}
	}
	if (arr[0][0] == arr[1][1] && arr[2][2] == arr[1][1] && arr[1][1] != ' ')//判断左对角线
	{
		return arr[1][1];
	}
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] != ' ')//判断右对角线
	{
		return arr[1][1];
	}
	//判断平局
	char full=IsFull(arr, cow, row);//判断是否棋盘是否满了
	return full;
	//这个算法非常低级，只能实现简单的三子棋，不能实现更大的五子棋，需要学习算法来完成
}