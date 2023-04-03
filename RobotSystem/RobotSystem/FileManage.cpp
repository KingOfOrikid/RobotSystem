#include "FileManage.h"



FileManage::FileManage()
{
}


FileManage::~FileManage()
{
}


/*功能：向txt文件中写入内容(可在原内容基础上追加)
参数：
file--文件地址
word--需要添加的内容
*/
void FileManage::writeTxt(string file, string word)
{
	ofstream outfile(file, ios::app);//ios::app表示在原文件末尾追加
	if (!outfile) {
		cout << "Open the file failure...\n";
		exit(0);
	}
	outfile << word;//向文件写数据
	outfile.close();//关闭文件
	return;
}

/*功能：新建一个txt文件
  参数：
        file--文件名
  返回值：无
*/
void FileManage::renewFile(const string& file)
{
	ofstream fout(file);
	if (fout)// 如果创建成功
	{ 
		fout.close(); // 执行完操作后关闭文件句柄
	}
	return;
}

/*功能：清空txt文件中的所有内容
参数：
fileName--需要清空的文件地址
返回值：无
*/
void FileManage::fileEmpty(const string& fileName)
{
	fstream file(fileName, ios::out);
	return;
}