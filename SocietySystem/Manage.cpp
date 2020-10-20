#include "Manage.h"
#include "StudentManage.h"
void Manage::Init() //��ʼ��
{
	this->Read();
}
char Manage::Menu( )		//�˵�
{
	cout<<endl;
	cout<<"*************************************************************"<<endl;
	cout<<"*                          ���Ź���                         *"<<endl;
	cout<<"*                                                           *"<<endl;
	cout<<"*                      1.���������Ϣ                       *"<<endl;
	cout<<"*                      2.�޸�������Ϣ                       *"<<endl;
	cout<<"*                      3.ɾ��������Ϣ                       *"<<endl;
	cout<<"*                      4.��ѯ������Ϣ                       *"<<endl;
	cout<<"*                      5.��ӡ��������                       *"<<endl;
	cout<<"*                      6.������һ��                         *"<<endl;
	cout<<"*************************************************************"<<endl;
	cout<<endl;
	cout<<"�����빦�ܼ�:";
	char choose;
	cin>>choose;
	fflush(stdin);
	cout<<endl<<endl;
	return choose;
}
void Manage::Add( )		//���������Ϣ
{
	ManageMessage temp;
	cout<<"���������������ŵ���Ϣ"<<endl<<endl;
	cout<<"����ID:";
	cin>>temp.m_id;
	cout<<"������:";
	cin>>temp.m_club;
	cout<<"�������ԣ�";
	cin>>temp.m_natrue;
	temp.m_name="�����糤";
	
	for(unsigned int i=0;i<m_mes.size();i++)
	{
		if(m_mes[i].m_id==temp.m_id)
		{
			cout<<"��Ա���Ѵ���!!!"<<endl;
			cout<<"�����������Ա��:";
			cin>>temp.m_id;
			i--;
		}
	}
	char yn;
	cout<<"ȷ����������ţ�:�ǣ�y��/��n��?"<<endl;
	cout<<"������:";
	cin>>yn;
	fflush(stdin);
	if(yn=='y'||yn=='Y')
	{
		m_mes.push_back(temp);
		Write();
		cout<<"�ɹ����������"<<endl<<endl;
	}
	else
	{
		cout<<"�������������"<<endl;
	}
}
void Manage::Change( )		//�޸�������Ϣ
{

	string sign;
	cout<<endl;
	cout<<"����Ҫ�޸ĵ�����ID:";
	cin>>sign;
	for(unsigned int i=0;i<m_mes.size();i++)
	{
		if(m_mes[i].m_id==sign)
		{
			cout<<endl;
			cout<<"��Ҫ�޸ĵ�������Ϣ�ǣ�"<<endl<<endl;
			cout<<"����ID:"<<m_mes[i].m_id<<endl;
			cout<<"������:"<<m_mes[i].m_club<<endl;
			cout<<"�糤:"<<m_mes[i].m_name<<endl;
			cout<<"��������:"<<m_mes[i].m_natrue<<endl;
			cout<<endl;
			cout<<endl;
			char yn;
			cout<<"�Ƿ��޸���Ϣ:�ǣ�y��/��n��?"<<endl;
			cout<<"�����룺";
			cin>>yn;
			fflush(stdin);
			if(yn=='y'||yn=='Y')
			{
				cout<<"�������������ŵ�����Ϣ"<<endl;
				cout<<"������ID��";
				cin>>m_mes[i].m_id;
				cout<<"��������:";
				cin>>m_mes[i].m_club;
				cout<<"����������:";
				cin>>m_mes[i].m_natrue;
				cout<<"�Ƿ�������������糤:�ǣ�y��/��n��?"<<endl;
				cout<<" ������:";
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
						cout<<"�������޳�Ա���޷������糤"<<endl;
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
				cout<<"����������Ϣ���"<<endl;

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
void Manage::Delete( )		//ɾ��������Ϣ
{

	string sign;
	cout<<endl;
	cout<<"����Ҫɾ��������ID:";
	cin>>sign;
	bool flog=false;
	vector<ManageMessage>::iterator it=m_mes.begin();
	for(it;it!=m_mes.end();it++)
	{
		if(it->m_id==sign)
		{
			cout<<endl;
			cout<<"��Ҫɾ�����ŵ���Ϣ�ǣ�"<<endl<<endl;
			cout<<"����ID:"<<it->m_id<<endl;
			cout<<"������:"<<it->m_club<<endl;
			{
				string path=it->m_club;
				StudentManage* stu=new StudentManage(path);
				stu->Init();
				string pp=stu->GetProprieter();
				if(pp=="")
				{
					it->m_name="����";
					cout<<"�糤:"<<it->m_name<<endl;
					it->m_peoples=stu->GetVector()->size();
					cout<<"����������:"<<stu->GetVector()->size()<<endl;
				}
				else
				{
					it->m_name=pp;
					cout<<"�糤:"<<it->m_name<<endl;
					it->m_peoples=stu->GetVector()->size();
					cout<<"����������:"<<stu->GetVector()->size()<<endl;
				}
				delete stu;
				stu=NULL;

			}
			cout<<"��������:"<<it->m_natrue<<endl;
			cout<<endl;
			flog=true;
			cout<<"�Ƿ�ɾ������"<<it->m_id<<"����Ϣ";
			cout<<"�ǣ�y��/��n����"<<endl;
			char yn;
			cout<<"������:";
			cin>>yn;
			fflush(stdin);
			if(yn=='y'||yn=='Y')
			{
				string pa=it->m_club+".data";
				remove(pa.c_str());
				m_mes.erase(it);
				Write();
				cout<<"�ɹ�ɾ������"<<endl;
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
		cout<<"û�и�������Ϣ"<<endl;
	}
}
void Manage::Search( )		//��ѯ������Ϣ
{
	string sign;
	cout<<endl;
	cout<<"����Ҫ��ѯ������ID:";
	cin>>sign;
	bool flog=false;
	for(unsigned int i=0;i<m_mes.size();i++)
	{
		if(m_mes[i].m_id==sign)
		{
			cout<<endl;
			cout<<"��Ҫ��ѯ���ŵ���Ϣ�ǣ�"<<endl<<endl;
			cout<<"����ID:"<<m_mes[i].m_id<<endl;
			cout<<"������:"<<m_mes[i].m_club<<endl;
			{
				string path=m_mes[i].m_club;
				StudentManage* stu=new StudentManage(path);
				stu->Init();
					string pp=stu->GetProprieter();
					if(pp=="")
					{
						this->m_mes[i].m_name="����";
						cout<<"�糤:"<<m_mes[i].m_name<<endl;
						this->m_mes[i].m_peoples=stu->GetVector()->size();
						cout<<"����������:"<<stu->GetVector()->size()<<endl;
					}
					else
					{
						this->m_mes[i].m_name=pp;
						cout<<"�糤:"<<m_mes[i].m_name<<endl;
						this->m_mes[i].m_peoples=stu->GetVector()->size();
						cout<<"����������:"<<stu->GetVector()->size()<<endl;
					}
				delete stu;
				stu=NULL;

			}
			cout<<"��������:"<<m_mes[i].m_natrue<<endl;
			this->Write();
			cout<<endl;
			flog=true;
		}
	}
	if(flog==false)
	{
		cout<<"û�и����ŵ���Ϣ"<<endl;
	}
}
void Manage::Write( )		//д���ļ�
{
	ofstream os("ManageMessage.txt",ios::out|ios::trunc);
	if(!os)
	{
		cout<<"���ļ�ʧ��"<<endl;
		exit(2);
	}
	os.seekp(0,ios::beg);
	for(unsigned int i=0;i<m_mes.size();i++)
	{
		//cout<<"�±�i="<<i<<endl;
		os<<m_mes[i].m_id<<"\t";
		os<<m_mes[i].m_club<<"\t";
		os<<m_mes[i].m_natrue<<"\t";
		os<<m_mes[i].m_name<<"\t";
	}
	os.close();
}
void Manage::Read( )		//���ļ��ж�ȡ
{
	ManageMessage temp;
	ifstream is("ManageMessage.txt",ios::in|ios::app);
	if(!is)
	{
		cout<<"���ļ�ʧ��"<<endl;
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
void Manage::SearchAll( ) //��ӡ����������Ϣ
{
	cout<<"��ӡ���в�����Ϣ��"<<endl<<endl;
	if(m_mes.size()==0)
	{
		cout<<"��û���κε����ţ��Ͻ�������!!!"<<endl;
	}
	else
	{

	for(unsigned int i=0;i<m_mes.size();i++)
	{
		cout<<endl;
		cout<<"����id:"<<m_mes[i].m_id<<endl;
		cout<<"������:"<<m_mes[i].m_club<<endl;
		{
			string path=m_mes[i].m_club;
			StudentManage* stu=new StudentManage(path);

			stu->Init();
			string pp=stu->GetProprieter();
			if(pp=="")
			{
				this->m_mes[i].m_name="����";
				cout<<"�糤:"<<m_mes[i].m_name<<endl;
				this->m_mes[i].m_peoples=stu->GetVector()->size();
				cout<<"����������:"<<stu->GetVector()->size()<<endl;
			}
			else
			{
			
				this->m_mes[i].m_name=pp;
				cout<<"�糤:"<<m_mes[i].m_name<<endl;
				this->m_mes[i].m_peoples=stu->GetVector()->size();
				cout<<"����������:"<<stu->GetVector()->size()<<endl;
			}
			delete stu;
			stu=NULL;

		}
		cout<<"��������:"<<m_mes[i].m_natrue<<endl;
		this->Write();
		cout<<endl;
	}
	}

}
vector<ManageMessage>& Manage::GetVector()//��ȡ����
{
	return this->m_mes;
}
Manage::Manage(void)
{
	
}

Manage::~Manage(void)
{
}
