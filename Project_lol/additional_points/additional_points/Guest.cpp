#include "Guest.h"
#include "Test.h"
#include <fstream>
#include<iostream>

using namespace std;

 void Guest::RegisterNewUser() 
{	
	ofstream fout("cppstudio.txt");

	cout << "Create login: ";
	cin >> login;
	//check if it is unique
	login = Encrypt(login);
	cout << endl<<"Create password: ";
	cin >> password;
	password = Encrypt(password);
	//logpass[login] = password;

	cout << "Ok, now let`s get acquainted!" << endl << "Input your first, middle and last name please: ";
	cin >> FIO;
	cout << endl << "What is your address? Input it here: ";
	cin >> address;
	cout << endl << "And the last thing, I need your phone number:";
	cin >> phoneNumber;
	
	fout << login<< password<<FIO << address << phoneNumber;

}

 void Guest::LogIn(string inlogin, string inpassword)
 {
	 cout << endl;
 }

void Guest::ShowAvaliableTests(Test* tests)
{
	for (int i = 0; i < 10; ++i)
	{
		if (!tests[i].GetPassed())
		{
			cout << tests[i].GetName() << endl;
		}
	}
}

void Guest::ShowCompletedTests(Test* tests)
{
	for (int i = 0; i < 10; ++i)
	{
		if (tests[i].GetPassed())
		{
			cout << tests[i].GetScore() << endl;
		}
	}
}


long long Guest::Encrypt(std::string input)
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