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
	assert(infile2.is_open()); //��ʧ��,�����������Ϣ,����ֹ�������� 
	string line1,line2;
	while (getline(infile1, line1))
	{
		vector<string> strVec;
		StringOp::split(line1, "/", strVec);//��txt�ļ��е����ݳ�����������и�����и�ɲ������ݴ��浽strVec������
		if (strVec.size() >= 2)//���¼�������������ڶ���������Ϣȱʧ��
		{
			incomeQVec.push_back(strVec[0]);
			incomeAVec.push_back(strVec[1]);
		}
		else
		{
			cout << "��Ϣȱʧ��" << endl;
		}
	}
	infile1.close();//�ر��ļ�
	while (getline(infile2, line2))
	{
		vector<string> strVec;
		StringOp::split(line2, "/", strVec);//��txt�ļ��е����ݳ�����������и�����и�ɲ������ݴ��浽strVec������
		if (strVec.size() >= 2)//���¼�������������ڶ���������Ϣȱʧ��
		{
			outlayQVec.push_back(strVec[0]);
			outlayAVec.push_back(strVec[1]);
		}
		else
		{
			cout << "��Ϣȱʧ��" << endl;
		}
	}
	infile2.close();//�ر��ļ�
}


BookKeeping::~BookKeeping()
{
}

/*���ܣ���������
  ��������
  ����ֵ����
*/
void BookKeeping::show()
{
	cout << "���뺰߶߶������:";
	cin >> name;
	cout << "���뱻߶߶��Ϊ:";
	cin >> masterName;
}

/*���ܣ����˿�ʼ��ѡ��"��Ǯ"��"��Ǯ"
  ��������
  ����ֵ��
        choose--�û��ļ���ѡ��
*/
int BookKeeping::begin()
{
	while (true)
	{
		cout << name << ":�����һ�Ǯ�˻�����Ǯ�ˣ�" << endl;
		cout << masterName << ":";
		cin >> tempWord;
		if (tempWord.find("��Ǯ") != string::npos)
		{
			choose = 1;
			break;
		}
		else if (tempWord.find("��Ǯ") != string::npos)
		{
			choose = 2;
			break;
		}
		else
		{
			cin.clear();
			cin.ignore();
			cout << name << ":��û�кúûش��ҵ�����Ŷ" << endl;
		}
	}
	return choose;
}

/*���ܣ�����֧��
  ������
        detail--֧��������
		num--֧��������
  ����ֵ����
*/
void BookKeeping::storeOut(string& detail, int& num)
{
	string tempWord = detail + ":" + to_string(num) + "��";
	storeOutVec.push_back(tempWord);
}

/*���ܣ���������
  ������
        detail--���������
        num--���������
  ����ֵ����
*/
void BookKeeping::storeIn(string& detail, int& num)
{
	string tempWord = detail + ":" + to_string(num) + "��";
	storeInVec.push_back(tempWord);
}

/*���ܣ�ѡ��"��Ǯ"��֧������
  ��������
  ����ֵ����
*/
void BookKeeping::outlay()
{
	while (true)
	{
		cout << name << ":Ǯ����������" << endl;
		cout << masterName << ":";
		cin >> detail;
		int temp = 0;
		for (int i = 0; i < outlayQVec.size(); i++)
		{
			if (detail.find(outlayQVec[i]) != string::npos)
			{
L1:				cout << name << ":���˶���Ǯ��" << endl;
				cout << masterName << ":";
				cin >> numOfDetail;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout << "���������֣�" << endl;
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
			else if (detail.find("û��") != string::npos)
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

/*���ܣ�ѡ��"��Ǯ��"���������
  ��������
  ����ֵ����
*/
void BookKeeping::income()
{
	while (true)
	{
		cout << name << ":��������Ǯ��" << endl;
		cout << masterName << ":";
		cin >> detail;
		int temp = 0;
		for (int i = 0; i < incomeQVec.size(); i++)
		{
			if (detail.find(incomeQVec[i]) != string::npos)
			{
L1:				cout << name << ":���˶���Ǯ��" << endl;
				cout << masterName << ":";
				cin >> numOfDetail;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout << "���������֣�" << endl;
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
			else if (detail.find("û��") != string::npos)
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

/*���ܣ���֧�������봢�浽txt�ļ���
  ������
        incomeFile--�����ļ�
		outlayFile--֧���ļ�
  ����ֵ����
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