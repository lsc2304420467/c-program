#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void game()
{
	char arr[ROWS][COLS] = { 0 };//��Ų��úõ��׵���Ϣ
	char arr1[ROWS][COLS] = { 0 };//��ź��ų����׵���Ϣ
	//��ʼ������
	Initarr(arr, ROWS, COLS, '0');//'0'
	Initarr(arr1, ROWS, COLS, '*');//'*'

	//��ӡһ������
	Displayarr(arr, ROW, COL);
	Displayarr(arr1, ROW, COL);
	//������
	Setarr(arr, ROW,COL);
	/*Displayarr(arr, ROW, COL);*/

	////�Ų���
	Findarr(arr, arr1, ROW, COL);
}
int main()
{
	
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		printmeun();
		printf("��ѡ��-��");
		scanf("%d" ,&input);
		switch (input)
		{
		case 1:
			printf("��ʼɨ����Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("����Ƿ��ַ�������������\n");
			break;
		}
	} while (input);
	return 0;
}