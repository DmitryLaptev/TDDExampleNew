#include "pch.h"
#include <cassert>
#include "CppUnitTest.h"
#include "../TDDLinearC++/LinearEquation.h"
#include "../TDDLinearC++/LinearEquation.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace UnitTest1
{
	TEST_CLASS(LinTest)
	{
	private:
		double* array1 = new double[4]{ 1,2,3,4 };
	public:
		TEST_METHOD(FailWithWrongIndexing1)
		{
			auto test1 = []() {
				string listofcoef = "1,3,5,7,9";
				LinearEquation a(listofcoef);
				double value = a[-1];
			};
			Assert::ExpectException<out_of_range>(test1);
		}
		TEST_METHOD(FailWithWrongIndexing2)
		{
			auto test2 = []() {
				string listofcoef = "1,3,5,7,9";
				LinearEquation a(listofcoef);
				double value = a[5];
			};
			Assert::ExpectException<out_of_range>(test2);
		}
		TEST_METHOD(FailWithNegativeArgument)
		{
			auto test3 = []() {
				string listofcoef = "1,3,5,7,9";
				LinearEquation a(listofcoef);
				LinearEquation value(-5);
			};
			Assert::ExpectException<invalid_argument>(test3);
		}
		TEST_METHOD(IndexingChecking)
		{
			string listofcoef = "1,3,5,7,9";
			LinearEquation a(listofcoef);
			Assert::AreEqual(9.0, a[5]);
		}
		TEST_METHOD(InitializationCheching)
		{
			LinearEquation a(4);
			a.input(0);
			string listofcoef = "0,0,0,0";
			LinearEquation b(listofcoef);
			Assert::AreEqual(b, a);
		}
		TEST_METHOD(OperatorChecking1)
		{
			string listofcoef1 = "1,2,3,5.6,12,9,0.8";
			LinearEquation a(listofcoef1);
			string listofcoef2 = "2,-4,6.9, 8.9,11,13.8, 15.5";
			LinearEquation b(listofcoef2);
			string result = "3,-2,9.9,14.5,23, 16.3";
			LinearEquation res(result);
			Assert::AreEqual(a + b, res);
		}
		TEST_METHOD(OperatorChecking2)
		{
			string listofcoef1 = "1,2,3,5.6,12,9,0.8";
			LinearEquation a(listofcoef1);
			string listofcoef2 = "2,-4,6.9, 8.9,11,13.8, 15.5";
			LinearEquation b(listofcoef2);
			string result = "-1,6,-3.9,-3.3,1,-4.8,-14.7";
			LinearEquation res(result);
			Assert::AreEqual(a - b, res);
		}
		TEST_METHOD(WrongEquationCheching)
		{
			string listofcoef1 = "0,0,0,0,0,0,0.8";
			LinearEquation a(listofcoef1);
			bool pp;
			if (a) pp = true;
			else pp = false;
			Assert::AreEqual(false, pp);
		}
		TEST_METHOD(CorrectlyEquationCheching)
		{
			string listofcoef1 = "1,2,3,5.6,12,9,0.8";
			LinearEquation a(listofcoef1);
			bool pp;
			if (a) pp = true;
			else pp = false;
			Assert::AreEqual(true, pp);
		}
	};
}