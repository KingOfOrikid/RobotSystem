#pragma warning(disable:4996)
#include "Operate.h"
#include "Users.h"
#include "SystemWork.h"
#include "Robot.h"
#include "BookKeeping.h"
#include "FileManage.h"


using namespace std;

void menu(char& choose);
void initialization();
int main()
{
	Operate op("C:\\Users\\yuki\\Desktop\\RobotSystem\\RobotSystem\\test.txt");
	char choose = 0;
	int num = 0;
	bool sign=false;
	while (true)
	{
		menu(choose);
		switch (choose)
		{
		case '1':
			num=op.circularLogin();
			sign = true;
			break;
		case '2':
			op.registered();
			system("cls");
			break;
		case '3':
			op.circularChange();
			system("cls");
			break;
		case '4':
			cout << "88!" << endl;
			exit(0);
			break;
		default:
			cout << "请输入有效的操作项！" << endl;
			exit(0);
			break;
		}
		if (choose=='4'||choose=='1')
		{
			break;
		}
	}
	initialization();
	if (choose=='1'&&sign ==true)
	{
		while (true)
		{
			system("cls");//清屏
			cout << "请选择要聊天的对象：1-机器男朋友   2-叨叨记账" << endl;
			cin >> choose;
			if (choose == '1')
			{
				SystemWork sys("C:\\Users\\yuki\\Desktop\\RobotSystem\\RobotSystem\\boyfriend.txt");
				sys.boyfriend(num, op.usingUser);
				cout << op.usingUser.getAllIntegral() << endl;
				sys.saveTxt("C:\\Users\\yuki\\Desktop\\RobotSystem\\RobotSystem\\boyfriend.txt", op.usingUser);
				/*string word = op.usingUser.getAllName() + "," + op.usingUser.getAllPassword() + "," + to_string(op.usingUser.getAllIntegral()) + "\n";
				char w[128];
				strcpy(w, word.c_str());
				sys.modifyContentInFile("C:\\Users\\yuki\\Desktop\\RobotSystem\\RobotSystem\\boyfriend.txt", num + 1, w);*/
			}
			else if (choose == '2')
			{
				BookKeeping book("C:\\Users\\yuki\\Desktop\\RobotSystem\\RobotSystem\\Income.txt", "C:\\Users\\yuki\\Desktop\\RobotSystem\\RobotSystem\\Outlay.txt");
				book.show();
				choose = book.begin();
				if (choose == 1)
				{
					book.outlay();
				}
				else if (choose == 2)
				{
					book.income();
				}
				string fileIn = op.usingUser.getAllName() + "In.txt", fileOut = op.usingUser.getAllName() + "Out.txt";
				book.storeTxt(fileIn, fileOut);
				break;
			}
			else
			{
				cout << "请输入正确的选项！" << endl;
				Sleep(300);
				continue;
			}
		}
		
	}
	return 0;
}

void menu(char& choose)
{
	cout << "========欢迎进入机器人聊天系统========" << endl;
	cout << "1.登录    2.注册    3.重置密码    4.退出" << endl;
	cout << "请选择：";
	cin >> choose;
	return;
}

void initialization()
{
	cout << "机器人初始化中";
	for (int i = 0; i < 6; i++)
	{
		cout << ".";
		Sleep(500);
	}
	return;
}