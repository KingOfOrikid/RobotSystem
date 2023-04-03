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
	assert(infile.is_open());  //��ʧ��,�����������Ϣ,����ֹ�������� 
	string line;
	while (getline(infile, line))
	{
		vector<string> strVec;
		StringOp::split(line, "/", strVec);//��txt�ļ��е����ݳ�����������и�����и�ɲ������ݴ��浽strVec������
		if (strVec.size() >=2)//���¼�������������ڶ���������Ϣȱʧ��
		{
			questionsVec.push_back(strVec[0]);
			answersVec.push_back(strVec[1]);
		}
		else
		{
			cout << "��Ϣȱʧ��" << endl;
		}
	}
	infile.close();//�ر��ļ�
	store(answersVec, questionsVec);
}



SystemWork::~SystemWork()
{
}

/*���ܣ�����˻����˵�����ͻش�
  ������
        answersVec--�ش�����
		questionsVec--��������
  ����ֵ����
*/
void SystemWork::store(vector<string>& answersVec,vector<string>& questionsVec)
{
	robot.storeAnsw(answersVec);
	robot.storeQues(questionsVec);
}

/*���ܣ��������йؼ��ʲ�������
  ������
        robot--��������Ļ�����
		StoredVec--Ҫ���ҵ�����
		enteredWord--Ҫ���ҵľ���
  ����ֵ��
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
		cout << "��֪������˵ɶ," << robot.getMasterName() << "���ǲ��Ƕ���,�������Եİ�" << endl;
	}
	return flag;
}

/*���ܣ������ָĹ������Ϣ�����txt��
  ������
        file--�ļ���
		usinguser--�Ĺ����ֵ��û�
  ����ֵ����
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

/* �޸��ļ�ĳ������
���룺�ļ��� fileName   �к�   lineNum ,�޸ĵ����� content
������ļ��� fileName
�޷���ֵ
tip��1,lineNum�ӵ�һ�п�ʼ 2.content��Ҫ���ϻ��з�
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

/* char*tostr  �ַ���ת��str����
���룺char * �ַ�����ַ
�����
����ֵ�� str���͵��ַ���
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

/*���ܣ���õ�ǰ����ʱ�䲢��ʱ��������жϵó��ش�
  ��������
  ����ֵ����
*/
void SystemWork::getAndJudgeTime()
{
	time_t t;  //��ʱ��  
	tm local; //����ʱ��   
	tm* gmt;   //��������ʱ��  
	t = time(NULL); //��ȡĿǰ��ʱ��  
	localtime_s(&local, &t); //תΪ����ʱ��  
	strftime(buf, 64, "%Y-%m-%d %H:%M:%S", &local);
	char hoursCh[2] = { buf[11] , buf[12] };
	int hours=0;
	hours = atoi(hoursCh);
	if ( 0 <= hours && hours < 6 )
	{
		cout << "�����ˣ�Ҫ���˯��";
	}
	else if (6 <= hours && hours <= 10)
	{
		cout << "�簲���ǵó��緹";
	}
	else if (11 <= hours && hours <= 16)
	{
		cout << "�簲�����극˯һ���";
	}
	else if (17 <= hours && hours <= 20)
	{
		cout << "��������";
	}
	else if (21 <= hours && hours <= 23)
	{
		cout << "����ҲҪ��˯Ŷ";
	}
	return;
	/*time_t timep;
	time(&timep); /*��ȡtime_t���͵ĵ�ǰʱ��*/
				  /*��gmtime��time_t���͵�ʱ��ת��Ϊstruct tm���͵�ʱ�䣬��û�о���ʱ��ת����UTCʱ��
	printf("%s", ctime(&timep));
	return;*/
}

/*���ܣ���õ�ǰ����ʱ��
  ��������
  ����ֵ��
        buf--ʱ������
*/
string SystemWork::getTime()
{
	time_t t;  //��ʱ��  
	tm local; //����ʱ��   
	tm* gmt;   //��������ʱ��  
	t = time(NULL); //��ȡĿǰ��ʱ��  
	localtime_s(&local, &t); //תΪ����ʱ��  
	strftime(buf, 64, "%Y-%m-%d %H:%M:%S", &local);
	return buf;
}

/*���ܣ����������������й���
  ������
        num--�û����û������е�����
		usinguser--����ʹ�õ��û�
  ����ֵ����
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

/*���ܣ��û�ѡ���˳����˳�����ѡ���ֵ����г�ֵ����
  ������
        robot--������
		choose--�û���ѡ��
		usinguser--����ʹ�õ��û�
  ����ֵ��
        sign
*/
bool SystemWork::exchangeLife(Robot& robot, char& choose, Users& usinguser)
{
	if (choose == '1')
	{
		cout << robot.getMasterName() << ":��ͻȻ���������ˣ�88��" << endl;
		saveTxt("C:\\Users\\yuki\\Desktop\\RobotSystem\\RobotSystem\\test.txt",usinguser);
		exit(0);
	}
	else if (choose == '2')
	{
L1:		cout << "����������һ�������ֵ��(һ����ֵ��Ӧʮ���֣��㵱ǰ����" << usinguser.getAllIntegral() << "����):";
		cin >> lifeChange;
		if (usinguser.getAllIntegral()<(lifeChange * 10))
		{
			cout << "��Ļ��ֲ�����" << endl;
			sign = false;
		}
		else if (lifeChange <= 0)
		{
			cin.clear();
			cin.ignore();
			cout << "���������0��������" << endl;
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
		cout << "��������Ч��ѡ�" << endl;
		sign = false;
	}
	return sign;
}

/*���ܣ�����������ֵ�ľ�ʱ���û���ѡ��
  ����:
  ����ֵ��
         choose--�û���ѡ��
*/
char SystemWork::lifeEmpty()
{
	cout << "�����˵�����ֵ�ľ�����ѡ��1-�˳����죬2-ʹ�û��ֳ�ֵ��";
	cin >> choose;
	return choose;
}