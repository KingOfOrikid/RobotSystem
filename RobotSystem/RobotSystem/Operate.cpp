#include "Operate.h"
#include "Users.h"
#include "StringOp.h"
#include "FileManage.h"


Operate::Operate(const string&file)
{
	ifstream infile;
	infile.open(file.data());
	assert(infile.is_open());  //��ʧ��,�����������Ϣ,����ֹ�������� 
	string line;
	int tempIntergral;//�����йػ��ֵ��м����
	while (getline(infile,line))
	{
		vector<string> strVec;
		StringOp::split(line, ",", strVec);//��txt�ļ��е����ݳ�����������и�����и�ɲ������ݴ��浽strVec������
		if (strVec.size() >= 3)//���¼������������������������Ϣȱʧ��
		{
			tempIntergral = atoi(strVec[2].c_str());//��string����ת��Ϊint����
			user.setInformation(strVec[0], strVec[1], tempIntergral);
			userVec.push_back(user);
		}
		else
		{
			cout << "��Ϣȱʧ��" << endl;
		}
	}
	infile.close();//�ر��ļ�
}

Operate::~Operate()
{
}

Operate::Operate()
{
}

/*���ܣ�������������в��ҷָ������ж������Ƿ���Ч
  ������
        enteredPassword--���������
		delim--�ָ���
  ����ֵ��
        flag--������Ч��Ϊfalse����Ч��Ϊtrue
*/
bool Operate::find(string& enteredPassword,const string& delim)
{
	string::size_type idx;
	idx = enteredPassword.find(delim);//������������в��ҷָ������ж������Ƿ���Ч
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


/*���ܣ����ĳ�ַ���������
  ������
        tempPassword--��Ҫ����յ��ַ���
  ����ֵ����
*/
void Operate::clearValue(string& tempPassword)
{
	tempPassword = "";
	return;
}

/*���ܣ����ĳ�ַ�������
  ������
        ch--��Ҫ��յ��ַ�
  ����ֵ����
*/
void Operate::clearValue(char& ch)
{
	ch = 0;
	return;
}

/*���ܣ���½ʱ�����û������û���������
  ������
        name--�û���
		password--����
  ����ֵ��
*/
void Operate::show(string& name, string& password)
{
	cout << "�����������û�����";
	//��ʾ�û������û���
	cin >> name;
	cout << "�������������룺";
	//��ʾ�û���������
	return;
}

/*���ܣ���ʾ���û�������������
��������
����ֵ����
*/
void Operate::showPP()
{
	sign = false;
	while (sign==false)
	{
		clearValue(tempPassword);
		clearValue(registeredCh);
		cout << "����������:";
		tempPassword=StringOp::passwordFormat(registeredCh);
		enteredPassword = tempPassword;
		sign = judgeEffectivenessOfP(enteredPassword, ",");
	}
		clearValue(tempPassword);
		clearValue(registeredCh);
		cout << "���ٴ��������룺";
		tempPassword = StringOp::passwordFormat(registeredCh);
		clearValue(registeredCh);
}

/*���ܣ�ת��Ϊ�����ʽ
  ������
        ch--ת��Ϊ�����ʽʱ��Ҫ���ַ���
  ����ֵ��
        tempPassword--���������

string Operate::passwordFormat(char ch)
{
	while ((ch = _getch()) != 13)
	{
		tempPassword += ch;
		cout << "*";
	}//������ת����*���
	cout << endl;
	return tempPassword;
}*/

/*���ܣ�����Ҫ¼����û���Ϣ���ӳ�һ������ָ������ַ�������¼��txt�ļ�
  ������
        tempWord--װ�ַ����ı���
  ����ֵ��
        tempWord--װ�ַ����ı���
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

/*���ܣ��ж��������û����Ƿ���ȷ
  ������
        name--�û���
		password--����
  ����ֵ��
        flag--ָʾ������ȷ���
*/
bool Operate::judgeNP(string name, string password)
{
	for (unsigned int i = 0; i < userVec.size(); i++)
	{
		if (name == userVec[i].getAllName() && password == userVec[i].getAllPassword())
			//����û�����������ȷ
		{
			flag = true;
			break;
		}
		else
		{
			flag = false;
		}
	}
	//����ȷ����ʾ���û�����������󡱲���������
	return flag;
}

/*���ܣ��ж�ע��ʱ���û����Ƿ��ѱ������û�ע��
  ������
        name--ע��ʱ������û���
  ����ֵ��
        flag--�û�������Ϊ��������Ϊ��ȷ
*/
bool Operate::judgeN(string& enteredName)
{
	for (int i = 0; i < userVec.size(); i++)
	{
		if (enteredName == userVec[i].getAllName())
		{
			cout << "�û����Ѵ��ڣ�����������" << endl;
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

/*���ܣ��жϸ��ĺ�������Ƿ���ԭ����һ��
  ������
        password--���ĺ������
		num--���û��û�����Ӧ��vector������
  ����ֵ��
        flag--ָʾ�����Ƿ�һ��
*/
bool Operate::judgeP(string& password,int& num)
{
	if (password == userVec[num].getAllPassword())
		//�������������ԭ����һ��
	{
		flag = false;
	}
	else
	{
		flag = true;
	}
	return flag;
}

/*���ܣ��ж�������ַ����Ƿ���ϱ�׼���ڵ��ڰ��ַ�
  ������
        password--���������
  ����ֵ��
        sign--���ϱ�׼�򷵻���ȷ
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

/*���ܣ��ж������Ƿ���ϱ�׼���ַ��������ڵ���8�Ҳ����԰���������
  ������
        password--���������
		delim--�ָ���
  ����ֵ��
        sign--���ϱ�׼�򷵻���ȷ
*/
bool Operate::judgeEffectivenessOfP(string& password,const string& delim)
{
	sign = judgeNumOfP(password);
	flag = find(password, ",");
	if (sign == false && flag == true)
	{
		cout << "��������������ڵ���8�ַ����Ҳ����԰���\"" << delim << "\",��������Ч�����룡" << endl;
		sign = false;
	}
	else if (sign==false && flag==false)
	{
		cout << "��������������ڵ���8�ַ�" << endl;
		sign = false;
	}
	else if (sign == true && flag == true)
	{
		cout << "���벻���԰���\"" << delim << "\",��������Ч����" << endl;
		sign = false;
	}
	else if (sign == true && flag == false)
	{
		sign = true;
	}
	return sign;
}

/*���ܣ��жϴ��û�����Ӧ������һ���û�
  ������
        name--�û���
  ����ֵ��
        userNum--�û�����Ӧ���û���
*/
int Operate::judgeWhichUser(string name)
{
	for (unsigned int i = 0; i < userVec.size(); i++)
	{
		if (name == userVec[i].getAllName())
			//����û�������ĳ�û����û���
		{
			userNum = i;
			break;
		}
	}
	return userNum;
}

/*���ܣ���½����ʾ��½�ɹ����������
  ������
        name--������û���
		password--���������
  ����ֵ��
        flag--�û����������������ʾ����false
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
		cout << "��¼�ɹ���" << endl;
		userNum=judgeWhichUser(name);
		usingUser.setInformation(name, password, userVec[userNum].getAllIntegral());
	}
	//��ʾ����½�ɹ���
	else
	{
		cout << "�û������������" << endl;
		flag = false;
	}
	return flag;
}

/*���ܣ�ѭ����½�����û�������������������
  ��������
  ����ֵ��
         flag--�û�������������򷵻�false
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
		cout << "����������࣡" << endl;
		exit(0);//ֱ���˳�ϵͳ
	}
	return userNum;
}

/*���ܣ�ѭ���������룬�����û���������ȷ��ǰ���£�������������ͬ�����룬��������ɹ��������Ӧ���鼰txt�ļ��У��û�����������󲻵ô�������
  ��������
  ����ֵ����
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
			cout << "����������ĺ�����룺";
			//��ʾ�û�������ĺ������
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
					cout << "�������벻����ԭ����һ��" << endl;
					goto L1;
				}
				//�������������ԭ������ͬ��Ҫ����������
				else
				{
					clearValue(tempPassword);
					cout << "���ٴ��������룺";
					tempPassword = StringOp::passwordFormat(changeCh);
					clearValue(changeCh);
					tempPas2 = tempPassword;
					if (tempPas2 == tempPas1)
					{
						cout << "���ĳɹ���" << endl;
						//�����������һ����ʾ�����ĳɹ���
						userVec[userNum].changePassword(tempPas1);
						FileManage::fileEmpty("C:\\Users\\yuki\\Desktop\\RobotSystem\\RobotSystem\\test.txt");
						string tempWord = "";
						formTempWord(tempWord);
						FileManage::writeTxt("C:\\Users\\yuki\\Desktop\\RobotSystem\\RobotSystem\\test.txt", tempWord);
						//�����ĺ������¼�����鲢���浽�ļ���
						break;
					}
					else
					{
						cout << "�������벻һ�£�" << endl;
						goto L1;
					}
				}
			}
			
		}
		else
		{
			cout << "�û��������������" << endl;
			//��ʾ����������û������������
			flag = false;
			//������������
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
		cout << "����������࣡���˳�ϵͳ��" << endl;
		exit(0);//ֱ���˳�ϵͳ
	}
	return;
}

/*���ܣ�ע�ᣬ�������ǰ�����ڵ��û������û���������������鼰txt�ļ���
  ��������
  ����ֵ����
*/
void Operate::registered()
{
L2:	cout << "�������µ��û�����";
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
				cout << "ע��ɹ���" << endl;
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
				cout << "�����������벻һ�£�" << endl;
			}
		}
	}
}