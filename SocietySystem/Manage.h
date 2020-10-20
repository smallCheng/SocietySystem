#pragma once
#include<iostream>
#include<stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include "ManageMessage.h"
using namespace std;

//���Ź�����
class Manage
{
public:
	void Init( );		//��ʼ������
	char Menu( );		//�˵�
	void Add();		//���������Ϣ
	void Change( );		//�޸�������Ϣ
	void Delete( );		//ɾ��������Ϣ
	void Search( );		//��ѯ������Ϣ
	void SearchAll();	//��ӡ����������Ϣ
	void Write( );		//д���ļ�
	void Read( );		//���ļ��ж�ȡ
	Manage(void);
	~Manage(void);
	vector<ManageMessage>& GetVector();//��ȡ����
private:
	vector<ManageMessage> m_mes;
};
