#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7.3.it/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test)
		{
            int k = 3, n = 3;
            int** a = new int* [k];
            for (int i = 0; i < k; i++)
                a[i] = new int[n];

            a[0][0] = 1; a[0][1] = -2; a[0][2] = 3;
            a[1][0] = 4; a[1][1] = 5; a[1][2] = -6;
            a[2][0] = 7; a[2][1] = 8; a[2][2] = 9;

            int sum = SUM(a, k, n);

            Assert::AreEqual(sum, 12);

            for (int i = 0; i < k; i++)
                delete[] a[i];
            delete[] a;
		}
	};
}
