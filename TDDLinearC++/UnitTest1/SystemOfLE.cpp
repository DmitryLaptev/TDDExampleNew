#include "pch.h"
#include <cassert>
#include "CppUnitTest.h"
#include "../TDDLinearC++/SystemOfLinearEquation.h"
#include "../TDDLinearC++/SystemOfLinearEquation.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace UnitTest1
{
	TEST_CLASS(LinTest)
	{
	public:
		TEST_METHOD(FailWithWrongIndexing1)
		{
			auto test1 = []() {
				SystemOfLinearEquation listofcoef(4);
				listofcoef.AddLE(LinearEquation("1,2,3,4"));
				LinearEquation a = listofcoef[-1];
			};
			Assert::ExpectException<out_of_range>(test1);
		}
		TEST_METHOD(FailWithWrongIndexing2)
		{
			auto test2 = []() {
				SystemOfLinearEquation listofcoef(4);
				listofcoef.AddLE(LinearEquation("1,2,3,4"));
				LinearEquation a = listofcoef[10];
			};
			Assert::ExpectException<out_of_range>(test2);
		}
		TEST_METHOD(InfinitySolutionsChecking)
		{
			auto test3 = []() {
				SystemOfLinearEquation listofcoef(4);
				listofcoef.AddLE(LinearEquation("1, 2, 3, 4"));
				listofcoef.AddLE(LinearEquation("3, 5, 7, 9"));
				listofcoef.AddLE(LinearEquation("5, 8, 4, 2"));
				listofcoef.AddLE(LinearEquation("2, 14, 8, 11"));
				listofcoef.stepConvert();
				vector<double> result = listofcoef.gaussMethod();
			};
			Assert::ExpectException<invalid_argument>(test3);
		}
		TEST_METHOD(IndexingChecking)
		{
			auto test4 = []() {
				SystemOfLinearEquation listofcoef(4);
				listofcoef.AddLE(LinearEquation("1, 2, 3, 4"));
				listofcoef.AddLE(LinearEquation("15, 35, 14, 9"));
				listofcoef.AddLE(LinearEquation("12, 45, 89, 0"));
				listofcoef.AddLE(LinearEquation("1, 2, 3, 6"));
				listofcoef.stepConvert();
				vector<double> result = listofcoef.gaussMethod();
			};
			Assert::ExpectException<invalid_argument>(test4);
		}
	};
}