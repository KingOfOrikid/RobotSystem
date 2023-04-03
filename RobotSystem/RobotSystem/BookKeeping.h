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
	void show();//命名过程
	int begin();//记账开始，选择"花钱"或"挣钱"
	void outlay();//选择"花钱"后，支出过程
	void income();//选择"挣钱后"，收入过程
	void storeOut(string& detail, int& num);//储存支出
	void storeIn(string& detail, int& num);//储存收入
	void storeTxt(const string& incomeFile, const string outlayFile);//把支出和收入储存到txt文件中

private:
	vector<string> incomeQVec;//收入关键词数组
	vector<string> incomeAVec;//收入回答数组
	vector<string> outlayQVec;//支出关键词数组
	vector<string> outlayAVec;//支出回答数组
	string name,masterName;//叨叨及主人的名字
	string tempWord;
	int choose;
	string detail;//明细
	int numOfDetail;//明细的金额

public:
	vector<string> storeOutVec;
	vector<string> storeInVec;;
};