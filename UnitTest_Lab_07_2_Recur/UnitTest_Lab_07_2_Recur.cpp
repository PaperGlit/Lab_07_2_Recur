#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07_2_Recur/Lab_07_2_Recur.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

int TestMinSum(int** a, const int rowCount, const int colCount, int i, int j, int S, int Min)
{
	if (i < colCount)
	{
		if (j < rowCount)
		{
			if (a[j][i] < Min)
				Min = a[j][i];
			TestMinSum(a, rowCount, colCount, i, j + 1, S, Min);
		}
		else
		{
			S += Min;
			TestMinSum(a, rowCount, colCount, i + 2, 0, S, 70);
		}
	}
	else
		return S;
}

namespace UnitTestLab072Iter
{
	TEST_CLASS(UnitTestLab072Iter)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			srand((unsigned)time(NULL));
			int Low = 7;
			int High = 62;
			int rowCount = 7;
			int colCount = 6;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];
			Create(a, rowCount, colCount, Low, High, 0, 0);
			int** b = a;
			Assert::AreEqual(TestMinSum(a, rowCount, colCount, 1, 0, 0, 70), Sum(b, rowCount, colCount, 1, 0));
		}
	};
}
