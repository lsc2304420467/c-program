#pragma once
//���ͷ�ļ������������õģ����涨������Ҫ�ķ��ų���������غ���������
#include<stdio.h>//��ͷ�ļ�����������ڵ������ͷ�ļ��Ͳ���Ҫ�ٴ�ȥ��������⺯��
#include<stdlib.h>//�ṩ������ĺ���
#include<time.h>//�ṩ���ֵ��
#define ROW 3//���������ά������г�
#define COW 3//���������ά������г�
void printCaiDan();//�������������ӡ�˵�
void Initarr(char arr[ROW][COW],int row,int cow);//�������������ʼ���������ݶ�Ϊ�ո�
void printQiPan(char arr[ROW][COW], int row, int cow);//��ӡ����
void PlayerMove(char arr[ROW][COW], int row, int cow);//ģ���������
void ComputerMove(char arr[ROW][COW],int row,int cow);//ģ���������
char IsWin(char arr[ROW][COW],int row, int cow);//�ж����Ӯ���ǵ���Ӯ����ƽ�ֻ����Ǽ�����Ϸ
char IsFull(char arr[ROW][COW], int row, int cow);//�ж������ǲ����Ѿ�����