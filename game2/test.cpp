#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void game()
{
	char arr[ROWS][COLS] = { 0 };//存放布置好的雷的信息
	char arr1[ROWS][COLS] = { 0 };//存放好排除的雷的信息
	//初始化棋盘
	Initarr(arr, ROWS, COLS, '0');//'0'
	Initarr(arr1, ROWS, COLS, '*');//'*'

	//打印一下棋盘
	Displayarr(arr, ROW, COL);
	Displayarr(arr1, ROW, COL);
	//布置雷
	Setarr(arr, ROW,COL);
	/*Displayarr(arr, ROW, COL);*/

	////排查雷
	Findarr(arr, arr1, ROW, COL);
}
int main()
{
	
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		printmeun();
		printf("请选择-》");
		scanf("%d" ,&input);
		switch (input)
		{
		case 1:
			printf("开始扫雷游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输出非法字符，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}