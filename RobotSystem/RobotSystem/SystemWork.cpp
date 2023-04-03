#include "SystemWork.h"
#include "FileManage.h"
#include "StringOp.h"

SystemWork::SystemWork()
{
}

SystemWork::SystemWork(const string&file)
{
	ifstream infile;
	infile.open(file.data());
	assert(infile.is_open());  //若失败,则输出错误消息,并终止程序运行 
	string line;
	while (getline(infile, line))
	{
		vector<string> strVec;
		StringOp::split(line, "/", strVec);//将txt文件中的数据成行输出并按切割符号切割成部分数据储存到strVec数组中
		if (strVec.size() >=2)//如果录入数组数量大于二（即无信息缺失）
		{
			questionsVec.push_back(strVec[0]);
			answersVec.push_back(strVec[1]);
		}
		else
		{
			cout << "信息缺失！" << endl;
		}
	}
	infile.close();//关闭文件
	store(answersVec, questionsVec);
}



SystemWork::~SystemWork()
{
}

/*功能：储存此机器人的问题和回答
  参数：
        answersVec--回答数组
		questionsVec--问题数组
  返回值：无
*/
void SystemWork::store(vector<string>& answersVec,vector<string>& questionsVec)
{
	robot.storeAnsw(answersVec);
	robot.storeQues(questionsVec);
}

/*功能：从数组中关键词查找问题
  参数：
        robot--储存问题的机器人
		StoredVec--要查找的数组
		enteredWord--要查找的句子
  返回值：
        flag
*/
bool SystemWork::find(Robot& robot,vector<string>& StoredVec, string& enteredWord)
{
	int temp = 0;
	for (int i = 0; i < StoredVec.size(); i++)
	{
		if (enteredWord.find(StoredVec[i])!=string::npos)
		{
			if (i==0)
			{
				cout << robot.getName() << ":";
				cout << robot.getOneAnsw(i) << robot.getMasterName() << ",";
				getAndJudgeTime();
				cout << endl;
			}
			else
			{
				cout << robot.getName() << ":";
				cout << robot.getOneAnsw(i) << endl;
			}
			temp = 1;
			break;
		}
	}
	if (temp==0)
	{
		cout << robot.getName() << ":";
		cout << "不知道你在说啥," << robot.getMasterName() << "你是不是饿了,给你买点吃的吧" << endl;
	}
	return flag;
}

/*功能：将积分改过后的信息储存进txt中
  参数：
        file--文件名
		usinguser--改过积分的用户
  返回值：无
*/
void SystemWork::saveTxt(const string& file, Users& usinguser)
{
	string word = usinguser.getAllName() + "," + usinguser.getAllPassword() + "," + to_string(usinguser.getAllIntegral()) ;
	char w[128];
	strcpy(w, word.c_str());
	char f[1024];
	strcpy(f, file.c_str());
	modifyContentInFile(f, userNum + 1, w);
}

/* 修改文件某行内容
输入：文件名 fileName   行号   lineNum ,修改的内容 content
输出：文件名 fileName
无返回值
tip：1,lineNum从第一行开始 2.content需要加上换行符
*/
void SystemWork::modifyContentInFile(char *fileName, int lineNum, char *content)
{
	ifstream in;
	char line[1024] = { '\0' };
	in.open(fileName);
	int i = 0;
	string tempStr;
	while (in.getline(line, sizeof(line)))
	{
		i++;
		if (lineNum != i)
		{
			tempStr += charToStr(line);
		}
		else
		{
			tempStr += charToStr(content);
		}
		tempStr += '\n';
	}
	in.close();
	ofstream out;
	out.open(fileName);
	out.flush();
	out << tempStr;
	out.close();
}

/* char*tostr  字符串转化str类型
输入：char * 字符串地址
无输出
返回值： str类型的字符串
*/
string SystemWork::charToStr(char * contentChar)
{
	string tempStr;
	for (int i = 0; contentChar[i] != '\0'; i++)
	{
		tempStr += contentChar[i];
	}
	return tempStr;
}

/*功能：获得当前本机时间并对时间段作出判断得出回答
  参数：无
  返回值：无
*/
void SystemWork::getAndJudgeTime()
{
	time_t t;  //秒时间  
	tm local; //本地时间   
	tm* gmt;   //格林威治时间  
	t = time(NULL); //获取目前秒时间  
	localtime_s(&local, &t); //转为本地时间  
	strftime(buf, 64, "%Y-%m-%d %H:%M:%S", &local);
	char hoursCh[2] = { buf[11] , buf[12] };
	int hours=0;
	hours = atoi(hoursCh);
	if ( 0 <= hours && hours < 6 )
	{
		cout << "很晚了，要早点睡觉";
	}
	else if (6 <= hours && hours <= 10)
	{
		cout << "早安，记得吃早饭";
	}
	else if (11 <= hours && hours <= 16)
	{
		cout << "午安，吃完饭睡一会吧";
	}
	else if (17 <= hours && hours <= 20)
	{
		cout << "吃晚饭了吗";
	}
	else if (21 <= hours && hours <= 23)
	{
		cout << "今天也要早睡哦";
	}
	return;
	/*time_t timep;
	time(&timep); /*获取time_t类型的当前时间*/
				  /*用gmtime将time_t类型的时间转换为struct tm类型的时间，按没有经过时区转换的UTC时间
	printf("%s", ctime(&timep));
	return;*/
}

/*功能：获得当前本机时间
  参数：无
  返回值：
        buf--时间数组
*/
string SystemWork::getTime()
{
	time_t t;  //秒时间  
	tm local; //本地时间   
	tm* gmt;   //格林威治时间  
	t = time(NULL); //获取目前秒时间  
	localtime_s(&local, &t); //转为本地时间  
	strftime(buf, 64, "%Y-%m-%d %H:%M:%S", &local);
	return buf;
}

/*功能：机器人男朋友运行过程
  参数：
        num--用户在用户数组中的行数
		usinguser--正在使用的用户
  返回值：无
*/
void SystemWork::boyfriend(int& num,Users& usinguser)
{
	userNum = num;
	Robot robot1(robot);
	robot1.setName();
	robot1.setMasterName();
	system("cls");
	cout << getTime() << endl;
	for (int i = 0; i <= robot1.getLife(); i++)
	{
		cout << robot1.getMasterName() << ":";
		cin >> enteredWord;
		find(robot1, questionsVec, enteredWord);
		if (i==robot1.getLife()-1)
		{
			while (true)
			{
				lifeEmpty();
				sign=exchangeLife(robot1, choose, usinguser);
				if (sign==true)
				{
					i = -1;
					break;
				}
				else
				{
					continue;
				}
			}	
		}
	}
	return;
}

/*功能：用户选择退出则退出程序，选择充值则进行充值过程
  参数：
        robot--机器人
		choose--用户的选择
		usinguser--正在使用的用户
  返回值：
        sign
*/
bool SystemWork::exchangeLife(Robot& robot, char& choose, Users& usinguser)
{
	if (choose == '1')
	{
		cout << robot.getMasterName() << ":我突然不想聊天了，88！" << endl;
		saveTxt("C:\\Users\\yuki\\Desktop\\RobotSystem\\RobotSystem\\test.txt",usinguser);
		exit(0);
	}
	else if (choose == '2')
	{
L1:		cout << "请输入你想兑换的生命值数(一生命值对应十积分，你当前还有" << usinguser.getAllIntegral() << "积分):";
		cin >> lifeChange;
		if (usinguser.getAllIntegral()<(lifeChange * 10))
		{
			cout << "你的积分不够！" << endl;
			sign = false;
		}
		else if (lifeChange <= 0)
		{
			cin.clear();
			cin.ignore();
			cout << "请输入大于0的整数！" << endl;
			goto L1;
		}
		else
		{
			int changes = usinguser.getAllIntegral() - (lifeChange * 10);
			robot.changeLife(lifeChange);
			usinguser.changeIntegral(changes);
			sign = true;
		}
	}
	else
	{
		cout << "请输入有效的选项！" << endl;
		sign = false;
	}
	return sign;
}

/*功能：机器人生命值耗尽时让用户作选择
  参数:
  返回值：
         choose--用户的选择
*/
char SystemWork::lifeEmpty()
{
	cout << "机器人的生命值耗尽！请选择：1-退出聊天，2-使用积分充值：";
	cin >> choose;
	return choose;
}