#include "Users.h"
#include "FileManage.h"


Users::Users()
{
}


Users::~Users()
{
}

/*�����������롢���ִ��浽���û������������롢���ֱ�����*/
void Users::setInformation(string name,string password , int intergral)
{
	this->name = name;
	this->password = password;
	this->integral=intergral;
	return;
}

/*�����Ƿ���ȷ¼��userVec����*/
void Users::userTestShow()
{
	cout << name << endl;
	cout << password << endl;
	cout << integral << endl;
	return;
}

/*����û����û���*/
string Users::getAllName()
{
	return name;
}

/*����û�������*/
string Users::getAllPassword()
{
	return password;
}

/*����û��Ļ���*/
int Users::getAllIntegral()
{
	return integral;
}

/*�����û���Ϣ*/
void Users::entryLoginInformation(string name, string password)
{
	this->name = name;
	this->password = password;
	return;
}

/*��������*/
void Users::changePassword(string tempPassword)
{
	password = tempPassword;
}

/*���Ļ���*/
void Users::changeIntegral(int integral)
{
	this->integral = integral;
	return;
}