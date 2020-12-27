#pragma once
#include <string>
#include "Stack.h"

using namespace std;

class PostfixClass
{
public:
	PostfixClass();
	~PostfixClass();
	
	void inputstring();
	void ConvertToPostfix();
	double Calculate();
	int GetPriority(string s);
	string outstring();
	string infix;
	string postfix;
private:
	Stack stack;
};
