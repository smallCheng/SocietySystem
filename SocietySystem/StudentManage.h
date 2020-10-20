#pragma once
#include<iostream>
#include<stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include "StudentMessage.h"
using namespace std;
//ѧ����Ϣ������
class StudentManage
{
public:
	void Init();		//��ʼ������
	char Menu( );		//�˵�
	char Menu2( );		//��Ա�˵�
	void Add(vector<string>&);		//�����Ա��Ϣ
	void Change( );		//�޸���Ա��Ϣ
	void Delete( );		//ɾ����Ա��Ϣ
	void Search( );		//��ѯ��Ա��Ϣ
	void SearchAll();	//��ӡ���л�Ա��Ϣ
	void Write();		//д���ļ�
	void Read();		//���ļ��ж�ȡ
	string Proprieter();	//�����糤
	void FindProprieter();  //�糤��ѯ
	void FindProprieterGg(); //�����糤
	bool FindProprieterF();	//�ж��糤�Ƿ����
	string GetProprieter();  //��ȡ�糤��
	void Peoples();			//��ȡ��������
	vector<StudentMessage>*& GetVector();		//��ȡ����

	StudentManage(string path);
	~StudentManage(void);
private:
	vector<StudentMessage>* m_mes;
	static int m_num;
	string pathname;
};
