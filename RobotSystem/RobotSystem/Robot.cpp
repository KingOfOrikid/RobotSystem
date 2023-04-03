#include "Robot.h"
#include "FileManage.h"


Robot::Robot()
{
	lifeValue = 5;//机器人初始生命值5
}

Robot::Robot(const Robot& r)
{
	lifeValue = r.lifeValue;
	questions=r.questions;
	answers=r.answers;
}


Robot::~Robot()
{
}

/*功能：得到生命值
  参数：无
  返回值：
        lifeValue--生命值
*/
int Robot::getLife()
{
	return lifeValue;
}

/*功能：改变生命值
  参数：
        value--改变后的生命值
  返回值：无
*/
void Robot::changeLife(int& value)
{
	lifeValue = value;
	return;
}

/*功能：储存问题
  参数：
        questionVec--问题数组
  返回值：无
*/
void Robot::storeQues(vector<string>& questionVec)
{
	for (int i = 0; i < questionVec.size(); i++)
	{
		questions.push_back(questionVec[i]);
	}
	return;
}

/*功能：储存回答
  参数：
        answerVec--回答参数
  返回值：无
*/
void Robot::storeAnsw(vector<string>& answerVec)
{
	for (int i = 0; i < answerVec.size(); i++)
	{
		answers.push_back(answerVec[i]);
	}
	return;
}

/*功能：得到相对应的回答
  参数：
        i--此回答在回答数组中的行数
  返回值：
        answer[i]--回答
*/
string Robot::getOneAnsw(int i)
{
	return answers[i];
}

/*功能：得到相对应的问题
  参数：
        i--此问题在问题数组中的行数
  返回值：
        question[i]--问题
*/
string Robot::getOneQues(int i)
{
	return questions[i];
}

/*功能：得到机器人姓名
  参数：无
  返回值：
        name--机器人姓名
*/
string Robot::getName()
{
	return name;
}

/*功能：得到机器人主人的名字
  参数：无
  返回值：
        masterName--机器人主人的名字
*/
string Robot::getMasterName()
{
	return masterName;
}

/*功能：得到机器人的名字
  参数：无
  返回值：无
*/
void Robot::setName()
{
	cout << "请输入你称呼对方的名字：";
	cin >> name;
	return;
}

/*功能：得到机器人主人的名字
  参数：无
  返回值：无
*/
void Robot::setMasterName()
{
	cout << "请输入你想让对方称呼你的名字：";
	cin >> masterName;
	return;
}