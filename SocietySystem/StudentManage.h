#pragma once
#include<iostream>
#include<stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include "StudentMessage.h"
using namespace std;
//学生信息管理类
class StudentManage
{
public:
	void Init();		//初始化加载
	char Menu( );		//菜单
	char Menu2( );		//会员菜单
	void Add(vector<string>&);		//添加社员信息
	void Change( );		//修改社员信息
	void Delete( );		//删除社员信息
	void Search( );		//查询社员信息
	void SearchAll();	//打印所有会员信息
	void Write();		//写入文件
	void Read();		//从文件中读取
	string Proprieter();	//设置社长
	void FindProprieter();  //社长查询
	void FindProprieterGg(); //撤销社长
	bool FindProprieterF();	//判断社长是否存在
	string GetProprieter();  //获取社长名
	void Peoples();			//获取社团人数
	vector<StudentMessage>*& GetVector();		//获取向量

	StudentManage(string path);
	~StudentManage(void);
private:
	vector<StudentMessage>* m_mes;
	static int m_num;
	string pathname;
};
