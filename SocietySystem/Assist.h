#pragma once
#include "StudentManage.h"
#include "Manage.h"
#include"ManageLog.h"
#include<io.h>
#include<stdio.h>
#include<windows.h>
#include<conio.h>

//��ʼ��
void MainInit();
//����ָ���ļ�
void FindData();
//�߼�����ӭҳ��
char Welcome0();
//��ͨ����ӭҳ��
char Welcome1();
//��ͨ��Ա��ӭҳ��
char Welcome2();
//�߼�����ӭ���湦��
void Function0();
//��ͨ����ӭ���湦��
void Function1();
//��ͨ��Ա��ӭ���湦��
void Function2();
//���Ź���
void ClubManage();
//����֮��
void ClubFamily();
//����֮��(��Ա)
void ClubFamily2();
//չʾ����������
void ShowClub();
//ѧ������
void StuMan(int);
//��Ա�鿴
void StuMan2(int);
//��½����
int MainFace();
//�߼������½
void RootLog();
//���ع��� ��ʼ���߼������û���������
void PwdInit();
//�˺Ź���
void Users();
//�˺Ź���ӭҳ��
char UsersFace();
//�޸ĸ߼������˺�
void ChangeUsers();
//�����ͨ�����˺�
void AddManage();
//��ʼ����ͨ�����˺���Ϣ
void ManageLogInit();
//��ʾ������ͨ�����˺�
void ShowManage();
//������ͨ�����˺�
void DelectManage();
//��ͨ��Ա��½
void PeoLog();
//��ͨ�����½
void ManLog();
//�˺��������
string MyMd5(string str,int len);
//����
string MyMd5C(string str,int len);
//����̨��ɫ
void m_setColor();