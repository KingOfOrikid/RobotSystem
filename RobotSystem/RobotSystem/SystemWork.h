#pragma once
#pragma warning(disable:4996)//ʹctimeΪ��ȫ��
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
	void store(vector<string>& answersVec, vector<string>& questionsVec);//����˻����˵�����ͻش�
	void modifyContentInFile(char *fileName, int lineNum, char *content);//�޸��ļ�ĳ������
	void saveTxt(const string& file,Users& usinguser);//�����ָĹ������Ϣ�����txt��
	string charToStr(char * contentChar);//�ַ���ת��str����
	void getAndJudgeTime();//��õ�ǰ����ʱ�䲢��ʱ��������жϵó��ش�
	string getTime();//��õ�ǰ����ʱ��
	bool find(Robot& robot,vector<string>& StoredVec, string& enteredWord);//�������йؼ��ʲ�������
	bool exchangeLife(Robot& robot, char& choose, Users& usinguser);//�û�ѡ���˳����˳�����ѡ���ֵ����г�ֵ����
	char lifeEmpty();//����������ֵ�ľ�ʱ���û���ѡ��
	void boyfriend(int& num, Users& usinguser);//���������������й���

private:
	Robot robot;//������
	bool flag, sign;
	string enteredWord;//����Ļ�
	char choose;
	int lifeChange;//�ı������ֵ
	char buf[128] = { 0 };//����ʱ�������
	Users user;
};

