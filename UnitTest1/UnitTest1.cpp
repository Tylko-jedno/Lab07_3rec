#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab07_3rec/Lab07_3rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MatrixTests
{
	TEST_CLASS(MatrixTests)
	{
	public:

		TEST_METHOD(TestCreate)
		{
			const int rowCount = 3;
			const int colCount = 3;
			const int Low = -5;
			const int High = 5;
			int** matrix = new int* [rowCount];
			for (int i = 0; i < rowCount; ++i)
				matrix[i] = new int[colCount];

			Create(matrix, rowCount, colCount, Low, High, 0, 0);

			bool inRange = true;
			for (int i = 0; i < rowCount; ++i)
			{
				for (int j = 0; j < colCount; ++j)
				{
					if (matrix[i][j] < Low || matrix[i][j] > High)
					{
						inRange = false;
						break;
					}
				}
				if (!inRange) break;
			}

			Assert::IsTrue(inRange);

			for (int i = 0; i < rowCount; ++i)
				delete[] matrix[i];
			delete[] matrix;
		}

		TEST_METHOD(TestPart1_Count)
		{
			const int rowCount = 3;
			const int colCount = 3;
			int** matrix = new int* [rowCount];
			for (int i = 0; i < rowCount; ++i)
				matrix[i] = new int[colCount];

			matrix[0][0] = 1; matrix[0][1] = 2; matrix[0][2] = 0;
			matrix[1][0] = 3; matrix[1][1] = 0; matrix[1][2] = 4;
			matrix[2][0] = 5; matrix[2][1] = 6; matrix[2][2] = 7;

			int count = 0;
			bool hasZero = Part1_Count(matrix, rowCount, colCount, count);

			Assert::IsTrue(hasZero);
			Assert::AreEqual(-1, count);

			for (int i = 0; i < rowCount; ++i)
				delete[] matrix[i];
			delete[] matrix;
		}

		TEST_METHOD(TestSortRowsByCharacteristic)
		{
			const int rowCount = 3;
			const int colCount = 3;
			int** matrix = new int* [rowCount];
			for (int i = 0; i < rowCount; ++i)
				matrix[i] = new int[colCount];


			matrix[0][0] = 1; matrix[0][1] = 4; matrix[0][2] = 6;  
			matrix[1][0] = 2; matrix[1][1] = 2; matrix[1][2] = 2;  
			matrix[2][0] = 0; matrix[2][1] = 2; matrix[2][2] = 8;  

			Part2_sortRowsByCharacteristic(matrix, rowCount, colCount);


			Assert::AreEqual(2, matrix[0][0]);
			Assert::AreEqual(1, matrix[1][0]);
			Assert::AreEqual(0, matrix[2][0]);

			for (int i = 0; i < rowCount; ++i)
				delete[] matrix[i];
			delete[] matrix;
		}
	};
}

