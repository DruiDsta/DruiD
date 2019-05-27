#pragma once
#include <string>
#include <map>

class Test;

class Guest {
private:
	std::string login; //must be unique and encrypted
	std::string password;//must be encrypted

//	map <string, string, int> logpass; //pair login-password

	std::string FIO;
	std::string address; 
	long phoneNumber;

public:
	void RegisterNewUser();

	void LogIn(std::string, std::string);

	void ShowAvaliableTests(Test*);
	void ShowCompletedTests(Test*);


	long long Encrypt(std::string);


};