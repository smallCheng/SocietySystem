#include "Assist.h"
int main( )
{
	setlocale(LC_ALL,"");
	//界面调色
	//m_setColor();
	MainInit();//初始化
	while(1)
	{
		switch(MainFace())
		{
		case 1:
			PeoLog();  //普通会员登陆
			break;
		case 2:
			ManLog();//普通管理登陆
			break;
		case 3:
			RootLog();//高级管理登陆
			break;
		case 4:
			cout<<"已退出社团管理系统"<<endl;
			return 0;
		case 333:  //隐藏功能 初始化高级管理名和密码
			PwdInit();
			break;
		default:
			cout<<"输入有误，请重新输入："<<endl;
			break;
		}
	}
	return 0;
}