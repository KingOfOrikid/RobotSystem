#include "Robot.h"
#include "FileManage.h"


Robot::Robot()
{
	lifeValue = 5;//�����˳�ʼ����ֵ5
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

/*���ܣ��õ�����ֵ
  ��������
  ����ֵ��
        lifeValue--����ֵ
*/
int Robot::getLife()
{
	return lifeValue;
}

/*���ܣ��ı�����ֵ
  ������
        value--�ı�������ֵ
  ����ֵ����
*/
void Robot::changeLife(int& value)
{
	lifeValue = value;
	return;
}

/*���ܣ���������
  ������
        questionVec--��������
  ����ֵ����
*/
void Robot::storeQues(vector<string>& questionVec)
{
	for (int i = 0; i < questionVec.size(); i++)
	{
		questions.push_back(questionVec[i]);
	}
	return;
}

/*���ܣ�����ش�
  ������
        answerVec--�ش����
  ����ֵ����
*/
void Robot::storeAnsw(vector<string>& answerVec)
{
	for (int i = 0; i < answerVec.size(); i++)
	{
		answers.push_back(answerVec[i]);
	}
	return;
}

/*���ܣ��õ����Ӧ�Ļش�
  ������
        i--�˻ش��ڻش������е�����
  ����ֵ��
        answer[i]--�ش�
*/
string Robot::getOneAnsw(int i)
{
	return answers[i];
}

/*���ܣ��õ����Ӧ������
  ������
        i--�����������������е�����
  ����ֵ��
        question[i]--����
*/
string Robot::getOneQues(int i)
{
	return questions[i];
}

/*���ܣ��õ�����������
  ��������
  ����ֵ��
        name--����������
*/
string Robot::getName()
{
	return name;
}

/*���ܣ��õ����������˵�����
  ��������
  ����ֵ��
        masterName--���������˵�����
*/
string Robot::getMasterName()
{
	return masterName;
}

/*���ܣ��õ������˵�����
  ��������
  ����ֵ����
*/
void Robot::setName()
{
	cout << "��������ƺ��Է������֣�";
	cin >> name;
	return;
}

/*���ܣ��õ����������˵�����
  ��������
  ����ֵ����
*/
void Robot::setMasterName()
{
	cout << "�����������öԷ��ƺ�������֣�";
	cin >> masterName;
	return;
}