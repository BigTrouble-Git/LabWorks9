#include "pch.h"
#include "CppUnitTest.h"
#include "../Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Student* p = new Student[2];
			p[0].fizyka = 3;
			p[0].matematyka = 4;
			p[0].informatyka = 4;

			p[1].fizyka = 5;
			p[1].matematyka = 5;
			p[1].informatyka = 5;

			double amount = Amount(p, 2);
			Assert::AreEqual(amount, 50.);
			double maxim = Average_of_Student(p, 2, 0);
			Assert::AreEqual(maxim, 5.);




		}
	};
}
