#define _CRT_SECURE_NO_WARNINGS 1
#include"Concst.h"
enum OPtion
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	PRINT
};
int main()
{
	int input;
	Concst con;
	Initcon(&con);//��ʼ��ͨѶ¼
	do
	{
		menu();
		printf("����������Ҫ�Ĺ���");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			//��̬�汾Ҫ����ͨѶ¼
		/*	DestoryCon(&con);*/
			//�ļ���Ӧ���ȱ�����Ϣ���ļ���Ȼ��������
			SaveCon(&con);//������Ϣ
			DestoryCon(&con);
			break;
		case ADD:
			//����˵���Ϣ
			AddInformation(&con);
			break;
		case DEL:
			//ɾ���˵���Ϣ
			DelteInformation(&con);
			break;
		case SEARCH:
			//��ѧ��������һ���˵���Ϣ
			SearchInformation_num(&con);
			break;
		case MODIFY:
			//�޸�ѧ��ָ�����˵���Ϣ
			ModifyInformation_num(&con);
			break;
		case SORT:
			//����ѧ��������
			SORTInformation_num(&con);
			break;
		case PRINT:
			PrintInformation(&con);
			break;
		default:
			break;
		}
	} while (input);

}