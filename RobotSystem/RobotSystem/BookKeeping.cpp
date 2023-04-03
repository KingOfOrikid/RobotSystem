#include "BookKeeping.h"
#include "StringOp.h"
#include "FileManage.h"
#include "Operate.h"


BookKeeping::BookKeeping(const string& file1,const string& file2)
{
	ifstream infile1,infile2;
	infile1.open(file1.data());
	infile2.open(file2.data());
	assert(infile1.is_open());  
	assert(infile2.is_open()); //若失败,则输出错误消息,并终止程序运行 
	string line1,line2;
	while (getline(infile1, line1))
	{
		vector<string> strVec;
		StringOp::split(line1, "/", strVec);//将txt文件中的数据成行输出并按切割符号切割成部分数据储存到strVec数组中
		if (strVec.size() >= 2)//如果录入数组数量大于二（即无信息缺失）
		{
			incomeQVec.push_back(strVec[0]);
			incomeAVec.push_back(strVec[1]);
		}
		else
		{
			cout << "信息缺失！" << endl;
		}
	}
	infile1.close();//关闭文件
	while (getline(infile2, line2))
	{
		vector<string> strVec;
		StringOp::split(line2, "/", strVec);//将txt文件中的数据成行输出并按切割符号切割成部分数据储存到strVec数组中
		if (strVec.size() >= 2)//如果录入数组数量大于二（即无信息缺失）
		{
			outlayQVec.push_back(strVec[0]);
			outlayAVec.push_back(strVec[1]);
		}
		else
		{
			cout << "信息缺失！" << endl;
		}
	}
	infile2.close();//关闭文件
}


BookKeeping::~BookKeeping()
{
}

/*功能：命名过程
  参数：无
  返回值：无
*/
void BookKeeping::show()
{
	cout << "你想喊叨叨的名字:";
	cin >> name;
	cout << "你想被叨叨称为:";
	cin >> masterName;
}

/*功能：记账开始，选择"花钱"或"挣钱"
  参数：无
  返回值：
        choose--用户的记账选择
*/
int BookKeeping::begin()
{
	while (true)
	{
		cout << name << ":今天乱花钱了还是挣钱了？" << endl;
		cout << masterName << ":";
		cin >> tempWord;
		if (tempWord.find("花钱") != string::npos)
		{
			choose = 1;
			break;
		}
		else if (tempWord.find("挣钱") != string::npos)
		{
			choose = 2;
			break;
		}
		else
		{
			cin.clear();
			cin.ignore();
			cout << name << ":你没有好好回答我的问题哦" << endl;
		}
	}
	return choose;
}

/*功能：储存支出
  参数：
        detail--支出的名称
		num--支出的数量
  返回值：无
*/
void BookKeeping::storeOut(string& detail, int& num)
{
	string tempWord = detail + ":" + to_string(num) + "。";
	storeOutVec.push_back(tempWord);
}

/*功能：储存收入
  参数：
        detail--收入的名称
        num--收入的数量
  返回值：无
*/
void BookKeeping::storeIn(string& detail, int& num)
{
	string tempWord = detail + ":" + to_string(num) + "。";
	storeInVec.push_back(tempWord);
}

/*功能：选择"花钱"后，支出过程
  参数：无
  返回值：无
*/
void BookKeeping::outlay()
{
	while (true)
	{
		cout << name << ":钱花在哪里了" << endl;
		cout << masterName << ":";
		cin >> detail;
		int temp = 0;
		for (int i = 0; i < outlayQVec.size(); i++)
		{
			if (detail.find(outlayQVec[i]) != string::npos)
			{
L1:				cout << name << ":花了多少钱啊" << endl;
				cout << masterName << ":";
				cin >> numOfDetail;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout << "请输入数字！" << endl;
					goto L1;
					break;
				}
				else
				{
					cout << name << ":" << outlayAVec[i] << endl;
					storeOut(outlayQVec[i], numOfDetail);
					temp = 0;
					break;
				}
			}
			else if (detail.find("没了") != string::npos)
			{
				temp = 2;
				break;
			}
			else
			{
				continue;
			}
		}
		if (temp == 2)
		{
			break;
		}
	}
	return;
}

/*功能：选择"挣钱后"，收入过程
  参数：无
  返回值：无
*/
void BookKeeping::income()
{
	while (true)
	{
		cout << name << ":哪里挣到钱了" << endl;
		cout << masterName << ":";
		cin >> detail;
		int temp = 0;
		for (int i = 0; i < incomeQVec.size(); i++)
		{
			if (detail.find(incomeQVec[i]) != string::npos)
			{
L1:				cout << name << ":挣了多少钱啊" << endl;
				cout << masterName << ":";
				cin >> numOfDetail;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout << "请输入数字！" << endl;
					goto L1;
					break;
				}
				else
				{
					cout << name << ":" << incomeAVec[i] << endl;
					storeIn(incomeQVec[i], numOfDetail);
					temp = 0;
					break;
				}
			}
			else if (detail.find("没了") != string::npos)
			{
				temp = 2;
				break;
			}
			else
			{
				continue;
			}
		}
		if (temp == 2)
		{
			break;
		}
	}
	return;
}

/*功能：把支出和收入储存到txt文件中
  参数：
        incomeFile--收入文件
		outlayFile--支出文件
  返回值：无
*/
void BookKeeping::storeTxt(const string& incomeFile, const string outlayFile)
{
	for (int i = 0; i < storeInVec.size(); i++)
	{
		FileManage::writeTxt(incomeFile, storeInVec[i]+"\n");
	}
	for (int i = 0; i < storeOutVec.size(); i++)
	{
		FileManage::writeTxt(outlayFile, storeOutVec[i]+"\n");
	}
}