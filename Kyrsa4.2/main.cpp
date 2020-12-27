#include "Stack.h"
#include "Postfix.h"
#include <iostream>
int main() 
{
	PostfixClass P1;
	P1.inputstring();
	P1.ConvertToPostfix();
	std::cout << P1.outstring();
	std::cout << " = ";
	std::cout << P1.Calculate();
	return 0;
}