#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void printmeun()
{
	printf("**************************\n");
	printf("**************************\n");
	printf("*** �˳�ѡ0, ����Ϸѡ1 ***\n");
	printf("**************************\n");
	printf("**************************\n");
}
//��ʼ�����̵�
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

//��ӡ����
void Displayarr(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("---ɨ����Ϸ��ʼ��---\n");
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

//������
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

//�Ų���
void Findarr(char arr[ROWS][COLS], char arr1[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - COUNT)
	{
		printf("�����������ĵ������\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (arr[x][y] == '1')
			{
				printf("��ȵ����ˣ���Ϸ����");
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
			printf("���������Ƿ�������������\n");
		}
	}
	if (win== row * col - COUNT)
	{
		printf("��ϲ�㣬���׳ɹ�\n");
		Displayarr(arr, row, col);
	}
}