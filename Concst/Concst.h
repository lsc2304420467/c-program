#pragma once
//版本1静态版本
//1通讯录能存放1000个人的信息
//2每个人的信息是学号+姓名+性别+年龄+电话+地址
//3增加人的信息
//4删除人的信息
//5修改指定人信息
//6查找指定人
//7将通讯录按学号排序

//版本二 动态版本
//由于静态版本每次都开辟1000个空间，可能用不掉，所以会导致内存浪费
//在动态内存区开辟空间，一开始只开辟3个大小的空间
//当空间满了，增加2个信息

//版本三 文件版本
//当通讯录退出的时候，将信息写入文件
//当通讯录初始化的时候，加载文件的信息进通讯录中
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
	char num[MAX_NUM];//学号 唯一标识的
	char name[MAX_NAME];//姓名
	char sex[MAX_SEX];//性别
	int age;//年龄
	char tele[MAX_TELE];//电话
	char add[MAX_ADD];//地址

}PeoInfo;
typedef struct Concst
{
	//静态版本
	//	int sz;//表示现在通讯录里有多少个人的信息
	//	PeoInfo date[MAX];//存放放进来人的信息
	//动态版本
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