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
			cout << "��������Ч�Ĳ����" << endl;
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
			system("cls");//����
			cout << "��ѡ��Ҫ����Ķ���1-����������   2-߶߶����" << endl;
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
				cout << "��������ȷ��ѡ�" << endl;
				Sleep(300);
				continue;
			}
		}
		
	}
	return 0;
}

void menu(char& choose)
{
	cout << "========��ӭ�������������ϵͳ========" << endl;
	cout << "1.��¼    2.ע��    3.��������    4.�˳�" << endl;
	cout << "��ѡ��";
	cin >> choose;
	return;
}

void initialization()
{
	cout << "�����˳�ʼ����";
	for (int i = 0; i < 6; i++)
	{
		cout << ".";
		Sleep(500);
	}
	return;
}