#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <conio.h>

using namespace std;
class StringOp
{
public:
	StringOp();
	~StringOp();

public:
	static void split(const string& s, const string& delim, vector<string>& reVec);//切割字符串
	static string RePrint(int pwnum, string inputstr);//用空格替换最后一个*字符并截除密码最右字符
	static string passwordFormat(char ch);//密码格式(可删除字符)
};

