#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
	if (i < rowCount)
	{
		if (j < colCount)
		{
			a[i][j] = Low + rand() % (High - Low + 1);
			Create(a, rowCount, colCount, Low, High, i, j + 1);
		}
		else
			Create(a, rowCount, colCount, Low, High, i + 1, 0);
	}
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	if (i < rowCount)
	{
		if (j < colCount)
		{
			cout << setw(4) << a[i][j];
			Print(a, rowCount, colCount, i, j + 1);
		}
		else
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
	}
}

int Min(int** a, const int rowCount, int min, int i, int j)
{
	if (j < rowCount)
	{
		if (a[j][i] < min)
			min = a[j][i];
		Min(a, rowCount, min, i, j + 1);
	}
	else
		return min;
}

int Sum(int** a, const int rowCount, const int colCount, int i, int S)
{
	if (i < colCount)
	{
		S += Min(a, rowCount, 70, i, 0);
		Sum(a, rowCount, colCount, i + 2, S);
	}
	else
		return S;
}

int main()
{
	SetConsoleOutputCP(1251);
	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 62;
	int rowCount = 7;
	int colCount = 6;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Create(a, rowCount, colCount, Low, High, 0, 0);
	Print(a, rowCount, colCount, 0, 0);
	cout << endl;
	cout << "—ума м≥н≥мальних елемент≥в по парних стовпц€х матриц≥: " << Sum(a, rowCount, colCount, 1, 0) << endl;
	return 0;
}