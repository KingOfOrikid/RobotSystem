#include "Operate.h"
#include "Users.h"
#include "StringOp.h"
#include "FileManage.h"


Operate::Operate(const string&file)
{
	ifstream infile;
	infile.open(file.data());
	assert(infile.is_open());  //若失败,则输出错误消息,并终止程序运行 
	string line;
	int tempIntergral;//定义有关积分的中间变量
	while (getline(infile,line))
	{
		vector<string> strVec;
		StringOp::split(line, ",", strVec);//将txt文件中的数据成行输出并按切割符号切割成部分数据储存到strVec数组中
		if (strVec.size() >= 3)//如果录入数组数量大于三（即无信息缺失）
		{
			tempIntergral = atoi(strVec[2].c_str());//将string类型转化为int类型
			user.setInformation(strVec[0], strVec[1], tempIntergral);
			userVec.push_back(user);
		}
		else
		{
			cout << "信息缺失！" << endl;
		}
	}
	infile.close();//关闭文件
}

Operate::~Operate()
{
}

Operate::Operate()
{
}

/*功能：在输入的密码中查找分隔符，判断密码是否有效
  参数：
        enteredPassword--输入的密码
		delim--分隔符
  返回值：
        flag--密码有效则为false，无效则为true
*/
bool Operate::find(string& enteredPassword,const string& delim)
{
	string::size_type idx;
	idx = enteredPassword.find(delim);//在输入的密码中查找分隔符，判断密码是否有效
	if (idx==string::npos)
	{
		flag = false;
	}
	else
	{
		flag = true;
	}
	return flag;
}


/*功能：清空某字符串的内容
  参数：
        tempPassword--需要被清空的字符串
  返回值：无
*/
void Operate::clearValue(string& tempPassword)
{
	tempPassword = "";
	return;
}

/*功能：清空某字符的内容
  参数：
        ch--需要清空的字符
  返回值：无
*/
void Operate::clearValue(char& ch)
{
	ch = 0;
	return;
}

/*功能：登陆时提醒用户输入用户名与密码
  参数：
        name--用户名
		password--密码
  返回值：
*/
void Operate::show(string& name, string& password)
{
	cout << "请输入您的用户名：";
	//提示用户输入用户名
	cin >> name;
	cout << "请输入您的密码：";
	//提示用户输入密码
	return;
}

/*功能：提示让用户输入两次密码
参数：无
返回值：无
*/
void Operate::showPP()
{
	sign = false;
	while (sign==false)
	{
		clearValue(tempPassword);
		clearValue(registeredCh);
		cout << "请输入密码:";
		tempPassword=StringOp::passwordFormat(registeredCh);
		enteredPassword = tempPassword;
		sign = judgeEffectivenessOfP(enteredPassword, ",");
	}
		clearValue(tempPassword);
		clearValue(registeredCh);
		cout << "请再次输入密码：";
		tempPassword = StringOp::passwordFormat(registeredCh);
		clearValue(registeredCh);
}

/*功能：转化为密码格式
  参数：
        ch--转化为密码格式时需要的字符串
  返回值：
        tempPassword--输入的密码

string Operate::passwordFormat(char ch)
{
	while ((ch = _getch()) != 13)
	{
		tempPassword += ch;
		cout << "*";
	}//把密码转换成*输出
	cout << endl;
	return tempPassword;
}*/

/*功能：将需要录入的用户信息连接成一整句带分隔符的字符串便于录入txt文件
  参数：
        tempWord--装字符串的变量
  返回值：
        tempWord--装字符串的变量
*/
string Operate::formTempWord(string& tempWord)
{
	for (int i = 0; i < userVec.size(); i++)
	{
		if (i == userVec.size())
		{
			tempWord += userVec[i].getAllName() + "," + userVec[i].getAllPassword() + "," + to_string(userVec[i].getAllIntegral());
		}
		else
		{
			tempWord += userVec[i].getAllName() + "," + userVec[i].getAllPassword() + "," + to_string(userVec[i].getAllIntegral()) + "\n";

		}
	}
	return tempWord;
}

/*功能：判断密码与用户名是否正确
  参数：
        name--用户名
		password--密码
  返回值：
        flag--指示密码正确与否
*/
bool Operate::judgeNP(string name, string password)
{
	for (unsigned int i = 0; i < userVec.size(); i++)
	{
		if (name == userVec[i].getAllName() && password == userVec[i].getAllPassword())
			//如果用户名与密码正确
		{
			flag = true;
			break;
		}
		else
		{
			flag = false;
		}
	}
	//不正确则显示“用户名或密码错误”并重新输入
	return flag;
}

/*功能：判断注册时的用户名是否已被其他用户注册
  参数：
        name--注册时输入的用户名
  返回值：
        flag--用户名存在为错，不存在为正确
*/
bool Operate::judgeN(string& enteredName)
{
	for (int i = 0; i < userVec.size(); i++)
	{
		if (enteredName == userVec[i].getAllName())
		{
			cout << "用户名已存在！请重新输入" << endl;
			flag = false;
			break;
		}
		else
		{
			flag = true;
			continue;
		}
	}
	return flag;
}

/*功能：判断更改后的密码是否与原密码一致
  参数：
        password--更改后的密码
		num--此用户用户名对应的vector数组数
  返回值：
        flag--指示密码是否一致
*/
bool Operate::judgeP(string& password,int& num)
{
	if (password == userVec[num].getAllPassword())
		//如果输入密码与原密码一致
	{
		flag = false;
	}
	else
	{
		flag = true;
	}
	return flag;
}

/*功能：判断密码的字符数是否符合标准大于等于八字符
  参数：
        password--输入的密码
  返回值：
        sign--符合标准则返回正确
*/
bool Operate::judgeNumOfP(string& password)
{
	int num = password.size();
	if (num>=8)
	{
		sign = true;
	}
	else
	{
		sign = false;
	}
	return sign;
}

/*功能：判断密码是否符合标准，字符数量大于等于8且不可以包含“，”
  参数：
        password--输入的密码
		delim--分隔符
  返回值：
        sign--符合标准则返回正确
*/
bool Operate::judgeEffectivenessOfP(string& password,const string& delim)
{
	sign = judgeNumOfP(password);
	flag = find(password, ",");
	if (sign == false && flag == true)
	{
		cout << "密码数量必须大于等于8字符并且不可以包含\"" << delim << "\",请输入有效的密码！" << endl;
		sign = false;
	}
	else if (sign==false && flag==false)
	{
		cout << "密码数量必须大于等于8字符" << endl;
		sign = false;
	}
	else if (sign == true && flag == true)
	{
		cout << "密码不可以包含\"" << delim << "\",请输入有效密码" << endl;
		sign = false;
	}
	else if (sign == true && flag == false)
	{
		sign = true;
	}
	return sign;
}

/*功能：判断此用户名对应的是哪一个用户
  参数：
        name--用户名
  返回值：
        userNum--用户名对应的用户数
*/
int Operate::judgeWhichUser(string name)
{
	for (unsigned int i = 0; i < userVec.size(); i++)
	{
		if (name == userVec[i].getAllName())
			//如果用户名符合某用户的用户名
		{
			userNum = i;
			break;
		}
	}
	return userNum;
}

/*功能：登陆，显示登陆成功或密码错误
  参数：
        name--输入的用户名
		password--输入的密码
  返回值：
        flag--用户名或密码错误则显示返回false
*/
bool Operate::logIn(string name, string password)
{
	clearValue(tempPassword);
	show(name, password);
	tempPassword = StringOp::passwordFormat(logInCh);
	password = tempPassword;
	judgeNP(name, password);
	if (flag)
	{
		cout << "登录成功！" << endl;
		userNum=judgeWhichUser(name);
		usingUser.setInformation(name, password, userVec[userNum].getAllIntegral());
	}
	//显示“登陆成功”
	else
	{
		cout << "用户名或密码错误！" << endl;
		flag = false;
	}
	return flag;
}

/*功能：循环登陆，即用户名与密码最多错误三次
  参数：无
  返回值：
         flag--用户名或密码错误则返回false
*/
int Operate::circularLogin()
{
	error = 0;
	while (error<3)
	{
		logIn(enteredName, enteredPassword);
		if (flag == false)
		{
			error++;
		}
		else
		{
			break;
		}
	}
	if (error == 3)
	{
		cout << "错误次数过多！" << endl;
		exit(0);//直接退出系统
	}
	return userNum;
}

/*功能：循环更改密码，即在用户名密码正确的前提下，需输入两次相同的密码，更改密码成功即存入对应数组及txt文件中，用户名与密码错误不得大于三次
  参数：无
  返回值：无
*/
void Operate::circularChange()
{
	error = 0;
	while (error<3)
	{
		show(enteredName, enteredPassword);
		userNum=judgeWhichUser(enteredName);
		tempPassword = StringOp::passwordFormat(changeCh);
		enteredPassword = tempPassword;
		clearValue(changeCh);
		flag=judgeNP(enteredName, enteredPassword);
		clearValue(tempPassword);
		string tempPas1, tempPas2;
		if (flag == true)
		{
L1:			clearValue(tempPassword);
			cout << "请输入你更改后的密码：";
			//提示用户输入更改后的密码
			tempPassword = StringOp::passwordFormat(changeCh);
			tempPas1 = tempPassword;
			sign = judgeEffectivenessOfP(tempPas1, ",");
			if (sign==false)
			{
				goto L1;
			}
			else
			{
				judgeP(tempPas1, userNum);
				if (flag == false)
				{
					cout << "输入密码不能与原密码一致" << endl;
					goto L1;
				}
				//如果输入密码与原密码相同则要求重新输入
				else
				{
					clearValue(tempPassword);
					cout << "请再次输入密码：";
					tempPassword = StringOp::passwordFormat(changeCh);
					clearValue(changeCh);
					tempPas2 = tempPassword;
					if (tempPas2 == tempPas1)
					{
						cout << "更改成功！" << endl;
						//如果两次密码一致显示“更改成功”
						userVec[userNum].changePassword(tempPas1);
						FileManage::fileEmpty("C:\\Users\\yuki\\Desktop\\RobotSystem\\RobotSystem\\test.txt");
						string tempWord = "";
						formTempWord(tempWord);
						FileManage::writeTxt("C:\\Users\\yuki\\Desktop\\RobotSystem\\RobotSystem\\test.txt", tempWord);
						//将更改后的密码录入数组并保存到文件中
						break;
					}
					else
					{
						cout << "两次密码不一致！" << endl;
						goto L1;
					}
				}
			}
			
		}
		else
		{
			cout << "用户名或者密码错误！" << endl;
			//显示“您输入的用户名或密码错误”
			flag = false;
			//重新输入密码
			if (flag == false)
			{
				error++;
			}
			else
			{
				break;
			}
		}
	}
	if (error == 3)
	{
		cout << "错误次数过多！请退出系统！" << endl;
		exit(0);//直接退出系统
	}
	return;
}

/*功能：注册，需输入此前不存在的用户名，用户名与密码存入数组及txt文件中
  参数：无
  返回值：无
*/
void Operate::registered()
{
L2:	cout << "请输入新的用户名：";
	cin >> enteredName;
	judgeN(enteredName);
	if (flag==false)
	{
		goto L2;
	}
	else
	{
		while (true)
		{
			showPP();
			if (tempPassword == enteredPassword)
			{
				cout << "注册成功！" << endl;
				user.setInformation(enteredName, enteredPassword, 100);
				userVec.push_back(user);
				string tempWord;
				tempWord = userVec[userVec.size()-1].getAllName() + "," + userVec[userVec.size()-1].getAllPassword() + "," + to_string(userVec[userVec.size()-1].getAllIntegral());
				FileManage::writeTxt("C:\\Users\\yuki\\Desktop\\RobotSystem\\RobotSystem\\test.txt", tempWord);
				FileManage::writeTxt("C:\\Users\\yuki\\Desktop\\RobotSystem\\RobotSystem\\test.txt", "\n");
				break;
			}
			else
			{
				cout << "两次输入密码不一致！" << endl;
			}
		}
	}
}