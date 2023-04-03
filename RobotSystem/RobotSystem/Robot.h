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
	string name;//�����˵�����
	string masterName;//���������˵�����
	char choice;//ѡ��
	int lifeValue;//����ֵ

public:
	int getLife();//�õ�����ֵ
	void changeLife(int& value);// �ı�����ֵ
	void storeQues(vector<string>& questions);//��������
	void storeAnsw(vector<string>& answerVec);//����ش�
	string getOneAnsw(int i);//�õ����Ӧ�Ļش�
	string getOneQues(int i);//�õ����Ӧ������
	string getName();//�õ�����������
	string getMasterName();//�õ����������˵�����
	void setName();//�õ������˵�����
	void setMasterName();//�õ����������˵�����

protected:
	vector<string> questions;//��������
	vector<string> answers;//�ش�����
};

