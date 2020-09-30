#include<iostream>
#include <conio.h>
#include<fstream>
#include <windows.h>
using namespace std;
void SetColor(int col)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}
void SetPos(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
int Menu(string menu_items[], int SIZE)
{
	int key = 0;int code;
	do 
	{system("cls");
	key = (key + SIZE) % SIZE;
	for (int i = 0; i < SIZE; i++)
	{
		SetPos(20, 5 + i);
		if (key == i)
		{
			cout << " ";
			SetColor(6);
			cout << menu_items[i];
			SetColor(3); 
			cout << " " << endl;
			SetColor(15);}
		else
		{
			cout << " ";
			cout << menu_items[i];
			cout << " " << endl;
		}
	}
	code = _getch();
	if (code == 224)
	{code = _getch();
	if (code == 80) key++;
	if (code == 72) key--;
	}
	} while (code != 13);
	system("cls");
	return key;
}
void main()
{
	string menu[] = { "1.+","2.-","3.*","4./" };
	Menu(menu, size(menu));
}