#define _CRT_SECURE_NO_WARNINGS 1
#include"Concst.h"
void menu()
{
	printf("************************************\n");
	printf("****1 添加	2删除*******************\n");
	printf("****3 查询	4修改*******************\n");
	printf("****5 排序	6打印*******************\n");
	printf("****0 退出	************************\n");
	printf("************************************\n");
}
void LoadCon(Concst* con)//加载文件信息进通讯录
{
	FILE* pf = fopen("contact.dat", "r");
	if (pf==NULL)
	{
		perror("LoadCon");
		return;
	}
	//读文件 fread每次最多读count个，如果可以读到count个就返回count,
	// 如果读不到，就返回一个比count小的值，表示读取结束
	PeoInfo tmp = { 0 };
	
	while (fread(&tmp, sizeof(PeoInfo), 1, pf))
	{
		if (con->sz == con->capacity)
		{
			printf("空间不够，增加容量\n");
			PeoInfo* ptr = (PeoInfo*)realloc(con->date, (con->capacity + INC_SZ) * sizeof(PeoInfo));
			if (ptr != NULL)
			{
				con->date = ptr;
				con->capacity += INC_SZ;
				printf("增容成功\n");
			}
			else
			{
				perror("AddInformation");
				printf("增加类型失败");
				return;
			}
		}
		con->date[con->sz] = tmp;
		con->sz++;
	}
	printf("文件导入成功\n");
	//关闭文件
	fclose(pf);
	pf = NULL;
}
void Initcon(Concst* con)
{
	//静态版本
	//con->sz = 0;
	//memset(con->date, 0, sizeof(con->date));//完成通讯录的存储数据的初始化
	
	//动态版本
	con->date= (PeoInfo*)malloc(DEFAULT_SIZE * sizeof(PeoInfo));
	if (con->date==NULL)
	{
		perror("Initcon");
		return;
	}
	con->sz = 0;
	con->capacity = DEFAULT_SIZE;
	//加载文件
	LoadCon(con);
}
//静态版本的增加联系人
//void AddInformation(Concst* con)
//{
//	if (con->sz==con->capacity)
//	{
//		printf("通讯录已经满了，添加失败\n");
//		return;
//	}
//	else
//	{
//		printf("请输入学号->");
//		scanf("%s", con->date[con->sz].num);
//		printf("请输入名字->");
//		scanf("%s", con->date[con->sz].name);
//		printf("请输入性别->");
//		scanf("%s", con->date[con->sz].sex);
//		printf("请输入年龄->");
//		scanf("%d",&( con->date[con->sz].age));
//		printf("请输入电话->");
//		scanf("%s", con->date[con->sz].tele);
//		printf("请输入地址->");
//		scanf("%s", con->date[con->sz].add);
//		con->sz++;
//		printf("信息输入成功\n");
//	}
//}

//动态版本的增加联系人 
void AddInformation(Concst* con)
{
	if (con->sz==con->capacity)
	{
		printf("空间不够，增加容量\n");
		PeoInfo*ptr=(PeoInfo*) realloc(con->date, (con->capacity + INC_SZ) * sizeof(PeoInfo));
		if (ptr!=NULL)
		{
			con->date = ptr;
			con->capacity += INC_SZ;
			printf("增容成功\n");
		}
		else
		{
			perror("AddInformation");
			printf("增加类型失败");
			return;
		}
	}
		//增加一个人的信息
		printf("请输入学号->");
		scanf("%s", con->date[con->sz].num);
		printf("请输入名字->");
		scanf("%s", con->date[con->sz].name);
		printf("请输入性别->");
		scanf("%s", con->date[con->sz].sex);
		printf("请输入年龄->");
		scanf("%d",&( con->date[con->sz].age));
		printf("请输入电话->");
		scanf("%s", con->date[con->sz].tele);
		printf("请输入地址->");
		scanf("%s", con->date[con->sz].add);
		con->sz++;
		printf("信息输入成功\n");
}
void PrintInformation(Concst* con)
{
	printf("%-10s\t%-10s\t%-5s\t%-5s\t%-12s\t%-20s\n", "学号", "姓名", "性别", "年龄", "电话", "地址");
	for (int i = 0; i < con->sz; i++)
	{
		printf("%-10s\t%-10s\t%-5s\t%-5d\t%-12s\t%-20s\n",
										con->date[i].num,
										con->date[i].name,
										con->date[i].sex,
										con->date[i].age,
										con->date[i].tele,
										con->date[i].add);
	}
}
int FindInformation_NUM(Concst* con, char* p)
{
	int i = 0;
	for ( i = 0; i < con->sz; i++)
	{
		if (strcmp(con->date[i].num, p)==0)
		{
			return i;
		}
	}
	return -1;
}
void DelteInformation(Concst* con)
{
	if (con->sz==0)
	{
		printf("通讯录为空，删除失败");
	}
	else
	{
		char numfind[10];
		printf("请输入你要查找学生的学号->");
		scanf("%s", numfind);
		int ret=FindInformation_NUM(con, numfind);
		if (ret == -1)
		{
			printf("通讯录没有这个人，删除失败");
			return;
		}
		else
		{
			for (int i = ret; i < con->sz-1; i++)
			{
				con->date[i] = con->date[i + 1];
			}
			printf("删除成功\n");
			con->sz--;
		}
	}

}
void SearchInformation_num(Concst* con)
{
	printf("请输入你要查找的人的学号");
	char p[10];
	scanf("%s", p);
	int ret = FindInformation_NUM(con, p);
	if (ret==-1)
	{
		printf("查找的人不存在\n");
		return;
	}
	else
	{
		printf("%-10s\t%-10s\t%-5s\t%-5s\t%-12s\t%-20s\n", "学号", "姓名", "性别", "年龄", "电话", "地址");
		printf("%-10s\t%-10s\t%-5s\t%-5d\t%-12s\t%-20s\n",
			con->date[ret].num,
			con->date[ret].name,
			con->date[ret].sex,
			con->date[ret].age,
			con->date[ret].tele,
			con->date[ret].add);
		return;
	}
}
void ModifyInformation_num(Concst* con)
{
	printf("请输入你要修改的人的学号");
	char p[10];
	scanf("%s", p);
	int ret = FindInformation_NUM(con, p);
	if (ret == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}
	else
	{
		printf("请输入要修改的学号->");
		scanf("%s", con->date[ret].num);
		printf("请输入要修改的名字->");
		scanf("%s", con->date[ret].name);
		printf("请输入要修改的性别->");
		scanf("%s", con->date[ret].sex);
		printf("请输入要修改的年龄->");
		scanf("%d", con->date[ret].age);
		printf("请输入要修改的电话->");
		scanf("%s", con->date[ret].tele);
		printf("请输入要修改的地址->");
		scanf("%s", con->date[ret].add);
		return;
	}
}
int sort_num(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->num, ((PeoInfo*)e2)->num);
}
void SORTInformation_num(Concst* con)
{
	int sz = con->sz;
	qsort(con->date, sz, sizeof(con->date[0]), sort_num);
	printf("排序成功\n");
}
void DestoryCon(Concst* con)
{
	free(con->date);
	con->date = NULL;
	con->capacity = 0;
	con->sz = 0;
}
//这样写可以显示我们能看懂的数据，自己写的
//void SaveCon(Concst* con)
//{
//	FILE* pf = fopen("contact.dat", "w");
//	if (pf == NULL)
//	{
//		perror("SaveCon");
//		return;
//	}
//	//写文件
//	fprintf(pf, "%-10s\t%-10s\t%-5s\t%-5s\t%-12s\t%-20s\n", "学号", "姓名", "性别", "年龄", "电话", "地址");
//	for (int i = 0; i < con->sz; i++)
//	{
//		fprintf(pf, "%-10s\t%-10s\t%-5s\t%-5d\t%-12s\t%-20s\n", con->date[i].num,
//			con->date[i].name,
//			con->date[i].sex,
//			con->date[i].age,
//			con->date[i].tele,
//			con->date[i].add);
//	}
//	//关文件
//	fclose(pf);
//	pf = NULL;
//}
void SaveCon(Concst* con)//保存文件
{
	FILE* pf = fopen("contact.dat", "w");
	if (pf == NULL)
	{
		perror("SaveCon");
	}
	//写文件
	int i = 0;
	for (int  i = 0; i < con->sz; i++)
	{
		fwrite(con->date + i, sizeof(PeoInfo), 1, pf);
	}
	//关文件
	fclose(pf);
	pf = NULL;
}