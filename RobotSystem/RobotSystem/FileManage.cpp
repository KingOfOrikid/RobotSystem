#include "FileManage.h"



FileManage::FileManage()
{
}


FileManage::~FileManage()
{
}


/*���ܣ���txt�ļ���д������(����ԭ���ݻ�����׷��)
������
file--�ļ���ַ
word--��Ҫ��ӵ�����
*/
void FileManage::writeTxt(string file, string word)
{
	ofstream outfile(file, ios::app);//ios::app��ʾ��ԭ�ļ�ĩβ׷��
	if (!outfile) {
		cout << "Open the file failure...\n";
		exit(0);
	}
	outfile << word;//���ļ�д����
	outfile.close();//�ر��ļ�
	return;
}

/*���ܣ��½�һ��txt�ļ�
  ������
        file--�ļ���
  ����ֵ����
*/
void FileManage::renewFile(const string& file)
{
	ofstream fout(file);
	if (fout)// ��������ɹ�
	{ 
		fout.close(); // ִ���������ر��ļ����
	}
	return;
}

/*���ܣ����txt�ļ��е���������
������
fileName--��Ҫ��յ��ļ���ַ
����ֵ����
*/
void FileManage::fileEmpty(const string& fileName)
{
	fstream file(fileName, ios::out);
	return;
}