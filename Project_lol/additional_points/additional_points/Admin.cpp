#include "Admin.h"
#include"Test.h"
#include <fstream>

#include <iostream>

using namespace std;

void Admin::CreateAdmin()
{
	ofstream fout("admin.txt");
	login = "qwerty";
	password = "admin123";

	login = Encrypt(login);
	password = Encrypt(password);

	fout << login << password;

	//adminlog.insert({ login, password });
	fout.close();

}

void Admin:: ChangeLogPass()
{
	ofstream fout;
	fout.open("admin.txt", std::ofstream::out | std::ofstream::trunc); // truncate чтобы зачистить старые логин и пароль
	int choise;
	cout << "What do you want to change? 1-Login, 2-Password, 3-Both: ";
	cin >> choise;

	switch (choise)
	{
	case 1:
		cout << endl << "Enter new login: ";
		cin >> login;
		login = Encrypt(login);
		password = Encrypt(password);
		//adminlog[login] = password;
		fout << login << password;
		break;
	case 2:
		cout << endl << "Enter new password: ";
		cin >> password;
		login = Encrypt(login);
		password = Encrypt(password);
		//adminlog[login] = password;
		//adminlog.insert({ login, password });
		fout << login << password;
		break;
	case 3:
		cout << endl << "Enter new login: ";
		cin >> login;
		Encrypt(login);
		cout << endl << "Enter new password: ";
		cin >> password;
		Encrypt(password);
		//adminlog[login] = password;
		//adminlog.insert({ login, password });
		fout << login << password;
		break;
	default:
		cout << endl << "Looks like a mistake!" << endl;

	}
	fout.close();
}

void Admin::CreateUser(Guest* users)
{
	
}

void Admin::DeleteUser(Guest* users)
{

}

void Admin::ShowStats()
{

}

void Admin::AddTest()
{
	Test tmp;
	tmp.CreateTest();
	//tests.push_back(tmp);
}

void Admin::ChangeTest()
{

}





long long Admin::Encrypt(std::string input)
{
	const int p = 61;// P  - простое число, примерно равное количеству символов во входном алфавите(лат.заглавные, лат.строчные, цифры).
	long long hash = 0, p_pow = 1;
	for (size_t i = 0; i < input.length(); ++i)
	{
		// единицу прибавляем, чтобы у строки вида 'aaaaa' хэш был ненулевой
		hash += (input[i] - 'a' + 1) * p_pow;
		p_pow *= p;
	}
	return hash;
}