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
	static void writeTxt(string file, string word); //向txt文件中写入内容(可在原内容基础上追加)
	static void renewFile(const string& file);//新建一个txt文件
	static void fileEmpty(const string& fileName);//清空txt文件中的所有内容
};

