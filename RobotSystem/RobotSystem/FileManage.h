#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class FileManage
{
public:
	FileManage();
	~FileManage();

public:
	static void writeTxt(string file, string word); //��txt�ļ���д������(����ԭ���ݻ�����׷��)
	static void renewFile(const string& file);//�½�һ��txt�ļ�
	static void fileEmpty(const string& fileName);//���txt�ļ��е���������
};

