#pragma once
#pragma warning(disable:4996)//使ctime为安全的
#include <iostream>
#include "Robot.h"
#include "Users.h"
#include "Operate.h"
#include <fstream>
#include <cassert>
#include <time.h>
#include <iomanip>
#include <stdlib.h>

using namespace std;
class SystemWork:private Operate
{
public:
	SystemWork(const string&file);
	SystemWork();
	~SystemWork();
	friend class Robot;
	vector<string> questionsVec;
	vector<string> answersVec;


public:
	void store(vector<string>& answersVec, vector<string>& questionsVec);//储存此机器人的问题和回答
	void modifyContentInFile(char *fileName, int lineNum, char *content);//修改文件某行内容
	void saveTxt(const string& file,Users& usinguser);//将积分改过后的信息储存进txt中
	string charToStr(char * contentChar);//字符串转化str类型
	void getAndJudgeTime();//获得当前本机时间并对时间段作出判断得出回答
	string getTime();//获得当前本机时间
	bool find(Robot& robot,vector<string>& StoredVec, string& enteredWord);//从数组中关键词查找问题
	bool exchangeLife(Robot& robot, char& choose, Users& usinguser);//用户选择退出则退出程序，选择充值则进行充值过程
	char lifeEmpty();//机器人生命值耗尽时让用户作选择
	void boyfriend(int& num, Users& usinguser);//机器人男朋友运行过程

private:
	Robot robot;//机器人
	bool flag, sign;
	string enteredWord;//输入的话
	char choose;
	int lifeChange;//改变的生命值
	char buf[128] = { 0 };//储存时间的数组
	Users user;
};

