#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void game()
{
	char arr[ROW][COW];//定义所需要存储棋盘数据的空间
	Initarr(arr,ROW,COW);//将这个数组的内容都初始化为空格
	printQiPan(arr, ROW, COW);//将棋盘打印出来
	char ret = 0;
	while (1)
	{
		PlayerMove(arr, ROW, COW);//这个函数模拟玩家下棋
		printQiPan(arr, ROW, COW);//打印棋盘
		 ret=IsWin(arr, ROW, COW);
		if (ret!='C')
		{
			break;
		}
		ComputerMove(arr, ROW, COW);//模拟电脑下棋
		printQiPan(arr, ROW, COW);//打印棋盘
		ret = IsWin(arr, ROW, COW);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret== '*')
	{
		printf("玩家胜利\n");
		printQiPan(arr, ROW, COW);//将棋盘打印出来
	}
	 if (ret == '#')
	{
		printf("电脑胜利\n");
		printQiPan(arr, ROW, COW);//将棋盘打印出来
	}
	 if (ret=='P')
	{
		printf("平局\n");
		printQiPan(arr, ROW, COW);//将棋盘打印出来
		
	}

}
int main()
{
	int input=0;
	srand((unsigned int)time(NULL));
	do
	{
		printCaiDan();
		printf("请输入——》");
		scanf("%d", &input);
		switch (input)
			{
			case 1:
				game();
				break;
			case 0:
				printf("结束游戏\n");
				break;
			default:
				printf("输入非法字符，请重新输入\n");
				break;
			}
		
	} while (input);
	
	return 0;
}