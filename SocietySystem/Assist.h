#pragma once
#include "StudentManage.h"
#include "Manage.h"
#include"ManageLog.h"
#include<io.h>
#include<stdio.h>
#include<windows.h>
#include<conio.h>

//初始化
void MainInit();
//查找指定文件
void FindData();
//高级管理欢迎页面
char Welcome0();
//普通管理欢迎页面
char Welcome1();
//普通会员欢迎页面
char Welcome2();
//高级管理欢迎界面功能
void Function0();
//普通管理欢迎界面功能
void Function1();
//普通会员欢迎界面功能
void Function2();
//社团管理
void ClubManage();
//社团之家
void ClubFamily();
//社团之家(会员)
void ClubFamily2();
//展示所有社团名
void ShowClub();
//学生管理
void StuMan(int);
//会员查看
void StuMan2(int);
//登陆界面
int MainFace();
//高级管理登陆
void RootLog();
//隐藏功能 初始化高级管理用户名和密码
void PwdInit();
//账号管理
void Users();
//账号管理欢迎页面
char UsersFace();
//修改高级管理账号
void ChangeUsers();
//添加普通管理账号
void AddManage();
//初始化普通管理账号信息
void ManageLogInit();
//显示所有普通管理账号
void ShowManage();
//撤销普通管理账号
void DelectManage();
//普通会员登陆
void PeoLog();
//普通管理登陆
void ManLog();
//账号密码加密
string MyMd5(string str,int len);
//解密
string MyMd5C(string str,int len);
//控制台调色
void m_setColor();