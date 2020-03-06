#include <iostream>
#include <cmath>

using namespace std;

//book:标记，1表示合法，0表示不合法

struct //横坐标标记
{
	int x[8];
}Vec;

void Count()//调用一次计数一次
{
	static int count = 0;
	count++;
	cout << "-----  " << count <<"  -----"<< endl;
}

void initBook(int Book[8][8])//初始化标记数组
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Book[i][j] = 1;
		}
	}
}
void CopyBook(int newBook[8][8], int oldBook[8][8])//输入两个数组，将第二个复制到第一个中
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			newBook[i][j] = oldBook[i][j];
		}
	}
}

void MakeBook(int Book[8][8],int x, int y)//输入坐标，刷新非法标记
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (abs(i - y) == abs(j - x) || i == y || j == x )
			{
				Book[i][j] = 0;
			}
		}
	}
}

void PrintOut()//输出结果
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			cout << (Vec.x[i] == j ? "# " : "0 ");
		cout << endl ;
	}
}
void queen(int step, int book[8][8])//关键函数，step表行，book为标记
{
	int newbook[8][8];
	if (step == 8)//搞定，输出后返回
	{
		PrintOut();
		Count();
		return;
	}
	for (int j = 0; j < 8; j++)//遍历
	{
		if (book[step][j])//若标记合法
		{
			Vec.x[step] = j;//记录列

			CopyBook(newbook, book);//将旧标记备份
			MakeBook(newbook, j, step);//刷新标记

			queen(step + 1, newbook);//递归进入下一行

		}
	}
}

int main()
{
	int book[8][8];
	initBook(book);
	queen(0, book);
	return 0;
}