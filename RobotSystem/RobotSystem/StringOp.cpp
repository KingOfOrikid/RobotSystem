#include "StringOp.h"



StringOp::StringOp()
{
}


StringOp::~StringOp()
{
}

/*���ܣ���ȡtxt�ļ��е��ַ����е����ݲ����շָ����ָ�
������
s--��Ҫ�ָ���ַ���
delim-���������ַ������ַ����ķָ�����
reVec-�����ַ�����vector����
����ֵ����
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

/*���ܣ��ÿո��滻���һ��*�ַ����س����������ַ�
  ������
        pwnm--����
		inputstr--����������
  ����ֵ��
        aa-�����������ִ���0λ��ʼ�ĳ���Ϊi���Ӵ� 
*/
string StringOp::RePrint(int pwnum, string inputstr)   
{
	cout << "\b ";//��ǰ��һ����꣬������һ���ո� 
	string aa = inputstr.substr(0, pwnum);       //��������������ִ���0λ��ʼ�ĳ���Ϊi���Ӵ� 
	return aa;
}

/*���ܣ������ʽ(��ɾ���ַ�)
  ������
        ch-װ������ַ�
  ����ֵ��
        password--���������
*/
string StringOp::passwordFormat(char ch)
{
	string password;
	int i = 0;
	while (1)
	{
		ch = _getch();
		if (ch == 13)   //�ж��Ƿ�Ϊ�س���
			break;
		if (ch == 8)  //�ж��Ƿ�Ϊ���˼�
		{
			i--;
			password = RePrint(i, password);
			cout << "\b"; //��ǰ��һ����꣬���� RePrint()�� cout<<"\b "�����Ŀո� 
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