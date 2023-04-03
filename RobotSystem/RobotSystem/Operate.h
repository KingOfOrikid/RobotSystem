#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cassert>
#include <conio.h>
#include <stdio.h>
#include "Users.h"

using namespace std;
class Operate
{
public:
	Operate(const string&file);
	Operate();
	~Operate();

public:
	bool find(string& enteredPassword, const string& delim);
	void clearValue(string& tempPassword); //清空某字符串的内容
	void clearValue(char& ch);//清空某字符的内容
	void show(string& name, string& password);//登陆时提醒用户输入用户名与密码
	void showPP();//提示让用户输入两次密码
	string formTempWord(string& tempWord);//将需要录入的用户信息连接成一整句带分隔符的字符串便于录入txt文件
	bool judgeNP(string name, string password);//判断密码与用户名是否正确
	bool judgeN(string& enteredName);//判断注册时的用户名是否已被其他用户注册
	bool judgeP(string& password,int& num);//判断更改后的密码是否与原密码一致
	bool judgeNumOfP(string& password);//判断密码的字符数是否符合标准大于等于八字符
	bool judgeEffectivenessOfP(string& password, const string& delim);//判断密码是否符合标准，字符数量大于等于8且不可以包含“，”
	int judgeWhichUser(string name);//判断此用户名对应的是哪一个用户
	bool logIn(string name, string password);//登陆，显示登陆成功或密码错误
	int circularLogin();//循环登陆，即用户名与密码最多错误三次
	void circularChange();//循环更改密码，即在用户名密码正确的前提下，需输入两次相同的密码，更改密码成功即存入对应数组及txt文件中，用户名与密码错误不得大于三次
	void registered();//注册，需输入此前不存在的用户名，用户名与密码存入数组及txt文件中

private:
	string enteredName;//输入的用户名
	string enteredPassword;//输入的密码
	int error;//错误次数
	bool flag,sign;//判断正误决定接下来的内容
	char logInCh;//登录中转换密码格式的字符
	char changeCh;//改密码中转换密码格式的字符
	char registeredCh;//注册中转换密码格式的字符
	string tempPassword;//转换密码格式中用的中间变量密码

protected:
	vector<Users> userVec;//文件中原本储存的用户
	int userNum;//用户名对应的用户数

public:
	Users usingUser;//正在使用的用户
	Users user;
};

