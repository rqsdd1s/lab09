#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>
#include "../lab9.2/lab9.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest92
{
	TEST_CLASS(UnitTest92)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// x = 2, y = 1
#if FIRST_BRANCH
			// z > 10: max(2^3, (2+1)^2) = max(8, 9) = 9
			Assert::AreEqual(9.0, Calc(2, 1));
#else
			// z <= 10: min(|2-z|, |2+z|)
			Assert::AreEqual(fmin(fabs(2.0 - Z), fabs(2.0 + Z)), Calc(2, 1));
#endif
		}
	};
}
