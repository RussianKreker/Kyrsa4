#include "pch.h"
#include "CppUnitTest.h"
#include "G:\Программирование\2 курс\1 сем\Kyrsa4.2\Kyrsa4.2\Postfix.cpp"
#include "G:\Программирование\2 курс\1 сем\Kyrsa4.2\Kyrsa4.2\Stack.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			PostfixClass P1;
			P1.infix = "ch(0)";
			P1.ConvertToPostfix();
			Assert::IsTrue(P1.postfix == " 0 ch");
		}
		TEST_METHOD(TestMethod2)
		{
			PostfixClass P1;
			P1.infix = "2+2*3";
			P1.ConvertToPostfix();
			Assert::IsTrue(P1.postfix == "2 2 3 * +");
		}
		TEST_METHOD(TestMethod3)
		{
			PostfixClass P1;
			P1.infix = "(3+3*2-2^3)/0.1";
			P1.ConvertToPostfix();
			double result = P1.Calculate();
			Assert::IsTrue(result == 10);
		}
		TEST_METHOD(TestMethod4)
		{
			PostfixClass P1;
			P1.infix = "log(1000)";
			P1.ConvertToPostfix();
			double result = P1.Calculate();
			Assert::IsTrue(result == 3);
		}
		TEST_METHOD(TestMethod5)
		{
			PostfixClass P1;
			P1.infix = "cos(pi)";
			P1.ConvertToPostfix();
			double result = P1.Calculate();
			Assert::IsTrue(result == -1);
		}
		TEST_METHOD(TestMethod6)
		{
			PostfixClass P1;
			P1.infix = "sqrt(25)";
			P1.ConvertToPostfix();
			double result = P1.Calculate();
			Assert::IsTrue(result == 5);
		}
		TEST_METHOD(TestMethod7)
		{
			PostfixClass P1;
			P1.infix = "2+3";
			P1.ConvertToPostfix();
			double result = P1.Calculate();
			Assert::IsTrue(result == 5);
		}
		TEST_METHOD(TestMethod8)
		{
			PostfixClass P1;
			P1.infix = "6-4";
			P1.ConvertToPostfix();
			double result = P1.Calculate();
			Assert::IsTrue(result == 2);
		}
		TEST_METHOD(TestMethod9)
		{
			PostfixClass P1;
			P1.infix = "ln(e^3)";
			P1.ConvertToPostfix();
			double result = P1.Calculate();
			Assert::IsTrue(2.9999 < result && result < 3);
		}
		TEST_METHOD(TestMethod10)
		{
			PostfixClass P1;
			P1.infix = "(((6)*4)+5^4)/0.25";
			P1.ConvertToPostfix();
			double result = P1.Calculate();
			Assert::IsTrue(result == 2596);
		}
	};
}
