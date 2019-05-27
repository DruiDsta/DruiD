#pragma once
#include<string>
#include <map>

class Test {
private:
	std::string name;
	bool isPassed;
	int score = 0;

	std::map<std::string, std::string> QandA; //pair question - right answer


public:
	void CreateTest();
	std::string GetName() const;
	bool GetPassed() const;
	int GetScore() const;

	

};