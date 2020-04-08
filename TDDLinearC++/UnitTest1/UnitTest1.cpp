#include "pch.h"
#include <cassert>
#include "CppUnitTest.h"
#include "../Indexer/Indexer.h"
#include "../Indexer/Indexer.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	private:
		double* array1 = new double[4]{ 1,2,3,4 };
	public:
		TEST_METHOD(HaveCorrectLength)
		{
			Indexer indexer = Indexer(array1, 1, 2, 4);
			Assert::AreEqual(2, indexer.getLength());
		}
		TEST_METHOD(GetCorrectly)
		{
			Indexer indexer = Indexer(array1, 1, 2, 4);
			Assert::AreEqual(2.0, indexer[0]);
			Assert::AreEqual(3.0, indexer[1]);
		}
		TEST_METHOD(SetCorrectly)
		{
			Indexer indexer = Indexer(array1, 1, 2, 4);
			Assert::AreEqual(2.0, indexer[0]);
			Assert::AreEqual(3.0, indexer[1]);
		}
		TEST_METHOD(IndexerDoesNotCopyArray)
		{
			Indexer indexer1 = Indexer(array1, 1, 2, 4);
			Indexer indexer2 = Indexer(array1, 0, 2, 4);
			indexer1[0] = 100500;
			Assert::AreEqual(100500.0, indexer2[1]);
		}
		TEST_METHOD(FailWithWrongArguments1)
		{
			auto test1 = []() {
				double* array1 = new double[4]{ 1,2,3,4 };
				Indexer indexer(array1, -1, 3, 4);
			};
			Assert::ExpectException<invalid_argument>(test1);
		}
		TEST_METHOD(FailWithWrongArguments2)
		{
			auto test2 = []() {
				double* array1 = new double[4]{ 1,2,3,4 };
				Indexer indexer(array1, 1, -1, 4);
			};
			Assert::ExpectException<invalid_argument>(test2);
		}
		TEST_METHOD(FailWithWrongArguments3)
		{
			auto test3 = []() {
				double* array1 = new double[4]{ 1,2,3,4 };
				Indexer indexer(array1, 1, 10, 4);
			};
			Assert::ExpectException<invalid_argument>(test3);
		}
		TEST_METHOD(FailWithWrongIndexing1)
		{
			auto test4 = []() {
				double* array1 = new double[4]{ 1,2,3,4 };
				Indexer indexer(array1, 1, 2, 4);
				double value = indexer[-1];
			};
			Assert::ExpectException<out_of_range>(test4);
		}
		TEST_METHOD(FailWithWrongIndexing2)
		{
			auto test5 = []() {
				double* array1 = new double[4]{ 1,2,3,4 };
				Indexer indexer(array1, 1, 2, 4);
				double value = indexer[10];
			};
			Assert::ExpectException<out_of_range>(test5);
		}
	};
}
