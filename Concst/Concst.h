#pragma once
//�汾1��̬�汾
//1ͨѶ¼�ܴ��1000���˵���Ϣ
//2ÿ���˵���Ϣ��ѧ��+����+�Ա�+����+�绰+��ַ
//3�����˵���Ϣ
//4ɾ���˵���Ϣ
//5�޸�ָ������Ϣ
//6����ָ����
//7��ͨѶ¼��ѧ������

//�汾�� ��̬�汾
//���ھ�̬�汾ÿ�ζ�����1000���ռ䣬�����ò��������Իᵼ���ڴ��˷�
//�ڶ�̬�ڴ������ٿռ䣬һ��ʼֻ����3����С�Ŀռ�
//���ռ����ˣ�����2����Ϣ

//�汾�� �ļ��汾
//��ͨѶ¼�˳���ʱ�򣬽���Ϣд���ļ�
//��ͨѶ¼��ʼ����ʱ�򣬼����ļ�����Ϣ��ͨѶ¼��
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_NAME 10
#define MAX_NUM 10
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADD 20
#define MAX 1000
#define DEFAULT_SIZE 3
#define INC_SZ 2
typedef struct PeoInfo
{
	char num[MAX_NUM];//ѧ�� Ψһ��ʶ��
	char name[MAX_NAME];//����
	char sex[MAX_SEX];//�Ա�
	int age;//����
	char tele[MAX_TELE];//�绰
	char add[MAX_ADD];//��ַ

}PeoInfo;
typedef struct Concst
{
	//��̬�汾
	//	int sz;//��ʾ����ͨѶ¼���ж��ٸ��˵���Ϣ
	//	PeoInfo date[MAX];//��ŷŽ����˵���Ϣ
	//��̬�汾
	int sz;
	PeoInfo* date;
	int capacity;
};
void menu();
void Initcon(Concst* con);
void AddInformation(Concst *con);
void PrintInformation(Concst* con);
void DelteInformation(Concst* con);
int FindInformation_NUM(Concst* con, char* p);
void SearchInformation_num(Concst* con);
void ModifyInformation_num(Concst *con);
void SORTInformation_num(Concst* con);
void DestoryCon(Concst* con);
void SaveCon(Concst* con);
void LoadCon(Concst* con);