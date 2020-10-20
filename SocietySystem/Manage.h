#pragma once
#include<iostream>
#include<stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include "ManageMessage.h"
using namespace std;

//社团管理类
class Manage
{
public:
	void Init( );		//初始化加载
	char Menu( );		//菜单
	void Add();		//添加社团信息
	void Change( );		//修改社团信息
	void Delete( );		//删除社团信息
	void Search( );		//查询社团信息
	void SearchAll();	//打印所有社团信息
	void Write( );		//写入文件
	void Read( );		//从文件中读取
	Manage(void);
	~Manage(void);
	vector<ManageMessage>& GetVector();//获取向量
private:
	vector<ManageMessage> m_mes;
};
