#pragma once
#include <iostream>
#include <vector>
#include <string>
#include<windows.h>

using namespace std;
class Robot
{
public:
	Robot(const Robot& r);
	Robot();
	~Robot();

private:
	string name;//机器人的名字
	string masterName;//机器人主人的名字
	char choice;//选择
	int lifeValue;//生命值

public:
	int getLife();//得到生命值
	void changeLife(int& value);// 改变生命值
	void storeQues(vector<string>& questions);//储存问题
	void storeAnsw(vector<string>& answerVec);//储存回答
	string getOneAnsw(int i);//得到相对应的回答
	string getOneQues(int i);//得到相对应的问题
	string getName();//得到机器人姓名
	string getMasterName();//得到机器人主人的名字
	void setName();//得到机器人的名字
	void setMasterName();//得到机器人主人的名字

protected:
	vector<string> questions;//问题数组
	vector<string> answers;//回答数组
};

