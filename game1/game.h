#pragma once
//这个头文件是用来被引用的，里面定义了需要的符号常量，和相关函数的声明
#include<stdio.h>//在头文件引入这个，在调用这个头文件就不需要再次去调用这个库函数
#include<stdlib.h>//提供随机数的函数
#include<time.h>//提供随机值的
#define ROW 3//定义所需二维数组的列长
#define COW 3//定义所需二维数组的行长
void printCaiDan();//这个函数用来打印菜单
void Initarr(char arr[ROW][COW],int row,int cow);//这个函数用来初始化数组内容都为空格
void printQiPan(char arr[ROW][COW], int row, int cow);//打印棋盘
void PlayerMove(char arr[ROW][COW], int row, int cow);//模拟玩家下棋
void ComputerMove(char arr[ROW][COW],int row,int cow);//模拟电脑下棋
char IsWin(char arr[ROW][COW],int row, int cow);//判断玩家赢还是电脑赢还是平局或者是继续游戏
char IsFull(char arr[ROW][COW], int row, int cow);//判断棋盘是不是已经满了