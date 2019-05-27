#include<iostream>
#include<conio.h>
#include <ctime>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include "Guest.h"
#include "Admin.h"

using namespace std;

HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

void Menu(int x, int y, int k, string s);
void Select(string, string, string);

bool checkFile(const char* file_name) {
	ifstream file;
	file.open(file_name);
	if (!file)
		return false;
	else
		return true;
}

void Menu(int x, int y, int k, string s)
{

	CONSOLE_CURSOR_INFO ci;

	SetConsoleCursorInfo(handle, &ci);
	COORD c;
	c.X = x; c.Y = y;
	SetConsoleCursorPosition(handle, c);
	SetConsoleTextAttribute(handle, k);
	for(int i=0; i<s.length(); ++i)
	cout << s[i];

	cout << endl;

}

void Select(string a, string b, string c)
{
	system("cls");
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // дескриптор окна
	COORD coord; // переменная, отвечающая за координаты в консоли

	HANDLE h_in = GetStdHandle(STD_INPUT_HANDLE); // дескриптор окна для работы с мышкой
	SetConsoleMode(h_in, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS); // установка режима использования мышки

	INPUT_RECORD all_events[256]; // массив событий, произошедших в консоли
	DWORD read_event; // переменная, в которую запишется количество

	Menu(10, 5, 10, a);
	Menu(10, 7, 10, b);
	Menu(10, 9, 10, c);

	while (1)
	{
		ReadConsoleInput(h_in, all_events, 256, &read_event); // получить все события, произошедшие в консоли
		for (int i = 0; i < read_event; i++) // пройтись по всем событиям
		{
			coord.X = all_events[i].Event.MouseEvent.dwMousePosition.X; // запомнить координаты мышки
			coord.Y = all_events[i].Event.MouseEvent.dwMousePosition.Y;
			all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED;

			if (coord.X > 10 && coord.X < 20 && coord.Y == 5)
			{
				Menu(10, 5, 2, a);
				Menu(10, 7, 10, b);
				Menu(10, 9, 10, c);
				if (coord.X > 10 && coord.X < 20 && coord.Y == 5 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)// если нажата левая кнопка мыши
				{
					if (checkFile("admin.txt"))
					{
						char ch;
						system("cls");
						cout << "ARE YOU NEW HERE? Y/N";
						ch = _getch();
						if (ch == 'y' || ch == 'Y')
						{
							system("cls");
							//user.RegisterNewUser();
						}
						else if (ch == 'n' || ch == 'N')
						{
							system("cls");
							//user.LogIn(log,pass);
						}
						else
							cout << "I THINK YOU HAVE MADE A MISTAKE!";
					}
				}
			}
			else if (coord.X > 10 && coord.X < 25 && coord.Y == 7)
			{
				Menu(10, 5, 10, a);
				Menu(10, 7, 2, b);
				Menu(10, 9, 10, c);
				if (coord.X > 10 && coord.X < 20 && coord.Y == 5 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)// если нажата левая кнопка мыши
				{
					if (checkFile("admin.txt")) 
					{
						//input your login
					}

					//else CreateAdmin();
				}
			}
			else if (coord.X > 10 && coord.X < 20 && coord.Y == 9)
			{
				Menu(10, 5, 10, a);
				Menu(10, 7, 10,b);
				Menu(10, 9, 2, c);
				if (coord.X > 10 && coord.X < 20 && coord.Y == 9 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)// если нажата левая кнопка мыши
				{
					exit(0);
				}
			}
		}
	}
}

int main(void)
{
	/*ИЗМЕНЕНИЕ РАЗМЕРА КОНСОЛИ
	+++++++++++++++++++++++++++++++++++++++++++++++++++++++
	HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD bufferSize = {80,50};
	SetConsoleScreenBufferSize(hWnd,bufferSize);
	+++++++++++++++++++++++++++++++++++++++++++++++++++++++
	OR
	system("mode con col=100 lines=50");*/

	system("title KATE`S TESTS");

	Admin admin;
	admin.CreateAdmin();

	Select("LOGIN AS GUEST", "LOGIN AS ADMIN", "EXIT");



	Sleep(INFINITE);


} 