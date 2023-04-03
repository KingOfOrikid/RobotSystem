#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Users
{
public:
	Users();
	~Users();

private:
	string name;//用户用户名
	string password;//用户密码
	int integral;//用户积分

public:
	void userTestShow();//测试过程中看信息是否录入
	void setInformation(string name, string password, int intergral);//将姓名、密码、积分储存到此用户的姓名、密码、积分变量中
	void entryLoginInformation(string name, string password);//储存用户信息
	string getAllName();//获得用户的用户名
	string getAllPassword();//获得用户的密码
	int getAllIntegral();//获得用户的积分
	void changePassword(string password);//更改密码
	void changeIntegral(int integral);//更改积分
};

