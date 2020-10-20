#include "Assist.h"
//��ͨ������������
vector<ManageLog> managelog;
//�������ų�ԱID
vector<string> files;
//���Ź��������
Manage manages;
//��ʼ����ͨ�����˺���Ϣ
void ManageLogInit()
{
	ifstream is("ManageLog.pwd",ios::in|ios::app);
	if(!is)
	{
		cout<<"����ͨ����Ա�˺��ļ�ʧ��"<<endl;
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
//��ʼ��
void MainInit()
{
	manages.Init();
	ManageLogInit();
	FindData();
}
//��½����
int MainFace()
{
	int pos;
	cout<<"*************************************************************"<<endl;
	cout << "*                      ��ӭʹ�����Ź�����Ϣ                 *" << endl;
	cout << "*                                                           *" << endl;
	cout << "*                         1.��ͨ��Ա��½                    *" << endl;
	cout << "*                         2.��ͨ�����½                    *" << endl;
	cout << "*                         3.�߼������½                    *" << endl;
	cout << "*                         4.�˳�����                        *" << endl;
	cout<<"*************************************************************"<<endl<<endl;
	cout<<"�����룺";
	cin>>pos;
	fflush(stdin);
	return pos;
}

//չʾ����������
void ShowClub()
{
	if(manages.GetVector().size()==0)
	{
		cout<<"��û���κε����ţ��Ͻ�������!!!"<<endl;
	}
	{
		for(unsigned int i=0;i<manages.GetVector().size();i++)
		{
			//file.push_back(manages.GetVector()[i].m_club);
			cout<<"                        "<<i+1<<"."<<manages.GetVector()[i].m_club<<"  "<<endl;
		}
	}
}
//ѧ������
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
			cout<<"��������������"<<endl;
			break;
		}
	}

}
//ѧ������
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
			cout<<"��������������"<<endl;
			break;
		}
	}
}
//����֮��
void ClubFamily()
{
	int pos;
	while(1)
	{
		cout<<"*************************************************************"<<endl;

		ShowClub();
		cout<<"                        88.������һ��                       "<<endl;
		cout<<"*************************************************************"<<endl;

		cout<<"��ѡ��";
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
			cout<<"������������������";
		}
	}
}
//����֮�ң���Ա��
void ClubFamily2()
{
	int pos;
	while(1)
	{
		cout<<"*************************************************************"<<endl;

		ShowClub();
		cout<<"                        88.������һ��                       "<<endl;
		cout<<"*************************************************************"<<endl;

		cout<<"��ѡ��";
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
			cout<<"������������������";
		}
	}

}
//�޸ĸ߼������˺�
void ChangeUsers()
{
	ifstream is("RootLog.pwd",ios::in);
	if(!is)
	{
		cout<<"�򿪸߼������˺��ļ�ʧ�ܣ�����"<<endl;
		exit(0);
	}
	cout<<"�����뵱ǰ������֤:";
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
		cout<<"��֤ʧ�ܣ��޷��޸��˻���Ϣ����"<<endl;
		is.close();
		return;
	}
	is.close();
	cout<<"��֤�ɹ�������"<<endl;
	string name;
	char pwd[7]="";
	char pwd1[7]="";
	ofstream os("RootLog.pwd",ios::out|ios::trunc);
	if(!os)
	{
		cout<<"�򿪸߼������˺��ļ�ʧ��"<<endl;
		exit(0);
	}
	cout<<"���������û�����";
	cin>>name;
cp:
	cout<<"����������λ���룺";
	char p;
	for(int i=0;i<6;i++)
	{
		p=_getch();
		cout<<"*";
		pwd[i]=p;
	}
	cout<<endl;
	cout<<"������������λ���룺";
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
		cout<<"�޸��˺���Ϣ�ɹ���"<<endl;
		os.close();
		return;
	}
	cout<<"������������벻һ�£�����������"<<endl;
	goto cp;

}
//�����ͨ�����˺�
void AddManage()
{
	string name;
	char pwd[7]="";
	char pwd1[7]="";
	ofstream os("ManageLog.pwd",ios::out|ios::app);
	if(!os)
	{
		cout<<"����ͨ�����˺��ļ�ʧ��"<<endl;
		exit(0);
	}
	cout<<"��������ͨ�����û�����";
top:
	cin>>name;
	fflush(stdin);
	for(unsigned int i=0;i<managelog.size();i++)
	{
		if(MyMd5C(managelog[i].m_name,managelog[i].m_name.length())==name)
		{
			cout<<"�˺��Ѵ��ڣ������������˺ţ�";
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
		cout<<"���������ͨ�����˺��Ѵ��ڣ�����������:";
		goto top;
	}
wc:
	cout<<"��������λ���룺";
	char p;
	for(int i=0;i<6;i++)
	{
		p=_getch();
		cout<<"*";
		pwd[i]=p;
	}
	cout<<endl;
	cout<<"����������λ���룺";
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
		cout<<"�����ͨ�����˺ųɹ���"<<endl;
		os.close();
		return;
	}
	cout<<"������������벻һ�£�����������"<<endl;
	goto wc;

}
//��ʾ������ͨ�����˺�
void ShowManage()
{
	if(managelog.size()==0)
	{
		cout<<"û����ͨ�����˺�"<<endl;
		return;
	}
	for(unsigned int i=0;i<managelog.size();i++)
	{
		cout<<MyMd5C(managelog[i].m_name,managelog[i].m_name.length())<<"\t";
		cout<<MyMd5C(managelog[i].m_pwd,managelog[i].m_pwd.length())<<endl;
	}
}
//������ͨ�����˺�
void DelectManage()
{
	cout<<"������Ҫ��������ͨ�����˺�:";
	string name;
	cin>>name;
	fflush(stdin);
	name=MyMd5(name,name.length());
	if(managelog.size()==0)
	{
		cout<<"û����ͨ�����˺ţ�����"<<endl;
		return;
	}
	vector<ManageLog>::iterator it=managelog.begin();
	for(it;it!=managelog.end();it++)
	{
		if(name==it->m_name)
		{
			cout<<"������ͨ�����˺ųɹ�"<<endl;
			managelog.erase(it);

			ofstream os("ManageLog.pwd",ios::out|ios::trunc);
			if(!os)
			{
				cout<<"����ͨ�����˺��ļ�ʧ�ܣ�����"<<endl;
				exit(0);
			}
			if(managelog.size()==0)
			{
				os.close();
				cout<<"û����ͨ�����˺��ˣ�����"<<endl;
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
	cout<<"�����ڸ��˺ţ�����"<<endl;
}
//�˺Ź���
void Users()
{
	while(1)
	{
		switch (UsersFace())
		{
			//�޸ĸ߼������˺ź�����
		case '1':
			ChangeUsers();
			break;
			//�����ͨ�����˺�
		case '2':
			AddManage();
			break;
			//������ͨ�����˺�
		case '3':
			DelectManage();
			break;
			//�鿴������ͨ�����˺�
		case '4':
			ShowManage();
			break;
			//������һ��
		case '5':
			return;
		default:
			cout<<"�����������������"<<endl;
			break;


		}
	}

}
//���Ź���
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
			cout<<"��������������"<<endl;
			break;
		}

	}	
}



//�߼�����ӭ���湦��
void Function0()
{
	while(1)
	{
		switch(Welcome0())
		{

		case '1':
			cout<<"\t\t\t����֮��\t\t"<<endl;
			ClubFamily();
			break;
		case '2':
			//cout<<"\t\t���Ź���------------1\t\t"<<endl;
			ClubManage();
			break;
		case '3':
			Users();//�˺Ź���
			break;
		case '4':
			cout<<"       ���˳���½        "<<endl;
			return;
		default:
			cout<<"�����������������:";
			break;
		}
	}
}

//��ͨ����ӭ���湦��
void Function1()
{
	while(1)
	{
		switch(Welcome1())
		{

		case '1':
			cout<<"\t\t\t����֮��\t\t"<<endl;
			ClubFamily();
			break;
		case '2':
			//cout<<"\t\t���Ź���------------1\t\t"<<endl;
			ClubManage();
			break;
		case '3':
			cout<<"       ���˳���½           "<<endl;
			return;
			break;
		default:
			cout<<"�����������������:";
			break;

		}
	}

}
//��ͨ��Ա��ӭ���湦��
void Function2()
{
while(1)
{
	switch(Welcome2())
	{

	case '1':
		cout<<"\t\t\t����֮��\t\t"<<endl;
		ClubFamily2();
		break;
	case '2':
		return;
		break;
	default:
		cout<<"�����������������:";
		break;

	}
}
}
//�߼�����ӭ����
char Welcome0()
{

	cout<<"*************************************************************"<<endl;
	cout<<"*                    ��ӭʹ�����Ź���ϵͳ                   *"<<endl;
	cout<<"*                                                           *"<<endl;
	cout<<"*                        1.����֮��                         *"<<endl;
	cout<<"*                        2.���Ź���                         *"<<endl;
	cout<<"*                        3.�˺Ź���                         *"<<endl;
	cout<<"*                        4.�˳���½                         *"<<endl;
	cout<<"*************************************************************"<<endl;

	char pos;
	cout<<"������:";
	cin>>pos;
	fflush(stdin);
	return pos;
}

//��ͨ����ӭ����
char Welcome1()
{

	cout<<"*************************************************************"<<endl;
	cout<<"*                   ��ӭʹ�����Ź���ϵͳ                    *"<<endl;
	cout<<"*                                                           *"<<endl;
	cout<<"*                        1.����֮��                         *"<<endl;
	cout<<"*                        2.���Ź���				           *"<<endl;
	cout<<"*                        3.�˳���½                         *"<<endl;
	cout<<"*************************************************************"<<endl;


	char pos;
	cout<<"������:";
	cin>>pos;
	fflush(stdin);
	return pos;
}
//��ͨ��Ա��ӭҳ��
char Welcome2()
{
	cout<<"*************************************************************"<<endl;
	cout<<"*                   ��ӭʹ�����Ź���ϵͳ                    *"<<endl;
	cout<<"*                                                           *"<<endl;
	cout<<"*                        1.����֮��                         *"<<endl;
	cout<<"*                        2.�˳���½                         *"<<endl;
	cout<<"*************************************************************"<<endl;


	char pos;
	cout<<"������:";
	cin>>pos;
	fflush(stdin);
	return pos;

}
//�߼������½
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
		cout<<"�������û�����";
		string name;
		cin>>name;
		fflush(stdin);
		cout<<"��������λ�����룺";
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
			cout<<"               ��½�ɹ�"<<endl;
			break;
		}
		else
		{
			cout<<endl;
			cout<<"�û��������������"<<endl;
			k++;

		}

	}
	if(k<3)
	{
		//���빤������
		Function0();

	}
	else
	{
		cout<<"���λ���������!!!!"<<endl;
		return;
	}

}

//��ͨ�����½
void ManLog()
{
	cout<<endl;
	string name;
	char pwd[7]="";
	int k=0;
	for(int i=0;i<3;i++)
	{
		cout<<"�������û�����";
		cin>>name;
		fflush(stdin);
		cout<<"��������λ�����룺";
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
				cout<<"               ��½�ɹ�"<<endl<<endl;
				Function1();
				return;
			}
		}
		cout<<endl;
		cout<<"�û��������������"<<endl;
		k++;


	}

	cout<<"���λ���������!!!!"<<endl;
	return;

}
//��ͨ��Ա��½
void PeoLog()
{
	cout<<endl;
	for(int i=0;i<3;i++)
	{
		cout<<"�������û�����";
		string name;
		cin>>name;
		fflush(stdin);
		cout<<"��������λ�����룺";
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
					cout<<"               ��½�ɹ�"<<endl;
					//���빤������
					Function2();
					return;
				}
			}
		}
		if(j==false)
		{
			cout<<endl;
			cout<<"�û��������������"<<endl;
		}

	}
		cout<<"���λ���������!!!!"<<endl;
		return;
}
//���ع��� ��ʼ���߼������û���������
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
//�˺Ź������
char UsersFace()
{
	cout<<"*************************************************************"<<endl;
	cout<<"*                          �˺Ź���                         *"<<endl;
	cout<<"*                                                           *"<<endl;
	cout<<"*                  1.�޸ĸ߼������û���������               *"<<endl;
	cout<<"*                  2.�����ͨ�����˺�                       *"<<endl;
	cout<<"*                  3.������ͨ�����˺�                       *"<<endl;
	cout<<"*                  4.�鿴������ͨ�����˺�                   *"<<endl;
	cout<<"*                  5.������һ��                             *"<<endl;
	cout<<"*************************************************************"<<endl;

	char pos;
	cout<<"�����룺";
	cin>>pos;
	fflush(stdin);
	return pos;

}
//����
string MyMd5(string str,int len)
{
	for(int i=0;i<len;i++)
	{
		str[i]+=i;
	}
	return str;
}
//����
string MyMd5C(string str,int len)
{
	for(int i=0;i<len;i++)
	{
		str[i]-=i;
	}
	return str;

}
//����ָ���ļ�
void FindData()
{
	//�ļ����
	long   hFile   =   0;
	//�ļ���Ϣ
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
						cout<<"��.data�ļ�ʧ��"<<endl;
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