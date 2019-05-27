#include "Test.h"
#include <fstream>
#include <iostream>

using namespace std;

void Test::CreateTest()
{
	string q, a;
	ofstream fout("tests.txt");
	cout << "Welcome to creator mode! Now you are going to add 12 Questions and Answers for the new test." << endl << "But first name it: ";
	cin >> name;
	cout << endl << "Test " << name << " has been created!" << endl;
	for (int i = 1; i < 13; ++i) {
		cout <<" "<<i<<"Input a question and than answer for it." << endl;
		cin >> q >> a;
		QandA.insert(pair<string, string>(q, a));
	}
	cout << endl<<endl<<"Congratulations! Test is successfully created!" << endl;
}

std::string Test:: GetName() const
{
	return name;
}
bool Test:: GetPassed() const
{
	return isPassed;
}
int Test::GetScore() const
{
	return score; 
}

