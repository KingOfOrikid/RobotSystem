#include "Users.h"
#include "FileManage.h"


Users::Users()
{
}


Users::~Users()
{
}

/*将姓名、密码、积分储存到此用户的姓名、密码、积分变量中*/
void Users::setInformation(string name,string password , int intergral)
{
	this->name = name;
	this->password = password;
	this->integral=intergral;
	return;
}

/*测试是否正确录入userVec数组*/
void Users::userTestShow()
{
	cout << name << endl;
	cout << password << endl;
	cout << integral << endl;
	return;
}

/*获得用户的用户名*/
string Users::getAllName()
{
	return name;
}

/*获得用户的密码*/
string Users::getAllPassword()
{
	return password;
}

/*获得用户的积分*/
int Users::getAllIntegral()
{
	return integral;
}

/*储存用户信息*/
void Users::entryLoginInformation(string name, string password)
{
	this->name = name;
	this->password = password;
	return;
}

/*更改密码*/
void Users::changePassword(string tempPassword)
{
	password = tempPassword;
}

/*更改积分*/
void Users::changeIntegral(int integral)
{
	this->integral = integral;
	return;
}