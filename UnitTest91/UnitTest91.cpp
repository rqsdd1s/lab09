#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>
#include "../lab9.1/var.cpp"
#include "../lab9.1/dod.cpp"
#include "../lab9.1/sum.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest91
{
	TEST_CLASS(UnitTest91)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// сума ряду для x = 1.5 має бути близькою до ln(1.5)
			nsVar::x = 1.5;
			nsVar::e = 1e-8;
			nsSum::sum();
			Assert::AreEqual(log(1.5), nsVar::s, 1e-6);
		}
	};
}
