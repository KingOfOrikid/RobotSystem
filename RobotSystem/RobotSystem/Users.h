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
	string name;//�û��û���
	string password;//�û�����
	int integral;//�û�����

public:
	void userTestShow();//���Թ����п���Ϣ�Ƿ�¼��
	void setInformation(string name, string password, int intergral);//�����������롢���ִ��浽���û������������롢���ֱ�����
	void entryLoginInformation(string name, string password);//�����û���Ϣ
	string getAllName();//����û����û���
	string getAllPassword();//����û�������
	int getAllIntegral();//����û��Ļ���
	void changePassword(string password);//��������
	void changeIntegral(int integral);//���Ļ���
};

