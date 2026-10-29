#include "pch.h"
#include "CppUnitTest.h"
#include "../PR_6.3_it/PR_6.3.it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest063it
{
    TEST_CLASS(UnitTest063it)
    {
    public:
        TEST_METHOD(TestSumPositiveStandard)
        {
            int a[] = { -3, 5, 0, 7, -2, 10 };
            Assert::AreEqual(22, SumPositive(a, 6));
        }

        TEST_METHOD(TestSumPositiveTemplate)
        {
            double b[] = { -1.5, 2.5, 3.0, -0.5 };
            Assert::AreEqual(5.5, SumPositiveTemplate(b, 4), 1e-6);
        }

        TEST_METHOD(TestSumPositiveTemplateInt)
        {
            int a[] = { -3, 5, 0, 7, -2, 10 };
            Assert::AreEqual(22, SumPositive<int>(a, 6));
        }

        TEST_METHOD(TestCreateWithinBounds)
        {
            int a[10];
            Create(a, 10, -5, 5);
            for (int i = 0; i < 10; i++)
            {
                Assert::IsTrue(a[i] >= -5 && a[i] <= 5);
            }
        }
    };
}
