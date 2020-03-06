#include <iostream>
#include <cmath>

using namespace std;

//book:��ǣ�1��ʾ�Ϸ���0��ʾ���Ϸ�

struct //��������
{
	int x[8];
}Vec;

void Count()//����һ�μ���һ��
{
	static int count = 0;
	count++;
	cout << "-----  " << count <<"  -----"<< endl;
}

void initBook(int Book[8][8])//��ʼ���������
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Book[i][j] = 1;
		}
	}
}
void CopyBook(int newBook[8][8], int oldBook[8][8])//�����������飬���ڶ������Ƶ���һ����
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			newBook[i][j] = oldBook[i][j];
		}
	}
}

void MakeBook(int Book[8][8],int x, int y)//�������꣬ˢ�·Ƿ����
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

void PrintOut()//������
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			cout << (Vec.x[i] == j ? "# " : "0 ");
		cout << endl ;
	}
}
void queen(int step, int book[8][8])//�ؼ�������step���У�bookΪ���
{
	int newbook[8][8];
	if (step == 8)//�㶨������󷵻�
	{
		PrintOut();
		Count();
		return;
	}
	for (int j = 0; j < 8; j++)//����
	{
		if (book[step][j])//����ǺϷ�
		{
			Vec.x[step] = j;//��¼��

			CopyBook(newbook, book);//���ɱ�Ǳ���
			MakeBook(newbook, j, step);//ˢ�±��

			queen(step + 1, newbook);//�ݹ������һ��

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