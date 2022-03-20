#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define COUNT 10
void printmeun();

//初始化棋盘的
void Initarr(char arr[ROWS][COLS], int rows, int cols, char set);

//打印棋盘
void Displayarr(char arr[ROWS][COLS], int row, int col);

//布置雷
void Setarr(char arr[ROWS][COLS], int row, int col);
//排查雷
void Findarr(char arr[ROWS][COLS], char arr1[ROWS][COLS], int row, int col);