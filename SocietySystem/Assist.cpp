#include "Assist.h"
//普通管理向量容器
vector<ManageLog> managelog;
//所有社团成员ID
vector<string> files;
//社团管理类对象
Manage manages;
//初始化普通管理账号信息
void ManageLogInit()
{
	ifstream is("ManageLog.pwd",ios::in|ios::app);
	if(!is)
	{
		cout<<"打开普通管理员账号文件失败"<<endl;
	}
	is.seekg(0,ios::beg);
	ManageLog ml;
	while(1)
	{
		is>>ml.m_name;
		is>>ml.m_pwd;
		if(is.eof())
		{
			is.close();
			break;
		}
		managelog.push_back(ml);
	}
}
//初始化
void MainInit()
{
	manages.Init();
	ManageLogInit();
	FindData();
}
//登陆界面
int MainFace()
{
	int pos;
	cout<<"*************************************************************"<<endl;
	cout << "*                      欢迎使用社团管理信息                 *" << endl;
	cout << "*                                                           *" << endl;
	cout << "*                         1.普通会员登陆                    *" << endl;
	cout << "*                         2.普通管理登陆                    *" << endl;
	cout << "*                         3.高级管理登陆                    *" << endl;
	cout << "*                         4.退出程序                        *" << endl;
	cout<<"*************************************************************"<<endl<<endl;
	cout<<"请输入：";
	cin>>pos;
	fflush(stdin);
	return pos;
}

//展示所有社团名
void ShowClub()
{
	if(manages.GetVector().size()==0)
	{
		cout<<"还没有任何的社团，赶紧创建吧!!!"<<endl;
	}
	{
		for(unsigned int i=0;i<manages.GetVector().size();i++)
		{
			//file.push_back(manages.GetVector()[i].m_club);
			cout<<"                        "<<i+1<<"."<<manages.GetVector()[i].m_club<<"  "<<endl;
		}
	}
}
//学生管理
void StuMan(int pos)
{
	string clubname=manages.GetVector()[pos].m_club;
	StudentManage* studentmanages=new StudentManage(clubname);
	studentmanages->Init();
	while(1)
	{

		switch(studentmanages->Menu())
		{
		case '1':
			studentmanages->Add(files);
			break;
		case '2':
			studentmanages->Change();
			break;
		case '3':
			studentmanages->Delete();
			break;
		case '4':
			studentmanages->Search();
			break;
		case '5':
			studentmanages->SearchAll( );
			break;
		case '6':
			studentmanages->FindProprieter( );
			break;
		case '7':
			studentmanages->Peoples( );
			break;
		case '8':
			if(studentmanages!=NULL)
			{
				delete studentmanages;
				studentmanages=NULL;
			}
			return;
		default:
			cout<<"输入有误，请重新"<<endl;
			break;
		}
	}

}
//学生管理
void StuMan2(int pos)
{
	string clubname=manages.GetVector()[pos].m_club;
	StudentManage* studentmanages=new StudentManage(clubname);
	studentmanages->Init();
	while(1)
	{
		switch(studentmanages->Menu2())
		{
		
		case '1':
			studentmanages->Search();
			break;
		case '2':
			studentmanages->SearchAll( );
			break;
		case '3':
			studentmanages->FindProprieter( );
			break;
		case '4':
			studentmanages->Peoples( );
			break;
		case '5':
			if(studentmanages!=NULL)
			{
				delete studentmanages;
				studentmanages=NULL;
			}
			return;
		default:
			cout<<"输入有误，请重新"<<endl;
			break;
		}
	}
}
//社团之家
void ClubFamily()
{
	int pos;
	while(1)
	{
		cout<<"*************************************************************"<<endl;

		ShowClub();
		cout<<"                        88.返回上一层                       "<<endl;
		cout<<"*************************************************************"<<endl;

		cout<<"请选择：";
		cin>>pos;
		fflush(stdin);

		int i=manages.GetVector().size();
		if(pos>0&&pos<=i)
		{
			StuMan(pos-1);
		}
		else if(pos==88)
		{
			return;
		}
		else
		{
			cout<<"输入有误，请重新输入";
		}
	}
}
//社团之家（会员）
void ClubFamily2()
{
	int pos;
	while(1)
	{
		cout<<"*************************************************************"<<endl;

		ShowClub();
		cout<<"                        88.返回上一层                       "<<endl;
		cout<<"*************************************************************"<<endl;

		cout<<"请选择：";
		cin>>pos;
		fflush(stdin);

		int i=manages.GetVector().size();
		if(pos>0&&pos<=i)
		{
			StuMan2(pos-1);
		}
		else if(pos==88)
		{
			return;
		}
		else
		{
			cout<<"输入有误，请重新输入";
		}
	}

}
//修改高级管理账号
void ChangeUsers()
{
	ifstream is("RootLog.pwd",ios::in);
	if(!is)
	{
		cout<<"打开高级管理账号文件失败！！！"<<endl;
		exit(0);
	}
	cout<<"请输入当前密码验证:";
	char pwdd[7]="";
	char g;
	for(int i=0;i<6;i++)
	{
		g=_getch();
		cout<<"*";
		pwdd[i]=g;
	}
	cout<<endl;
	
	fflush(stdin);
	string pw;
	is>>pw;
	pw.clear();
	is>>pw;
	string pwdd1=pwdd;
	pwdd1=MyMd5(pwdd1,pwdd1.length());
	if(pwdd1!=pw)
	{
		cout<<"验证失败，无法修改账户信息！！"<<endl;
		is.close();
		return;
	}
	is.close();
	cout<<"验证成功！！！"<<endl;
	string name;
	char pwd[7]="";
	char pwd1[7]="";
	ofstream os("RootLog.pwd",ios::out|ios::trunc);
	if(!os)
	{
		cout<<"打开高级管理账号文件失败"<<endl;
		exit(0);
	}
	cout<<"请输入新用户名：";
	cin>>name;
cp:
	cout<<"请输入新六位密码：";
	char p;
	for(int i=0;i<6;i++)
	{
		p=_getch();
		cout<<"*";
		pwd[i]=p;
	}
	cout<<endl;
	cout<<"请再输入新六位密码：";
	for(int i=0;i<6;i++)
	{
		p=_getch();
		cout<<"*";
		pwd1[i]=p;
	}
	cout<<endl;
	if(!strcmp(pwd,pwd1))
	{
		name=MyMd5(name,name.length());
		string pwd2=pwd;
		pwd2=MyMd5(pwd2,pwd2.length());
		os<<name<<endl<<pwd2<<endl;
		cout<<"修改账号信息成功！"<<endl;
		os.close();
		return;
	}
	cout<<"两次输入的密码不一致，请重新输入"<<endl;
	goto cp;

}
//添加普通管理账号
void AddManage()
{
	string name;
	char pwd[7]="";
	char pwd1[7]="";
	ofstream os("ManageLog.pwd",ios::out|ios::app);
	if(!os)
	{
		cout<<"打开普通管理账号文件失败"<<endl;
		exit(0);
	}
	cout<<"请输入普通管理用户名：";
top:
	cin>>name;
	fflush(stdin);
	for(unsigned int i=0;i<managelog.size();i++)
	{
		if(MyMd5C(managelog[i].m_name,managelog[i].m_name.length())==name)
		{
			cout<<"账号已存在，请输入其他账号：";
			goto top;
		}
	}
	bool k=false;
	for(unsigned int i=0;i<managelog.size();i++)
	{
		if(name==managelog[i].m_name)
		{
			k=true;
		}
	}
	if(k==true)
	{
		cout<<"您输入的普通管理账号已存在，请重新输入:";
		goto top;
	}
wc:
	cout<<"请输入六位密码：";
	char p;
	for(int i=0;i<6;i++)
	{
		p=_getch();
		cout<<"*";
		pwd[i]=p;
	}
	cout<<endl;
	cout<<"请再输入六位密码：";
	for(int i=0;i<6;i++)
	{
		p=_getch();
		cout<<"*";
		pwd1[i]=p;
	}
	cout<<endl;
	if(!strcmp(pwd,pwd1))
	{
		name=MyMd5(name,name.length());
		string pwd2=pwd;
		pwd2=MyMd5(pwd2,pwd2.length());
		os<<name<<endl<<pwd2<<endl;
		ManageLog ml;
		ml.m_name=name;
		ml.m_pwd=pwd2;
		managelog.push_back(ml);
		cout<<"添加普通管理账号成功！"<<endl;
		os.close();
		return;
	}
	cout<<"两次输入的密码不一致，请重新输入"<<endl;
	goto wc;

}
//显示所有普通管理账号
void ShowManage()
{
	if(managelog.size()==0)
	{
		cout<<"没有普通管理账号"<<endl;
		return;
	}
	for(unsigned int i=0;i<managelog.size();i++)
	{
		cout<<MyMd5C(managelog[i].m_name,managelog[i].m_name.length())<<"\t";
		cout<<MyMd5C(managelog[i].m_pwd,managelog[i].m_pwd.length())<<endl;
	}
}
//撤销普通管理账号
void DelectManage()
{
	cout<<"请输入要撤销的普通管理账号:";
	string name;
	cin>>name;
	fflush(stdin);
	name=MyMd5(name,name.length());
	if(managelog.size()==0)
	{
		cout<<"没有普通管理账号！！！"<<endl;
		return;
	}
	vector<ManageLog>::iterator it=managelog.begin();
	for(it;it!=managelog.end();it++)
	{
		if(name==it->m_name)
		{
			cout<<"撤销普通管理账号成功"<<endl;
			managelog.erase(it);

			ofstream os("ManageLog.pwd",ios::out|ios::trunc);
			if(!os)
			{
				cout<<"打开普通管理账号文件失败！！！"<<endl;
				exit(0);
			}
			if(managelog.size()==0)
			{
				os.close();
				cout<<"没有普通管理账号了！！！"<<endl;
				return;
			}

			for(unsigned int i=0;i<managelog.size();i++)
			{

				os<<managelog[i].m_name.c_str()<<endl<<managelog[i].m_pwd.c_str()<<endl;
			}
			os.close();
			return;
		}

	}
	cout<<"不存在该账号！！！"<<endl;
}
//账号管理
void Users()
{
	while(1)
	{
		switch (UsersFace())
		{
			//修改高级管理账号和密码
		case '1':
			ChangeUsers();
			break;
			//添加普通管理账号
		case '2':
			AddManage();
			break;
			//撤销普通管理账号
		case '3':
			DelectManage();
			break;
			//查看所有普通管理账号
		case '4':
			ShowManage();
			break;
			//返回上一层
		case '5':
			return;
		default:
			cout<<"输入错误，请重新输入"<<endl;
			break;


		}
	}

}
//社团管理
void ClubManage()
{

	while(1)
	{
		switch(manages.Menu())
		{
		case '1':
			manages.Add();
			break;
		case '2':
			manages.Change();
			break;
		case '3':
			manages.Delete();
			break;
		case '4':
			manages.Search();
			break;
		case '5':
			manages.SearchAll( );
			break;
		case '6':
			return;
		default:
			cout<<"输入有误，请重新"<<endl;
			break;
		}

	}	
}



//高级管理欢迎界面功能
void Function0()
{
	while(1)
	{
		switch(Welcome0())
		{

		case '1':
			cout<<"\t\t\t社团之家\t\t"<<endl;
			ClubFamily();
			break;
		case '2':
			//cout<<"\t\t社团管理------------1\t\t"<<endl;
			ClubManage();
			break;
		case '3':
			Users();//账号管理
			break;
		case '4':
			cout<<"       已退出登陆        "<<endl;
			return;
		default:
			cout<<"输入错误，请重新输入:";
			break;
		}
	}
}

//普通管理欢迎界面功能
void Function1()
{
	while(1)
	{
		switch(Welcome1())
		{

		case '1':
			cout<<"\t\t\t社团之家\t\t"<<endl;
			ClubFamily();
			break;
		case '2':
			//cout<<"\t\t社团管理------------1\t\t"<<endl;
			ClubManage();
			break;
		case '3':
			cout<<"       已退出登陆           "<<endl;
			return;
			break;
		default:
			cout<<"输入错误，请重新输入:";
			break;

		}
	}

}
//普通会员欢迎界面功能
void Function2()
{
while(1)
{
	switch(Welcome2())
	{

	case '1':
		cout<<"\t\t\t社团之家\t\t"<<endl;
		ClubFamily2();
		break;
	case '2':
		return;
		break;
	default:
		cout<<"输入错误，请重新输入:";
		break;

	}
}
}
//高级管理欢迎界面
char Welcome0()
{

	cout<<"*************************************************************"<<endl;
	cout<<"*                    欢迎使用社团管理系统                   *"<<endl;
	cout<<"*                                                           *"<<endl;
	cout<<"*                        1.社团之家                         *"<<endl;
	cout<<"*                        2.社团管理                         *"<<endl;
	cout<<"*                        3.账号管理                         *"<<endl;
	cout<<"*                        4.退出登陆                         *"<<endl;
	cout<<"*************************************************************"<<endl;

	char pos;
	cout<<"请输入:";
	cin>>pos;
	fflush(stdin);
	return pos;
}

//普通管理欢迎界面
char Welcome1()
{

	cout<<"*************************************************************"<<endl;
	cout<<"*                   欢迎使用社团管理系统                    *"<<endl;
	cout<<"*                                                           *"<<endl;
	cout<<"*                        1.社团之家                         *"<<endl;
	cout<<"*                        2.社团管理				           *"<<endl;
	cout<<"*                        3.退出登陆                         *"<<endl;
	cout<<"*************************************************************"<<endl;


	char pos;
	cout<<"请输入:";
	cin>>pos;
	fflush(stdin);
	return pos;
}
//普通会员欢迎页面
char Welcome2()
{
	cout<<"*************************************************************"<<endl;
	cout<<"*                   欢迎使用社团管理系统                    *"<<endl;
	cout<<"*                                                           *"<<endl;
	cout<<"*                        1.社团之家                         *"<<endl;
	cout<<"*                        2.退出登陆                         *"<<endl;
	cout<<"*************************************************************"<<endl;


	char pos;
	cout<<"请输入:";
	cin>>pos;
	fflush(stdin);
	return pos;

}
//高级管理登陆
void RootLog()
{
	cout<<endl;
	ifstream is("RootLog.pwd",ios::in);
	string name1;
	is>>name1;
	string pwd1;
	is>>pwd1;
	is.close();
	int k=0;
	for(int i=0;i<3;i++)
	{
		cout<<"请输入用户名：";
		string name;
		cin>>name;
		fflush(stdin);
		cout<<"请输入六位数密码：";
		char pwd[7]="";
		char p;
		for(int i=0;i<6;i++)
		{
			p=_getch();
			fflush(stdin);
			pwd[i]=p;
			cout<<"*";
		}
		string pwd2=pwd;
		pwd2=MyMd5(pwd2,pwd2.length());
		name=MyMd5(name,name.length());
		if(pwd1==pwd2&&name==name1)
		{
			cout<<endl<<endl;
			cout<<"               登陆成功"<<endl;
			break;
		}
		else
		{
			cout<<endl;
			cout<<"用户或密码输入错误"<<endl;
			k++;

		}

	}
	if(k<3)
	{
		//进入工作区间
		Function0();

	}
	else
	{
		cout<<"三次机会已用完!!!!"<<endl;
		return;
	}

}

//普通管理登陆
void ManLog()
{
	cout<<endl;
	string name;
	char pwd[7]="";
	int k=0;
	for(int i=0;i<3;i++)
	{
		cout<<"请输入用户名：";
		cin>>name;
		fflush(stdin);
		cout<<"请输入六位数密码：";
		char pwd[7]="";
		char p;
		for(int i=0;i<6;i++)
		{
			p=_getch();
			fflush(stdin);
			pwd[i]=p;
			cout<<"*";
		}
		//cout<<managelog.size()<<endl;
		string pwd1=pwd;
		pwd1=MyMd5(pwd1,pwd1.length());
		name=MyMd5(name,name.length());
		for(unsigned int i=0;i<managelog.size();i++)
		{
			//cout<<managelog[i].m_pwd.c_str()<<"\t"<<managelog[i].m_name<<endl;
			if(pwd1==managelog[i].m_pwd&&name==managelog[i].m_name)
			{
				cout<<endl<<endl;
				cout<<"               登陆成功"<<endl<<endl;
				Function1();
				return;
			}
		}
		cout<<endl;
		cout<<"用户或密码输入错误"<<endl;
		k++;


	}

	cout<<"三次机会已用完!!!!"<<endl;
	return;

}
//普通会员登陆
void PeoLog()
{
	cout<<endl;
	for(int i=0;i<3;i++)
	{
		cout<<"请输入用户名：";
		string name;
		cin>>name;
		fflush(stdin);
		cout<<"请输入六位数密码：";
		char pwd[7]="";
		char p;
		for(int i=0;i<6;i++)
		{
			p=_getch();
			fflush(stdin);
			pwd[i]=p;
			cout<<"*";
		}
		cout<<endl;
		bool j=false;
		if(!strcmp(pwd,"123456"))
		{
			for(unsigned int f=0;f<files.size();f++)
			{
				if(name==files[f])
				{
					j=true;
					cout<<endl;
					cout<<"               登陆成功"<<endl;
					//进入工作区间
					Function2();
					return;
				}
			}
		}
		if(j==false)
		{
			cout<<endl;
			cout<<"用户或密码输入错误"<<endl;
		}

	}
		cout<<"三次机会已用完!!!!"<<endl;
		return;
}
//隐藏功能 初始化高级管理用户名和密码
void PwdInit()
{
	ofstream os("RootLog.pwd",ios::out|ios::trunc);
	string name="admin";
	string pwd="666666";
	name=MyMd5(name,name.length());
	pwd=MyMd5(pwd,pwd.length());

	os<<name<<endl<<pwd<<endl;
	os.close();
}
//账号管理界面
char UsersFace()
{
	cout<<"*************************************************************"<<endl;
	cout<<"*                          账号管理                         *"<<endl;
	cout<<"*                                                           *"<<endl;
	cout<<"*                  1.修改高级管理用户名和密码               *"<<endl;
	cout<<"*                  2.添加普通管理账号                       *"<<endl;
	cout<<"*                  3.撤销普通管理账号                       *"<<endl;
	cout<<"*                  4.查看所有普通管理账号                   *"<<endl;
	cout<<"*                  5.返回上一层                             *"<<endl;
	cout<<"*************************************************************"<<endl;

	char pos;
	cout<<"请输入：";
	cin>>pos;
	fflush(stdin);
	return pos;

}
//加密
string MyMd5(string str,int len)
{
	for(int i=0;i<len;i++)
	{
		str[i]+=i;
	}
	return str;
}
//解密
string MyMd5C(string str,int len)
{
	for(int i=0;i<len;i++)
	{
		str[i]-=i;
	}
	return str;

}
//查找指定文件
void FindData()
{
	//文件句柄
	long   hFile   =   0;
	//文件信息
	struct _finddata_t fileinfo;
	string path=".";
	string pathName,exdName,exd="data";

	if (0 != strcmp(exd.c_str(), ""))
	{
		exdName = "\\*." + exd;
	}
	else
	{
		exdName = "\\*";
	}

	if((hFile = _findfirst(pathName.assign(path).append(exdName).c_str(),&fileinfo)) !=  -1)
	{
		do
		{
				if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)
				{
					//cout<<fileinfo.name<<endl;
					string fd=fileinfo.name;
					ifstream is(fileinfo.name,ios::in);
					if(!is)
					{
						cout<<"打开.data文件失败"<<endl;
						exit(0);
					}
					StudentMessage sm;
					while(1)
					{
						is>>sm.m_id>>sm.m_name>>sm.m_sex>>sm.m_age>>sm.m_profession>>sm.m_grade>>sm.m_club;
						if(is.eof())
						{
							is.close();
							break;
						}
						//cout<<sm.m_id<<sm.m_name<<endl;

						files.push_back(sm.m_id);
					}
					
				}
		}while(_findnext(hFile, &fileinfo)  == 0);
		_findclose(hFile);
	}

}
void m_setColor()
{
	system("color F3");
}