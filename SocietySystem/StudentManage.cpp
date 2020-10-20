#include "StudentManage.h"
int StudentManage::m_num=0;
StudentManage::StudentManage(string path):pathname(path),m_mes(NULL)
{
}

StudentManage::~StudentManage(void)
{
	if(this->m_mes!=NULL)
	{
		delete this->m_mes;
		this->m_mes=NULL;
	}
}
void StudentManage::Init()
{
	this->m_mes=new vector<StudentMessage>;
	this->Read();
}
char StudentManage::Menu( )		//菜单
{
	cout<<endl;
	cout<<"*************************************************************"<<endl;
	cout<<"*                      学生社团管理系统——"<<this->pathname  <<endl;
	cout<<"*                                                           *"<<endl;
	cout<<"*                       1.添加社员信息                      *"<<endl;
	cout<<"*                       2.修改社员信息                      *"<<endl;
	cout<<"*                       3.删除社员信息                      *"<<endl;              
	cout<<"*                       4.查询社员信息                      *"<<endl;
	cout<<"*                       5.打印所有成员                      *"<<endl;
	cout<<"*                       6.社长信息                          *"<<endl;
	cout<<"*                       7.社团人数                          *"<<endl;
	cout<<"*                       8.返回上一层                        *"<<endl;
	cout<<"*************************************************************"<<endl;
	cout<<endl;
	cout<<"请输入功能键:";
	char choose;
	cin>>choose;
	fflush(stdin);
	cout<<endl<<endl;
	return choose;
}

char StudentManage::Menu2( )		//会员菜单
{
	cout<<endl;
	cout<<"*************************************************************"<<endl;
	cout<<"*                      学生社团管理系统——"<<this->pathname  <<endl;
	cout<<"*                                                           *"<<endl;
	cout<<"*                       1.查询社员信息                      *"<<endl;
	cout<<"*                       2.打印所有成员                      *"<<endl;
	cout<<"*                       3.社长信息                          *"<<endl;
	cout<<"*                       4.社团人数                          *"<<endl;
	cout<<"*                       5.返回上一层                        *"<<endl;
	cout<<"*************************************************************"<<endl;
	cout<<endl;
	cout<<"请输入功能键:";
	char choose;
	cin>>choose;
	fflush(stdin);
	cout<<endl<<endl;
	return choose;
}

void StudentManage::Add(vector<string>& files)		//添加社员信息
{
	StudentMessage temp;
	cout<<"请依次输入新社员的信息"<<endl<<endl;
	cout<<"社员会员号:";
	cin>>temp.m_id;
	cout<<"社员名字:";
	cin>>temp.m_name;
	cout<<"社员性别：";
	cin>>temp.m_sex;
	cout<<"社员年龄:";
	cin>>temp.m_age;
	cout<<"社员专业:";
	cin>>temp.m_profession;
	cout<<"社员班级:";
	cin>>temp.m_grade;
	cout<<"社员职务:";
	cin>>temp.m_club;
	if(temp.m_club=="社长")
	{
		if(this->FindProprieterF())
		{
			cout<<"已存在社长，请输入其他职务"<<endl;
			cout<<"社员职务:";
			cin>>temp.m_club;
			if(temp.m_club=="社长")
			{
				cout<<"恶意操作，已返回"<<endl;
				return;
			}

		}
	}
	for(unsigned int i=0;i<m_mes->size();i++)
	{
		if((*m_mes)[i].m_id==temp.m_id)
		{
			cout<<"会员号已存在!!!"<<endl;
			cout<<"请重新输入会员号:";
			cin>>temp.m_id;
			i--;
		}
	}
	m_mes->push_back(temp);
	files.push_back(temp.m_id);
	m_num++;
	Write();
	cout<<"成功添加新成员"<<endl<<endl;
}
void StudentManage::Change( )		//修改社员信息
{
	
	string sign;
	cout<<endl;
	cout<<"输入要修改的社员信息的会员号:";
	cin>>sign;
	for(unsigned int i=0;i<m_mes->size();i++)
	{
		if((*m_mes)[i].m_id==sign)
		{
			cout<<endl;
			cout<<"你要修改的社员信息是："<<endl<<endl;
			cout<<"社员会员号:"<<(*m_mes)[i].m_id<<endl;
			cout<<"社员姓名:"<<(*m_mes)[i].m_name<<endl;
			cout<<"社员性别:"<<(*m_mes)[i].m_sex<<endl;
			cout<<"社员年龄："<<(*m_mes)[i].m_age<<endl;
			cout<<"社员专业:"<<(*m_mes)[i].m_profession<<endl;
			cout<<"社员班级:"<<(*m_mes)[i].m_grade<<endl;
			cout<<"社员职务:"<<(*m_mes)[i].m_club<<endl;
			cout<<endl;
			cout<<endl;
			char yn;
			cout<<"是否修改信息:是（y）/否（n）?"<<endl;
			cin>>yn;
			fflush(stdin);
			if(yn=='y'||yn=='Y')
			{
				cout<<"新依次输入社员的新信息"<<endl;
				cout<<"社员会员号:";
				cin>>(*m_mes)[i].m_id;
				cout<<"社员姓名:";
				cin>>(*m_mes)[i].m_name;
				cout<<"社员性别:";
				cin>>(*m_mes)[i].m_sex;
				cout<<"社员年龄：";
				cin>>(*m_mes)[i].m_age;
				cout<<"社员专业:";
				cin>>(*m_mes)[i].m_profession;
				cout<<"社员班级:";
				cin>>(*m_mes)[i].m_grade;
				cout<<"社员职务:";
				cin>>(*m_mes)[i].m_club;
				if((*m_mes)[i].m_club=="社长")
				{
					if(this->FindProprieterF())
					{
						cout<<"已存在社长，请输入其他职务"<<endl;
						cout<<"社员职务:";
						cin>>(*m_mes)[i].m_club;
						if((*m_mes)[i].m_club=="社长")
						{
							cout<<"恶意操作，已返回"<<endl;
							return;
						}

					}
				}
				Write();
				cout<<"更新社员信息完成"<<endl;

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
void StudentManage::Delete( )		//删除社员信息
{
	
	string sign;
	cout<<endl;
	cout<<"输入要删除的社员的会员号:";
	cin>>sign;
	bool flog=false;
	vector<StudentMessage>::iterator it=m_mes->begin();
	for(it;it!=m_mes->end();it++)
	{
		if(it->m_id==sign)
		{
			cout<<endl;
			cout<<"你要删除的社员信息是："<<endl<<endl;
			cout<<"社员会员号:"<<it->m_id<<endl;
			cout<<"社员姓名:"<<it->m_name<<endl;
			cout<<"社员性别:"<<it->m_sex<<endl;
			cout<<"社员年龄："<<it->m_age<<endl;
			cout<<"社员专业:"<<it->m_profession<<endl;
			cout<<"社员班级:"<<it->m_grade<<endl;
			cout<<"社员职务:"<<it->m_club<<endl;
			cout<<endl;
			flog=true;
			cout<<"是否删除会员"<<it->m_id<<"的信息";
			cout<<"是（y）/否（n）？";
			char yn;
			cin>>yn;
			fflush(stdin);
			if(yn=='y'||yn=='Y')
			{

				m_mes->erase(it);
				Write();
				cout<<"成功删除会员"<<endl;
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
		cout<<"没有该会员号信息"<<endl;
	}
}
void StudentManage::Search( )		//查询社员信息
{
	string sign;
	cout<<endl;
	cout<<"输入要查询的社员的会员号:";
	cin>>sign;
	bool flog=false;
	for(unsigned int i=0;i<m_mes->size();i++)
	{
		if((*m_mes)[i].m_id==sign)
		{
			cout<<endl;
			cout<<"你要查询的社员信息是："<<endl<<endl;
			cout<<"社员会员号:"<<(*m_mes)[i].m_id<<endl;
			cout<<"社员姓名:"<<(*m_mes)[i].m_name<<endl;
			cout<<"社员性别:"<<(*m_mes)[i].m_sex<<endl;
			cout<<"社员年龄："<<(*m_mes)[i].m_age<<endl;
			cout<<"社员专业:"<<(*m_mes)[i].m_profession<<endl;
			cout<<"社员班级:"<<(*m_mes)[i].m_grade<<endl;
			cout<<"社员职务:"<<(*m_mes)[i].m_club<<endl;
			cout<<endl;
			flog=true;
		}
	}
	if(flog==false)
	{
		cout<<"没有该会员号信息"<<endl;
	}
}
void StudentManage::Write( )		//写入文件
{
	string cludname=this->pathname+".data";
	ofstream os(cludname.c_str(),ios::out|ios::trunc);
	if(!os)
	{
		cout<<"打开文件失败"<<endl;
		exit(2);
	}
	os.seekp(0,ios::beg);
	for(unsigned int i=0;i<m_mes->size();i++)
	{
		os<<(*m_mes)[i].m_id<<"\t";
		os<<(*m_mes)[i].m_name<<"\t";
		os<<(*m_mes)[i].m_sex<<"\t";
		os<<(*m_mes)[i].m_age<<"\t";
		os<<(*m_mes)[i].m_profession<<"\t";
		os<<(*m_mes)[i].m_grade<<"\t";
		os<<(*m_mes)[i].m_club<<endl;
	}
	os.close();
}
void StudentManage::Read()		//从文件中读取
{
	StudentMessage tempstudent;
	string cludpath=this->pathname+".data";
	ifstream is(cludpath.c_str(),ios::in|ios::app);
	if(!is)
	{
		cout<<"打开文件失败"<<endl;
		exit(1);
	}
	is.seekg(0,ios::end);
	if(0==is.tellg())
	{
		is.close();
	}
	else
	{

		is.seekg(0,ios::beg);
		while(1)
		{
			
			is>>tempstudent.m_id;
			is>>tempstudent.m_name;
			is>>tempstudent.m_sex;
			is>>tempstudent.m_age;
			is>>tempstudent.m_profession;
			is>>tempstudent.m_grade;
			is>>tempstudent.m_club;
			if(!is.eof())
			{
				m_mes->push_back(tempstudent);
			}
			else
			{
				is.close();
				break;
			}
		}
	}
}
void StudentManage::SearchAll( ) //打印所有成员信息
{
	cout<<"打印所有成员："<<endl<<endl;
	if(0==m_mes->size())
	{
		cout<<"该社团还没有成员，请组建！！！"<<endl;
		return;
	}
	for(unsigned int i=0;i<m_mes->size();i++)
	{
		cout<<endl;
		cout<<"社员会员号:"<<(*m_mes)[i].m_id<<endl;
		cout<<"社员姓名:"<<(*m_mes)[i].m_name<<endl;
		cout<<"社员职务:"<<(*m_mes)[i].m_club<<endl;
		cout<<endl;
	}
}
//设置社长
string StudentManage::Proprieter()
{
	cout<<"请输入新的社长ID：";
	string sign;
	cin>>sign;
	bool flag=false;
	if(m_mes->size()==0)
	{
		cout<<"该社团没有成员，请创建！！！"<<endl;
		return "";
	}
	for(unsigned int i=0;i<m_mes->size();i++)
	{
		if((*m_mes)[i].m_id==sign)
		{
			this->FindProprieterGg();
			(*m_mes)[i].m_club="社长";
			this->Write();
			return (*m_mes)[i].m_name;
		}
	}
		cout<<"会员不存在，设置新社长失败";
		string a="";
		return a;
}
//社长查询
void StudentManage::FindProprieter()
{
	string sign="社长";
	if(m_mes->size()==0)
	{
		cout<<"该社团暂无成员，请创建!!!!!";
		return;
	}
	bool k=false;
	for(unsigned int i=0;i<m_mes->size();i++)
	{
		if((*m_mes)[i].m_club==sign)
		{
			cout<<endl;
			cout<<this->pathname<<"社长信息是："<<endl<<endl;
			cout<<"社员会员号:"<<(*m_mes)[i].m_id<<endl;
			cout<<"社员姓名:"<<(*m_mes)[i].m_name<<endl;
			cout<<"社员性别:"<<(*m_mes)[i].m_sex<<endl;
			cout<<"社员年龄："<<(*m_mes)[i].m_age<<endl;
			cout<<"社员专业:"<<(*m_mes)[i].m_profession<<endl;
			cout<<"社员班级:"<<(*m_mes)[i].m_grade<<endl;
			cout<<"社员职务:"<<(*m_mes)[i].m_club<<endl;
			cout<<endl;
			k=true;
		}
	}
	if(k==false)
	{
		cout<<"该社团还未设置社长，赶紧设置吧!!!"<<endl;
	}

}
//撤销社长
void StudentManage::FindProprieterGg()
{
	string sign="社长";
	for(unsigned int i=0;i<m_mes->size();i++)
	{
		if((*m_mes)[i].m_club==sign)
		{
			(*m_mes)[i].m_club="普通成员";
		}
	}
	this->Write();
}
//获取向量
vector<StudentMessage>*& StudentManage::GetVector()
{
	return this->m_mes;
}
bool StudentManage::FindProprieterF()	//判断社长是否存在
{
	string sign="社长";
	if((*m_mes).size()==0)
	{
		return false;
	}
	
	bool a=false;

	for(unsigned int i=0;i<m_mes->size();i++)
	{
		if((*m_mes)[i].m_club==sign)
		{
			a=true;
		}
	}
	return a;

}
string StudentManage::GetProprieter()	//获取社长名
{
	string sign="社长";
	if((*m_mes).size()==0)
	{
		return "";
	}
	for(unsigned int i=0;i<m_mes->size();i++)
	{
		if((*m_mes)[i].m_club==sign)
		{
			return (*m_mes)[i].m_name;
		}
	}
		return "";

}
void StudentManage::Peoples()
{
	cout<<this->pathname<<"总人数："<<m_mes->size()<<" 人"<<endl;
}