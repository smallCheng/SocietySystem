#include "Manage.h"
#include "StudentManage.h"
void Manage::Init() //初始化
{
	this->Read();
}
char Manage::Menu( )		//菜单
{
	cout<<endl;
	cout<<"*************************************************************"<<endl;
	cout<<"*                          社团管理                         *"<<endl;
	cout<<"*                                                           *"<<endl;
	cout<<"*                      1.添加社团信息                       *"<<endl;
	cout<<"*                      2.修改社团信息                       *"<<endl;
	cout<<"*                      3.删除社团信息                       *"<<endl;
	cout<<"*                      4.查询社团信息                       *"<<endl;
	cout<<"*                      5.打印所有社团                       *"<<endl;
	cout<<"*                      6.返回上一层                         *"<<endl;
	cout<<"*************************************************************"<<endl;
	cout<<endl;
	cout<<"请输入功能键:";
	char choose;
	cin>>choose;
	fflush(stdin);
	cout<<endl<<endl;
	return choose;
}
void Manage::Add( )		//添加社团信息
{
	ManageMessage temp;
	cout<<"请依次输入新社团的信息"<<endl<<endl;
	cout<<"社团ID:";
	cin>>temp.m_id;
	cout<<"社团名:";
	cin>>temp.m_club;
	cout<<"社团属性：";
	cin>>temp.m_natrue;
	temp.m_name="暂无社长";
	
	for(unsigned int i=0;i<m_mes.size();i++)
	{
		if(m_mes[i].m_id==temp.m_id)
		{
			cout<<"会员号已存在!!!"<<endl;
			cout<<"请重新输入会员号:";
			cin>>temp.m_id;
			i--;
		}
	}
	char yn;
	cout<<"确定添加新社团？:是（y）/否（n）?"<<endl;
	cout<<"请输入:";
	cin>>yn;
	fflush(stdin);
	if(yn=='y'||yn=='Y')
	{
		m_mes.push_back(temp);
		Write();
		cout<<"成功添加新社团"<<endl<<endl;
	}
	else
	{
		cout<<"放弃添加新社团"<<endl;
	}
}
void Manage::Change( )		//修改社团信息
{

	string sign;
	cout<<endl;
	cout<<"输入要修改的社团ID:";
	cin>>sign;
	for(unsigned int i=0;i<m_mes.size();i++)
	{
		if(m_mes[i].m_id==sign)
		{
			cout<<endl;
			cout<<"你要修改的社团信息是："<<endl<<endl;
			cout<<"社团ID:"<<m_mes[i].m_id<<endl;
			cout<<"社团名:"<<m_mes[i].m_club<<endl;
			cout<<"社长:"<<m_mes[i].m_name<<endl;
			cout<<"社团属性:"<<m_mes[i].m_natrue<<endl;
			cout<<endl;
			cout<<endl;
			char yn;
			cout<<"是否修改信息:是（y）/否（n）?"<<endl;
			cout<<"请输入：";
			cin>>yn;
			fflush(stdin);
			if(yn=='y'||yn=='Y')
			{
				cout<<"新依次输入社团的新信息"<<endl;
				cout<<"社团新ID：";
				cin>>m_mes[i].m_id;
				cout<<"社团新名:";
				cin>>m_mes[i].m_club;
				cout<<"社团新属性:";
				cin>>m_mes[i].m_natrue;
				cout<<"是否更换或者设置社长:是（y）/否（n）?"<<endl;
				cout<<" 请输入:";
				string yn;
				cin>>yn;
				fflush(stdin);
				if(!strcmp(yn.c_str(),"y"))
				{
					string path=m_mes[i].m_club;
					StudentManage* stu=new StudentManage(path);
					
					stu->Init();
					if(stu->GetVector()->size()==0)
					{
						cout<<"社团暂无成员，无法建立社长"<<endl;
					}
					else
					{

						stu->SearchAll();
						string pp=stu->Proprieter();
						if(pp!="")
						{
							this->m_mes[i].m_name=pp;
						}
						delete stu;
						stu=NULL;
					}


				}
				
				
				this->Write();
				cout<<"更新社团信息完成"<<endl;

			}
			else if(yn=='n'||yn=='N')
			{
				cout<<"已放弃修改"<<endl;
			}
			else
			{
				cout<<"输入有误，放弃修改"<<endl;
			}
		}
	}

}
void Manage::Delete( )		//删除社团信息
{

	string sign;
	cout<<endl;
	cout<<"输入要删除的社团ID:";
	cin>>sign;
	bool flog=false;
	vector<ManageMessage>::iterator it=m_mes.begin();
	for(it;it!=m_mes.end();it++)
	{
		if(it->m_id==sign)
		{
			cout<<endl;
			cout<<"你要删除社团的信息是："<<endl<<endl;
			cout<<"社团ID:"<<it->m_id<<endl;
			cout<<"社团名:"<<it->m_club<<endl;
			{
				string path=it->m_club;
				StudentManage* stu=new StudentManage(path);
				stu->Init();
				string pp=stu->GetProprieter();
				if(pp=="")
				{
					it->m_name="暂无";
					cout<<"社长:"<<it->m_name<<endl;
					it->m_peoples=stu->GetVector()->size();
					cout<<"社团总人数:"<<stu->GetVector()->size()<<endl;
				}
				else
				{
					it->m_name=pp;
					cout<<"社长:"<<it->m_name<<endl;
					it->m_peoples=stu->GetVector()->size();
					cout<<"社团总人数:"<<stu->GetVector()->size()<<endl;
				}
				delete stu;
				stu=NULL;

			}
			cout<<"社团属性:"<<it->m_natrue<<endl;
			cout<<endl;
			flog=true;
			cout<<"是否删除社团"<<it->m_id<<"的信息";
			cout<<"是（y）/否（n）？"<<endl;
			char yn;
			cout<<"请输入:";
			cin>>yn;
			fflush(stdin);
			if(yn=='y'||yn=='Y')
			{
				string pa=it->m_club+".data";
				remove(pa.c_str());
				m_mes.erase(it);
				Write();
				cout<<"成功删除社团"<<endl;
				return;
			}
			else if(yn=='n'||yn=='N')
			{
				cout<<"已放弃删除社员信息"<<endl;
			}
			else
			{
				cout<<"输入有误，放弃删除"<<endl;
			}
		}
	}
	if(flog==false)
	{
		cout<<"没有该社团信息"<<endl;
	}
}
void Manage::Search( )		//查询社团信息
{
	string sign;
	cout<<endl;
	cout<<"输入要查询的社团ID:";
	cin>>sign;
	bool flog=false;
	for(unsigned int i=0;i<m_mes.size();i++)
	{
		if(m_mes[i].m_id==sign)
		{
			cout<<endl;
			cout<<"你要查询社团的信息是："<<endl<<endl;
			cout<<"社团ID:"<<m_mes[i].m_id<<endl;
			cout<<"社团名:"<<m_mes[i].m_club<<endl;
			{
				string path=m_mes[i].m_club;
				StudentManage* stu=new StudentManage(path);
				stu->Init();
					string pp=stu->GetProprieter();
					if(pp=="")
					{
						this->m_mes[i].m_name="暂无";
						cout<<"社长:"<<m_mes[i].m_name<<endl;
						this->m_mes[i].m_peoples=stu->GetVector()->size();
						cout<<"社团总人数:"<<stu->GetVector()->size()<<endl;
					}
					else
					{
						this->m_mes[i].m_name=pp;
						cout<<"社长:"<<m_mes[i].m_name<<endl;
						this->m_mes[i].m_peoples=stu->GetVector()->size();
						cout<<"社团总人数:"<<stu->GetVector()->size()<<endl;
					}
				delete stu;
				stu=NULL;

			}
			cout<<"社团属性:"<<m_mes[i].m_natrue<<endl;
			this->Write();
			cout<<endl;
			flog=true;
		}
	}
	if(flog==false)
	{
		cout<<"没有该社团的信息"<<endl;
	}
}
void Manage::Write( )		//写入文件
{
	ofstream os("ManageMessage.txt",ios::out|ios::trunc);
	if(!os)
	{
		cout<<"打开文件失败"<<endl;
		exit(2);
	}
	os.seekp(0,ios::beg);
	for(unsigned int i=0;i<m_mes.size();i++)
	{
		//cout<<"下标i="<<i<<endl;
		os<<m_mes[i].m_id<<"\t";
		os<<m_mes[i].m_club<<"\t";
		os<<m_mes[i].m_natrue<<"\t";
		os<<m_mes[i].m_name<<"\t";
	}
	os.close();
}
void Manage::Read( )		//从文件中读取
{
	ManageMessage temp;
	ifstream is("ManageMessage.txt",ios::in|ios::app);
	if(!is)
	{
		cout<<"打开文件失败"<<endl;
		exit(1);
	}
	is.seekg(0,ios::end);
	if(0==is.tellg())
	{
		//cout<<is.seekg(0,ios::end)<<endl;
		//cout<<is.tellg()<<endl;
		is.close();
	}
	else
	{

		is.seekg(0,ios::beg);
		while(1)
		{

			is>>temp.m_id;
			is>>temp.m_club;
			is>>temp.m_natrue;
			is>>temp.m_name;
			if(!is.eof())
			{
				m_mes.push_back(temp);
			}
			else
			{
				is.close();
				break;
			}
		}
	}
}
void Manage::SearchAll( ) //打印所有社团信息
{
	cout<<"打印所有部门信息："<<endl<<endl;
	if(m_mes.size()==0)
	{
		cout<<"还没有任何的社团，赶紧创建吧!!!"<<endl;
	}
	else
	{

	for(unsigned int i=0;i<m_mes.size();i++)
	{
		cout<<endl;
		cout<<"社团id:"<<m_mes[i].m_id<<endl;
		cout<<"社团名:"<<m_mes[i].m_club<<endl;
		{
			string path=m_mes[i].m_club;
			StudentManage* stu=new StudentManage(path);

			stu->Init();
			string pp=stu->GetProprieter();
			if(pp=="")
			{
				this->m_mes[i].m_name="暂无";
				cout<<"社长:"<<m_mes[i].m_name<<endl;
				this->m_mes[i].m_peoples=stu->GetVector()->size();
				cout<<"社团总人数:"<<stu->GetVector()->size()<<endl;
			}
			else
			{
			
				this->m_mes[i].m_name=pp;
				cout<<"社长:"<<m_mes[i].m_name<<endl;
				this->m_mes[i].m_peoples=stu->GetVector()->size();
				cout<<"社团总人数:"<<stu->GetVector()->size()<<endl;
			}
			delete stu;
			stu=NULL;

		}
		cout<<"社团属性:"<<m_mes[i].m_natrue<<endl;
		this->Write();
		cout<<endl;
	}
	}

}
vector<ManageMessage>& Manage::GetVector()//获取向量
{
	return this->m_mes;
}
Manage::Manage(void)
{
	
}

Manage::~Manage(void)
{
}
