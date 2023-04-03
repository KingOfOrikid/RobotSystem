#include "StringOp.h"



StringOp::StringOp()
{
}


StringOp::~StringOp()
{
}

/*功能：读取txt文件中的字符串中的数据并按照分隔符分割
参数：
s--需要分割的字符串
delim-用来区分字符串与字符串的分隔符号
reVec-储存字符串的vector数组
返回值：无
*/
void StringOp::split(const string& s, const string& delim, vector<string>& reVec)
{
	size_t begin = 0;
	size_t index = s.find_first_of(delim, begin);

	while (index != string::npos)
	{
		string sub = s.substr(begin, index - begin);
		reVec.push_back(sub);
		begin = index + 1;
		index = s.find_first_of(delim, begin);
	}
	if (index - begin>0)
	{
		string sub = s.substr(begin, index - begin);
		reVec.push_back(sub);
	}
	return;
}

/*功能：用空格替换最后一个*字符并截除密码最右字符
  参数：
        pwnm--长度
		inputstr--已输入密码
  返回值：
        aa-已输入密码字串第0位开始的长度为i的子串 
*/
string StringOp::RePrint(int pwnum, string inputstr)   
{
	cout << "\b ";//向前移一个光标，并输入一个空格 
	string aa = inputstr.substr(0, pwnum);       //获得已输入密码字串第0位开始的长度为i的子串 
	return aa;
}

/*功能：密码格式(可删除字符)
  参数：
        ch-装密码的字符
  返回值：
        password--输入的密码
*/
string StringOp::passwordFormat(char ch)
{
	string password;
	int i = 0;
	while (1)
	{
		ch = _getch();
		if (ch == 13)   //判断是否为回车键
			break;
		if (ch == 8)  //判断是否为后退键
		{
			i--;
			password = RePrint(i, password);
			cout << "\b"; //向前移一个光标，消除 RePrint()中 cout<<"\b "遗留的空格 
		}
		else
		{
			password += ch;
			cout << '*';
			i++;
		}
	}
	cout << endl;
	return password;
}