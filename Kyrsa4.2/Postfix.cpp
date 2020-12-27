#include "Postfix.h"
#include <iostream>
#include <cmath>

const double PI = 3.14159;
const double E =  2.71828;


PostfixClass::PostfixClass()
{
}

PostfixClass::~PostfixClass()
{
}


void PostfixClass::inputstring() 
{
	std::getline(std::cin, infix);
}

int PostfixClass::GetPriority(string c)
{
	if (c == "cos" || c == "sin" || c == "tg" || c == "ctg" || c == "log" || c == "ln" || c == "sqrt" || c == "ch") return 4;
	//if (c == "s" || c == "c" || c == "t" || c == "l") return 4;
	if (c == "^") return 3;
	if (c == "*" || c == "/") return 2;
	if (c == "+" || c == "-") return 1;
	if (c == "(" || c == ")") return 0;
	return -1;
}

string PostfixClass::outstring()
{
	return postfix;
}

void PostfixClass::ConvertToPostfix()
{
	string symbol;
	for (int i = 0; i < infix.length(); i++)
	{
		if (infix[i] == '0' || infix[i] == '1' || infix[i] == '2' || infix[i] == '3' || infix[i] == '4' || infix[i] == '5' || infix[i] == '6' || infix[i] == '7' || infix[i] == '8'
			|| infix[i] == '9' || infix[i] == '.')
		{
			postfix = postfix + infix[i];
		}
		else if (infix[i]=='+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
		{
			symbol = infix[i];
			while (GetPriority(symbol) <= GetPriority(stack.getTop()))
			{
				postfix = postfix + " " + stack.pop_back();
			}
			stack.push_back(symbol);
			postfix = postfix + " ";
		}
		else if ((infix.length()) - i > 2 &&  infix[i] == 's' && infix[i + 1] == 'i' && infix[i + 2] == 'n')// sin
		{
			while (GetPriority("sin") <= GetPriority(stack.getTop()))
			{
				postfix = postfix + stack.pop_back();
			}
			stack.push_back("sin");
			postfix = postfix + " ";
			i += 2;
		}
		else if ((infix.length())-i>2 && infix[i] == 'c' && infix[i + 1] == 'o' && infix[i + 2] == 's')//cos
		{
			while (GetPriority("cos") <= GetPriority(stack.getTop()))
			{
				postfix = postfix + " " + stack.pop_back();
			}
			stack.push_back("cos");
			postfix = postfix + " ";
			i += 2;
		}
		else if ((infix.length()) - i > 1 &&  infix[i] == 't' &&  infix[i + 1] == 'g') // tg
		{
			while (GetPriority("tg") <= GetPriority(stack.getTop()))
			{
				postfix = postfix + " " + stack.pop_back();
			}
			stack.push_back("tg");
			postfix = postfix + " ";
			i ++;
		}
		else if ((infix.length()) - i > 2 && infix[i] == 'c' && infix[i + 1] == 't' && infix[i + 2] == 'g') // ctg
		{
			while (GetPriority("ctg") <= GetPriority(stack.getTop()))
			{
				postfix = postfix + " " + stack.pop_back();
			}
			stack.push_back("ctg");
			postfix = postfix + " ";
			i += 2;
		}
		else if ((infix.length()) - i > 3 && infix[i] == 's' && infix[i + 1] == 'q' && infix[i + 2] == 'r' && infix[i + 3] == 't') // sqrt
		{
			while (GetPriority("sqrt") <= GetPriority(stack.getTop()))
			{
				postfix = postfix + " " + stack.pop_back();
			}
			stack.push_back("sqrt");
			postfix = postfix + " ";
			i += 3;
		}
		else if ((infix.length()) - i > 2 && infix[i] == 'l' && infix[i + 1] == 'o' && infix[i + 2] == 'g') // log
		{
			while (GetPriority("log") <= GetPriority(stack.getTop()))
			{
				postfix = postfix + " " + stack.pop_back();
			}
			stack.push_back("log");
			postfix = postfix + " ";
			i += 2;
		}
		else if ((infix.length()) - i > 1 && infix[i] == 'l' && infix[i + 1] == 'n') // ln
		{
			while (GetPriority("ln") <= GetPriority(stack.getTop()))
			{
				postfix = postfix + " " + stack.pop_back();
			}
			stack.push_back("ln");
			postfix = postfix + " ";
			i += 1;
		}
		else if ((infix.length()) - i > 1 && infix[i] == 'c' && infix[i + 1] == 'h') // ch
		{
			while (GetPriority("ch") <= GetPriority(stack.getTop()))
			{
				postfix = postfix + " " + stack.pop_back();
			}
			stack.push_back("ch");
			postfix = postfix + " ";
			i += 1;
		}
		else if (infix[i]=='(')
		{
			stack.push_back("(");
		}
		else if (infix[i]==')')
		{
			symbol = stack.pop_back();
			while (symbol != "(")
			{
				postfix = postfix+ " " + symbol;
				symbol = stack.pop_back();
			}
		}
		else if ((infix.length()) - i > 1 && infix[i]=='p' && infix[i+1]=='i')//Pi
		{
			postfix = postfix + "pi";
			i++;
		}
		else if (infix[i] == 'e')//E
		{
		postfix = postfix + "e";
		}
	}
	while (!stack.isEmpty())
	{
		postfix = postfix+ " " + stack.pop_back();
	}
}

double PostfixClass::Calculate()
{
	string symbol;
	double op1;
	double op2;
	for (int i = 0; i < postfix.length(); i++)
	{
		if (postfix[i] == '0' || postfix[i] == '1' || postfix[i] == '2' || postfix[i] == '3' || postfix[i] == '4' || postfix[i] == '5' || postfix[i] == '6' || postfix[i] == '7' || postfix[i] == '8'
			|| postfix[i] == '9' || postfix[i] == '.')
		{
			string num;
			while (postfix[i] == '0' || postfix[i] == '1' || postfix[i] == '2' || postfix[i] == '3' || postfix[i] == '4' || postfix[i] == '5' || postfix[i] == '6' || postfix[i] == '7' || postfix[i] == '8'
				|| postfix[i] == '9' || postfix[i] == '.')
			{
				num += postfix[i];
				i++;
			}
			i--;
			stack.push_back(num);
		}
		else if (postfix[i]=='+')
		{
			op1 = atof(stack.pop_back().c_str());
			op2 = atof(stack.pop_back().c_str());
			stack.push_back(to_string(op1 + op2));
		}
		else if (postfix[i] == '-')
		{
			op1 = atof(stack.pop_back().c_str());
			op2 = atof(stack.pop_back().c_str());
			stack.push_back(to_string(op2 - op1));
		}
		else if (postfix[i] == '*')
		{
			op1 = atof(stack.pop_back().c_str());
			op2 = atof(stack.pop_back().c_str());
			stack.push_back(to_string(op1 * op2));
		}
		else if (postfix[i] == '/')
		{
			op1 = atof(stack.pop_back().c_str());
			op2 = atof(stack.pop_back().c_str());
			stack.push_back(to_string(op2 / op1));
		}
		else if (postfix[i] == '^')
		{
			op1 = atof(stack.pop_back().c_str());
			op2 = atof(stack.pop_back().c_str());
			stack.push_back(to_string(pow(op2,op1)));
		}
		else if ((postfix.length()) - i > 2 && postfix[i] == 's' && postfix[i+1] == 'i' && postfix[i+2] == 'n')
		{
			op1 = atof(stack.pop_back().c_str());
			//op2 = atof(stack.pop_back().c_str());
			stack.push_back(to_string(sin(op1)));
		}
		else if ((postfix.length()) - i > 2 && postfix[i] == 'c' && postfix[i+1] == 'o' && postfix[i+2] == 's')
		{
			op1 = atof(stack.pop_back().c_str());
			//op2 = atof(stack.pop_back().c_str());
			stack.push_back(to_string(cos(op1)));
		}
		else if ((postfix.length()) - i > 2 && postfix[i] == 'c' && postfix[i+1] == 't' && postfix[i+2] == 'g')
		{
			op1 = atof(stack.pop_back().c_str());
			//op2 = atof(stack.pop_back().c_str());
			stack.push_back(to_string(1 / tan(op1)));
		}
		else if ((postfix.length()) - i > 1 && postfix[i] == 't' && postfix[i+1] == 'g')
		{
			op1 = atof(stack.pop_back().c_str());
			//op2 = atof(stack.pop_back().c_str());
			stack.push_back(to_string(tan(op1)));
		}
		else if ((postfix.length()) - i > 1 && postfix[i] == 'l' && postfix[i+1] == 'n')
		{
			op1 = atof(stack.pop_back().c_str());
			//op2 = atof(stack.pop_back().c_str());
			stack.push_back(to_string(log(op1)));
		}
		else if ((postfix.length()) - i > 2 && postfix[i] == 'l' && postfix[i+1] == 'o' && postfix[i + 2] == 'g')
		{
			op1 = atof(stack.pop_back().c_str());
			//op2 = atof(stack.pop_back().c_str());
			stack.push_back(to_string(log10(op1)));
		}
		else if ((postfix.length()) - i > 3 && postfix[i] == 's' && postfix[i + 1] == 'q' && postfix[i + 2] == 'r' && postfix[i + 3] == 't')
		{
			op1 = atof(stack.pop_back().c_str());
			//op2 = atof(stack.pop_back().c_str());
			stack.push_back(to_string(sqrt(op1)));
		}
		else if ((postfix.length()) - i > 1 && postfix[i] == 'c' && postfix[i + 1] == 'h')//ch
		{
			op1 = atof(stack.pop_back().c_str());
			////op2 = atof(stack.pop_back().c_str());
			//stack.push_back(to_string(log10(op1)));
			stack.push_back(to_string ( (pow(E, op1)+pow(E, -op1))/2 ) );
		}
		else if ((postfix.length()) - i > 1 && postfix[i] == 'p' && postfix[i + 1] == 'i' )
		{
			//op1 = atof(stack.pop_back().c_str());
			////op2 = atof(stack.pop_back().c_str());
			//stack.push_back(to_string(log10(op1)));
			stack.push_back(to_string(PI));
		}
		else if (postfix[i] == 'e')
		{
			//op1 = atof(stack.pop_back().c_str());
			////op2 = atof(stack.pop_back().c_str());
			//stack.push_back(to_string(log10(op1)));
			stack.push_back(to_string(E));
		}
	}
	double result = atof(stack.pop_back().c_str());
	return result;
}





