#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void game()
{
	char arr[ROW][COW];//��������Ҫ�洢�������ݵĿռ�
	Initarr(arr,ROW,COW);//�������������ݶ���ʼ��Ϊ�ո�
	printQiPan(arr, ROW, COW);//�����̴�ӡ����
	char ret = 0;
	while (1)
	{
		PlayerMove(arr, ROW, COW);//�������ģ���������
		printQiPan(arr, ROW, COW);//��ӡ����
		 ret=IsWin(arr, ROW, COW);
		if (ret!='C')
		{
			break;
		}
		ComputerMove(arr, ROW, COW);//ģ���������
		printQiPan(arr, ROW, COW);//��ӡ����
		ret = IsWin(arr, ROW, COW);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret== '*')
	{
		printf("���ʤ��\n");
		printQiPan(arr, ROW, COW);//�����̴�ӡ����
	}
	 if (ret == '#')
	{
		printf("����ʤ��\n");
		printQiPan(arr, ROW, COW);//�����̴�ӡ����
	}
	 if (ret=='P')
	{
		printf("ƽ��\n");
		printQiPan(arr, ROW, COW);//�����̴�ӡ����
		
	}

}
int main()
{
	int input=0;
	srand((unsigned int)time(NULL));
	do
	{
		printCaiDan();
		printf("�����롪����");
		scanf("%d", &input);
		switch (input)
			{
			case 1:
				game();
				break;
			case 0:
				printf("������Ϸ\n");
				break;
			default:
				printf("����Ƿ��ַ�������������\n");
				break;
			}
		
	} while (input);
	
	return 0;
}