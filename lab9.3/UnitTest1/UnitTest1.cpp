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
			string surname = "w";
			double i = 2005;
			int mat = 5;
			Student* p = new Student[2];
			Data* s = new Data[2];
			p[0].prizv = "v";
			s[0].year = 2006;


			p[1].prizv = "w";
			s[1].year = 2005;
			Sort(p,s, 2);
			Assert::AreEqual(p[0].prizv, surname);
			Assert::AreEqual(s[0].year, i);



		}
	};
}
