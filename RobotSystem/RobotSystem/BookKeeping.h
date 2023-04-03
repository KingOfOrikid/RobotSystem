#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cassert>

using namespace std;
class BookKeeping
{
public:
	BookKeeping(const string& file1, const string& file2);
	~BookKeeping();

public:
	void show();//��������
	int begin();//���˿�ʼ��ѡ��"��Ǯ"��"��Ǯ"
	void outlay();//ѡ��"��Ǯ"��֧������
	void income();//ѡ��"��Ǯ��"���������
	void storeOut(string& detail, int& num);//����֧��
	void storeIn(string& detail, int& num);//��������
	void storeTxt(const string& incomeFile, const string outlayFile);//��֧�������봢�浽txt�ļ���

private:
	vector<string> incomeQVec;//����ؼ�������
	vector<string> incomeAVec;//����ش�����
	vector<string> outlayQVec;//֧���ؼ�������
	vector<string> outlayAVec;//֧���ش�����
	string name,masterName;//߶߶�����˵�����
	string tempWord;
	int choose;
	string detail;//��ϸ
	int numOfDetail;//��ϸ�Ľ��

public:
	vector<string> storeOutVec;
	vector<string> storeInVec;;
};