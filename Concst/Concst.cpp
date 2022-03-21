#define _CRT_SECURE_NO_WARNINGS 1
#include"Concst.h"
void menu()
{
	printf("************************************\n");
	printf("****1 ���	2ɾ��*******************\n");
	printf("****3 ��ѯ	4�޸�*******************\n");
	printf("****5 ����	6��ӡ*******************\n");
	printf("****0 �˳�	************************\n");
	printf("************************************\n");
}
void LoadCon(Concst* con)//�����ļ���Ϣ��ͨѶ¼
{
	FILE* pf = fopen("contact.dat", "r");
	if (pf==NULL)
	{
		perror("LoadCon");
		return;
	}
	//���ļ� freadÿ������count����������Զ���count���ͷ���count,
	// ������������ͷ���һ����countС��ֵ����ʾ��ȡ����
	PeoInfo tmp = { 0 };
	
	while (fread(&tmp, sizeof(PeoInfo), 1, pf))
	{
		if (con->sz == con->capacity)
		{
			printf("�ռ䲻������������\n");
			PeoInfo* ptr = (PeoInfo*)realloc(con->date, (con->capacity + INC_SZ) * sizeof(PeoInfo));
			if (ptr != NULL)
			{
				con->date = ptr;
				con->capacity += INC_SZ;
				printf("���ݳɹ�\n");
			}
			else
			{
				perror("AddInformation");
				printf("��������ʧ��");
				return;
			}
		}
		con->date[con->sz] = tmp;
		con->sz++;
	}
	printf("�ļ�����ɹ�\n");
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}
void Initcon(Concst* con)
{
	//��̬�汾
	//con->sz = 0;
	//memset(con->date, 0, sizeof(con->date));//���ͨѶ¼�Ĵ洢���ݵĳ�ʼ��
	
	//��̬�汾
	con->date= (PeoInfo*)malloc(DEFAULT_SIZE * sizeof(PeoInfo));
	if (con->date==NULL)
	{
		perror("Initcon");
		return;
	}
	con->sz = 0;
	con->capacity = DEFAULT_SIZE;
	//�����ļ�
	LoadCon(con);
}
//��̬�汾��������ϵ��
//void AddInformation(Concst* con)
//{
//	if (con->sz==con->capacity)
//	{
//		printf("ͨѶ¼�Ѿ����ˣ����ʧ��\n");
//		return;
//	}
//	else
//	{
//		printf("������ѧ��->");
//		scanf("%s", con->date[con->sz].num);
//		printf("����������->");
//		scanf("%s", con->date[con->sz].name);
//		printf("�������Ա�->");
//		scanf("%s", con->date[con->sz].sex);
//		printf("����������->");
//		scanf("%d",&( con->date[con->sz].age));
//		printf("������绰->");
//		scanf("%s", con->date[con->sz].tele);
//		printf("�������ַ->");
//		scanf("%s", con->date[con->sz].add);
//		con->sz++;
//		printf("��Ϣ����ɹ�\n");
//	}
//}

//��̬�汾��������ϵ�� 
void AddInformation(Concst* con)
{
	if (con->sz==con->capacity)
	{
		printf("�ռ䲻������������\n");
		PeoInfo*ptr=(PeoInfo*) realloc(con->date, (con->capacity + INC_SZ) * sizeof(PeoInfo));
		if (ptr!=NULL)
		{
			con->date = ptr;
			con->capacity += INC_SZ;
			printf("���ݳɹ�\n");
		}
		else
		{
			perror("AddInformation");
			printf("��������ʧ��");
			return;
		}
	}
		//����һ���˵���Ϣ
		printf("������ѧ��->");
		scanf("%s", con->date[con->sz].num);
		printf("����������->");
		scanf("%s", con->date[con->sz].name);
		printf("�������Ա�->");
		scanf("%s", con->date[con->sz].sex);
		printf("����������->");
		scanf("%d",&( con->date[con->sz].age));
		printf("������绰->");
		scanf("%s", con->date[con->sz].tele);
		printf("�������ַ->");
		scanf("%s", con->date[con->sz].add);
		con->sz++;
		printf("��Ϣ����ɹ�\n");
}
void PrintInformation(Concst* con)
{
	printf("%-10s\t%-10s\t%-5s\t%-5s\t%-12s\t%-20s\n", "ѧ��", "����", "�Ա�", "����", "�绰", "��ַ");
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
		printf("ͨѶ¼Ϊ�գ�ɾ��ʧ��");
	}
	else
	{
		char numfind[10];
		printf("��������Ҫ����ѧ����ѧ��->");
		scanf("%s", numfind);
		int ret=FindInformation_NUM(con, numfind);
		if (ret == -1)
		{
			printf("ͨѶ¼û������ˣ�ɾ��ʧ��");
			return;
		}
		else
		{
			for (int i = ret; i < con->sz-1; i++)
			{
				con->date[i] = con->date[i + 1];
			}
			printf("ɾ���ɹ�\n");
			con->sz--;
		}
	}

}
void SearchInformation_num(Concst* con)
{
	printf("��������Ҫ���ҵ��˵�ѧ��");
	char p[10];
	scanf("%s", p);
	int ret = FindInformation_NUM(con, p);
	if (ret==-1)
	{
		printf("���ҵ��˲�����\n");
		return;
	}
	else
	{
		printf("%-10s\t%-10s\t%-5s\t%-5s\t%-12s\t%-20s\n", "ѧ��", "����", "�Ա�", "����", "�绰", "��ַ");
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
	printf("��������Ҫ�޸ĵ��˵�ѧ��");
	char p[10];
	scanf("%s", p);
	int ret = FindInformation_NUM(con, p);
	if (ret == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
		return;
	}
	else
	{
		printf("������Ҫ�޸ĵ�ѧ��->");
		scanf("%s", con->date[ret].num);
		printf("������Ҫ�޸ĵ�����->");
		scanf("%s", con->date[ret].name);
		printf("������Ҫ�޸ĵ��Ա�->");
		scanf("%s", con->date[ret].sex);
		printf("������Ҫ�޸ĵ�����->");
		scanf("%d", con->date[ret].age);
		printf("������Ҫ�޸ĵĵ绰->");
		scanf("%s", con->date[ret].tele);
		printf("������Ҫ�޸ĵĵ�ַ->");
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
	printf("����ɹ�\n");
}
void DestoryCon(Concst* con)
{
	free(con->date);
	con->date = NULL;
	con->capacity = 0;
	con->sz = 0;
}
//����д������ʾ�����ܿ��������ݣ��Լ�д��
//void SaveCon(Concst* con)
//{
//	FILE* pf = fopen("contact.dat", "w");
//	if (pf == NULL)
//	{
//		perror("SaveCon");
//		return;
//	}
//	//д�ļ�
//	fprintf(pf, "%-10s\t%-10s\t%-5s\t%-5s\t%-12s\t%-20s\n", "ѧ��", "����", "�Ա�", "����", "�绰", "��ַ");
//	for (int i = 0; i < con->sz; i++)
//	{
//		fprintf(pf, "%-10s\t%-10s\t%-5s\t%-5d\t%-12s\t%-20s\n", con->date[i].num,
//			con->date[i].name,
//			con->date[i].sex,
//			con->date[i].age,
//			con->date[i].tele,
//			con->date[i].add);
//	}
//	//���ļ�
//	fclose(pf);
//	pf = NULL;
//}
void SaveCon(Concst* con)//�����ļ�
{
	FILE* pf = fopen("contact.dat", "w");
	if (pf == NULL)
	{
		perror("SaveCon");
	}
	//д�ļ�
	int i = 0;
	for (int  i = 0; i < con->sz; i++)
	{
		fwrite(con->date + i, sizeof(PeoInfo), 1, pf);
	}
	//���ļ�
	fclose(pf);
	pf = NULL;
}