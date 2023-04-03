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
	void clearValue(string& tempPassword); //���ĳ�ַ���������
	void clearValue(char& ch);//���ĳ�ַ�������
	void show(string& name, string& password);//��½ʱ�����û������û���������
	void showPP();//��ʾ���û�������������
	string formTempWord(string& tempWord);//����Ҫ¼����û���Ϣ���ӳ�һ������ָ������ַ�������¼��txt�ļ�
	bool judgeNP(string name, string password);//�ж��������û����Ƿ���ȷ
	bool judgeN(string& enteredName);//�ж�ע��ʱ���û����Ƿ��ѱ������û�ע��
	bool judgeP(string& password,int& num);//�жϸ��ĺ�������Ƿ���ԭ����һ��
	bool judgeNumOfP(string& password);//�ж�������ַ����Ƿ���ϱ�׼���ڵ��ڰ��ַ�
	bool judgeEffectivenessOfP(string& password, const string& delim);//�ж������Ƿ���ϱ�׼���ַ��������ڵ���8�Ҳ����԰���������
	int judgeWhichUser(string name);//�жϴ��û�����Ӧ������һ���û�
	bool logIn(string name, string password);//��½����ʾ��½�ɹ����������
	int circularLogin();//ѭ����½�����û�������������������
	void circularChange();//ѭ���������룬�����û���������ȷ��ǰ���£�������������ͬ�����룬��������ɹ��������Ӧ���鼰txt�ļ��У��û�����������󲻵ô�������
	void registered();//ע�ᣬ�������ǰ�����ڵ��û������û���������������鼰txt�ļ���

private:
	string enteredName;//������û���
	string enteredPassword;//���������
	int error;//�������
	bool flag,sign;//�ж��������������������
	char logInCh;//��¼��ת�������ʽ���ַ�
	char changeCh;//��������ת�������ʽ���ַ�
	char registeredCh;//ע����ת�������ʽ���ַ�
	string tempPassword;//ת�������ʽ���õ��м��������

protected:
	vector<Users> userVec;//�ļ���ԭ��������û�
	int userNum;//�û�����Ӧ���û���

public:
	Users usingUser;//����ʹ�õ��û�
	Users user;
};

