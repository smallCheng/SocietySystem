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
char StudentManage::Menu( )		//�˵�
{
	cout<<endl;
	cout<<"*************************************************************"<<endl;
	cout<<"*                      ѧ�����Ź���ϵͳ����"<<this->pathname  <<endl;
	cout<<"*                                                           *"<<endl;
	cout<<"*                       1.�����Ա��Ϣ                      *"<<endl;
	cout<<"*                       2.�޸���Ա��Ϣ                      *"<<endl;
	cout<<"*                       3.ɾ����Ա��Ϣ                      *"<<endl;              
	cout<<"*                       4.��ѯ��Ա��Ϣ                      *"<<endl;
	cout<<"*                       5.��ӡ���г�Ա                      *"<<endl;
	cout<<"*                       6.�糤��Ϣ                          *"<<endl;
	cout<<"*                       7.��������                          *"<<endl;
	cout<<"*                       8.������һ��                        *"<<endl;
	cout<<"*************************************************************"<<endl;
	cout<<endl;
	cout<<"�����빦�ܼ�:";
	char choose;
	cin>>choose;
	fflush(stdin);
	cout<<endl<<endl;
	return choose;
}

char StudentManage::Menu2( )		//��Ա�˵�
{
	cout<<endl;
	cout<<"*************************************************************"<<endl;
	cout<<"*                      ѧ�����Ź���ϵͳ����"<<this->pathname  <<endl;
	cout<<"*                                                           *"<<endl;
	cout<<"*                       1.��ѯ��Ա��Ϣ                      *"<<endl;
	cout<<"*                       2.��ӡ���г�Ա                      *"<<endl;
	cout<<"*                       3.�糤��Ϣ                          *"<<endl;
	cout<<"*                       4.��������                          *"<<endl;
	cout<<"*                       5.������һ��                        *"<<endl;
	cout<<"*************************************************************"<<endl;
	cout<<endl;
	cout<<"�����빦�ܼ�:";
	char choose;
	cin>>choose;
	fflush(stdin);
	cout<<endl<<endl;
	return choose;
}

void StudentManage::Add(vector<string>& files)		//�����Ա��Ϣ
{
	StudentMessage temp;
	cout<<"��������������Ա����Ϣ"<<endl<<endl;
	cout<<"��Ա��Ա��:";
	cin>>temp.m_id;
	cout<<"��Ա����:";
	cin>>temp.m_name;
	cout<<"��Ա�Ա�";
	cin>>temp.m_sex;
	cout<<"��Ա����:";
	cin>>temp.m_age;
	cout<<"��Աרҵ:";
	cin>>temp.m_profession;
	cout<<"��Ա�༶:";
	cin>>temp.m_grade;
	cout<<"��Աְ��:";
	cin>>temp.m_club;
	if(temp.m_club=="�糤")
	{
		if(this->FindProprieterF())
		{
			cout<<"�Ѵ����糤������������ְ��"<<endl;
			cout<<"��Աְ��:";
			cin>>temp.m_club;
			if(temp.m_club=="�糤")
			{
				cout<<"����������ѷ���"<<endl;
				return;
			}

		}
	}
	for(unsigned int i=0;i<m_mes->size();i++)
	{
		if((*m_mes)[i].m_id==temp.m_id)
		{
			cout<<"��Ա���Ѵ���!!!"<<endl;
			cout<<"�����������Ա��:";
			cin>>temp.m_id;
			i--;
		}
	}
	m_mes->push_back(temp);
	files.push_back(temp.m_id);
	m_num++;
	Write();
	cout<<"�ɹ�����³�Ա"<<endl<<endl;
}
void StudentManage::Change( )		//�޸���Ա��Ϣ
{
	
	string sign;
	cout<<endl;
	cout<<"����Ҫ�޸ĵ���Ա��Ϣ�Ļ�Ա��:";
	cin>>sign;
	for(unsigned int i=0;i<m_mes->size();i++)
	{
		if((*m_mes)[i].m_id==sign)
		{
			cout<<endl;
			cout<<"��Ҫ�޸ĵ���Ա��Ϣ�ǣ�"<<endl<<endl;
			cout<<"��Ա��Ա��:"<<(*m_mes)[i].m_id<<endl;
			cout<<"��Ա����:"<<(*m_mes)[i].m_name<<endl;
			cout<<"��Ա�Ա�:"<<(*m_mes)[i].m_sex<<endl;
			cout<<"��Ա���䣺"<<(*m_mes)[i].m_age<<endl;
			cout<<"��Աרҵ:"<<(*m_mes)[i].m_profession<<endl;
			cout<<"��Ա�༶:"<<(*m_mes)[i].m_grade<<endl;
			cout<<"��Աְ��:"<<(*m_mes)[i].m_club<<endl;
			cout<<endl;
			cout<<endl;
			char yn;
			cout<<"�Ƿ��޸���Ϣ:�ǣ�y��/��n��?"<<endl;
			cin>>yn;
			fflush(stdin);
			if(yn=='y'||yn=='Y')
			{
				cout<<"������������Ա������Ϣ"<<endl;
				cout<<"��Ա��Ա��:";
				cin>>(*m_mes)[i].m_id;
				cout<<"��Ա����:";
				cin>>(*m_mes)[i].m_name;
				cout<<"��Ա�Ա�:";
				cin>>(*m_mes)[i].m_sex;
				cout<<"��Ա���䣺";
				cin>>(*m_mes)[i].m_age;
				cout<<"��Աרҵ:";
				cin>>(*m_mes)[i].m_profession;
				cout<<"��Ա�༶:";
				cin>>(*m_mes)[i].m_grade;
				cout<<"��Աְ��:";
				cin>>(*m_mes)[i].m_club;
				if((*m_mes)[i].m_club=="�糤")
				{
					if(this->FindProprieterF())
					{
						cout<<"�Ѵ����糤������������ְ��"<<endl;
						cout<<"��Աְ��:";
						cin>>(*m_mes)[i].m_club;
						if((*m_mes)[i].m_club=="�糤")
						{
							cout<<"����������ѷ���"<<endl;
							return;
						}

					}
				}
				Write();
				cout<<"������Ա��Ϣ���"<<endl;

			}
			else if(yn=='n'||yn=='N')
			{
				cout<<"�ѷ����޸�"<<endl;
			}
			else
			{
				cout<<"�������󣬷����޸�"<<endl;
			}


		}
	}

}
void StudentManage::Delete( )		//ɾ����Ա��Ϣ
{
	
	string sign;
	cout<<endl;
	cout<<"����Ҫɾ������Ա�Ļ�Ա��:";
	cin>>sign;
	bool flog=false;
	vector<StudentMessage>::iterator it=m_mes->begin();
	for(it;it!=m_mes->end();it++)
	{
		if(it->m_id==sign)
		{
			cout<<endl;
			cout<<"��Ҫɾ������Ա��Ϣ�ǣ�"<<endl<<endl;
			cout<<"��Ա��Ա��:"<<it->m_id<<endl;
			cout<<"��Ա����:"<<it->m_name<<endl;
			cout<<"��Ա�Ա�:"<<it->m_sex<<endl;
			cout<<"��Ա���䣺"<<it->m_age<<endl;
			cout<<"��Աרҵ:"<<it->m_profession<<endl;
			cout<<"��Ա�༶:"<<it->m_grade<<endl;
			cout<<"��Աְ��:"<<it->m_club<<endl;
			cout<<endl;
			flog=true;
			cout<<"�Ƿ�ɾ����Ա"<<it->m_id<<"����Ϣ";
			cout<<"�ǣ�y��/��n����";
			char yn;
			cin>>yn;
			fflush(stdin);
			if(yn=='y'||yn=='Y')
			{

				m_mes->erase(it);
				Write();
				cout<<"�ɹ�ɾ����Ա"<<endl;
				return;
			}
			else if(yn=='n'||yn=='N')
			{
				cout<<"�ѷ���ɾ����Ա��Ϣ"<<endl;
			}
			else
			{
				cout<<"�������󣬷���ɾ��"<<endl;
			}

		}
	}
	if(flog==false)
	{
		cout<<"û�иû�Ա����Ϣ"<<endl;
	}
}
void StudentManage::Search( )		//��ѯ��Ա��Ϣ
{
	string sign;
	cout<<endl;
	cout<<"����Ҫ��ѯ����Ա�Ļ�Ա��:";
	cin>>sign;
	bool flog=false;
	for(unsigned int i=0;i<m_mes->size();i++)
	{
		if((*m_mes)[i].m_id==sign)
		{
			cout<<endl;
			cout<<"��Ҫ��ѯ����Ա��Ϣ�ǣ�"<<endl<<endl;
			cout<<"��Ա��Ա��:"<<(*m_mes)[i].m_id<<endl;
			cout<<"��Ա����:"<<(*m_mes)[i].m_name<<endl;
			cout<<"��Ա�Ա�:"<<(*m_mes)[i].m_sex<<endl;
			cout<<"��Ա���䣺"<<(*m_mes)[i].m_age<<endl;
			cout<<"��Աרҵ:"<<(*m_mes)[i].m_profession<<endl;
			cout<<"��Ա�༶:"<<(*m_mes)[i].m_grade<<endl;
			cout<<"��Աְ��:"<<(*m_mes)[i].m_club<<endl;
			cout<<endl;
			flog=true;
		}
	}
	if(flog==false)
	{
		cout<<"û�иû�Ա����Ϣ"<<endl;
	}
}
void StudentManage::Write( )		//д���ļ�
{
	string cludname=this->pathname+".data";
	ofstream os(cludname.c_str(),ios::out|ios::trunc);
	if(!os)
	{
		cout<<"���ļ�ʧ��"<<endl;
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
void StudentManage::Read()		//���ļ��ж�ȡ
{
	StudentMessage tempstudent;
	string cludpath=this->pathname+".data";
	ifstream is(cludpath.c_str(),ios::in|ios::app);
	if(!is)
	{
		cout<<"���ļ�ʧ��"<<endl;
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
void StudentManage::SearchAll( ) //��ӡ���г�Ա��Ϣ
{
	cout<<"��ӡ���г�Ա��"<<endl<<endl;
	if(0==m_mes->size())
	{
		cout<<"�����Ż�û�г�Ա�����齨������"<<endl;
		return;
	}
	for(unsigned int i=0;i<m_mes->size();i++)
	{
		cout<<endl;
		cout<<"��Ա��Ա��:"<<(*m_mes)[i].m_id<<endl;
		cout<<"��Ա����:"<<(*m_mes)[i].m_name<<endl;
		cout<<"��Աְ��:"<<(*m_mes)[i].m_club<<endl;
		cout<<endl;
	}
}
//�����糤
string StudentManage::Proprieter()
{
	cout<<"�������µ��糤ID��";
	string sign;
	cin>>sign;
	bool flag=false;
	if(m_mes->size()==0)
	{
		cout<<"������û�г�Ա���봴��������"<<endl;
		return "";
	}
	for(unsigned int i=0;i<m_mes->size();i++)
	{
		if((*m_mes)[i].m_id==sign)
		{
			this->FindProprieterGg();
			(*m_mes)[i].m_club="�糤";
			this->Write();
			return (*m_mes)[i].m_name;
		}
	}
		cout<<"��Ա�����ڣ��������糤ʧ��";
		string a="";
		return a;
}
//�糤��ѯ
void StudentManage::FindProprieter()
{
	string sign="�糤";
	if(m_mes->size()==0)
	{
		cout<<"���������޳�Ա���봴��!!!!!";
		return;
	}
	bool k=false;
	for(unsigned int i=0;i<m_mes->size();i++)
	{
		if((*m_mes)[i].m_club==sign)
		{
			cout<<endl;
			cout<<this->pathname<<"�糤��Ϣ�ǣ�"<<endl<<endl;
			cout<<"��Ա��Ա��:"<<(*m_mes)[i].m_id<<endl;
			cout<<"��Ա����:"<<(*m_mes)[i].m_name<<endl;
			cout<<"��Ա�Ա�:"<<(*m_mes)[i].m_sex<<endl;
			cout<<"��Ա���䣺"<<(*m_mes)[i].m_age<<endl;
			cout<<"��Աרҵ:"<<(*m_mes)[i].m_profession<<endl;
			cout<<"��Ա�༶:"<<(*m_mes)[i].m_grade<<endl;
			cout<<"��Աְ��:"<<(*m_mes)[i].m_club<<endl;
			cout<<endl;
			k=true;
		}
	}
	if(k==false)
	{
		cout<<"�����Ż�δ�����糤���Ͻ����ð�!!!"<<endl;
	}

}
//�����糤
void StudentManage::FindProprieterGg()
{
	string sign="�糤";
	for(unsigned int i=0;i<m_mes->size();i++)
	{
		if((*m_mes)[i].m_club==sign)
		{
			(*m_mes)[i].m_club="��ͨ��Ա";
		}
	}
	this->Write();
}
//��ȡ����
vector<StudentMessage>*& StudentManage::GetVector()
{
	return this->m_mes;
}
bool StudentManage::FindProprieterF()	//�ж��糤�Ƿ����
{
	string sign="�糤";
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
string StudentManage::GetProprieter()	//��ȡ�糤��
{
	string sign="�糤";
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
	cout<<this->pathname<<"��������"<<m_mes->size()<<" ��"<<endl;
}