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
	static void split(const string& s, const string& delim, vector<string>& reVec);//�и��ַ���
	static string RePrint(int pwnum, string inputstr);//�ÿո��滻���һ��*�ַ����س����������ַ�
	static string passwordFormat(char ch);//�����ʽ(��ɾ���ַ�)
};

