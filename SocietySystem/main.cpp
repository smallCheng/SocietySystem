#include "Assist.h"
int main( )
{
	setlocale(LC_ALL,"");
	//�����ɫ
	//m_setColor();
	MainInit();//��ʼ��
	while(1)
	{
		switch(MainFace())
		{
		case 1:
			PeoLog();  //��ͨ��Ա��½
			break;
		case 2:
			ManLog();//��ͨ�����½
			break;
		case 3:
			RootLog();//�߼������½
			break;
		case 4:
			cout<<"���˳����Ź���ϵͳ"<<endl;
			return 0;
		case 333:  //���ع��� ��ʼ���߼�������������
			PwdInit();
			break;
		default:
			cout<<"�����������������룺"<<endl;
			break;
		}
	}
	return 0;
}