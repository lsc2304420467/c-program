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
	Initcon(&con);//初始化通讯录
	do
	{
		menu();
		printf("请输入你需要的功能");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			//动态版本要销毁通讯录
		/*	DestoryCon(&con);*/
			//文件版应该先保存信息进文件，然后再销毁
			SaveCon(&con);//保存信息
			DestoryCon(&con);
			break;
		case ADD:
			//添加人的信息
			AddInformation(&con);
			break;
		case DEL:
			//删除人的信息
			DelteInformation(&con);
			break;
		case SEARCH:
			//用学号来查找一个人的信息
			SearchInformation_num(&con);
			break;
		case MODIFY:
			//修改学号指定的人的信息
			ModifyInformation_num(&con);
			break;
		case SORT:
			//按照学号来排序
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