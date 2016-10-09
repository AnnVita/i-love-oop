#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <array>

static const int NUM_OF_ARGUMENTS = 2;
static const int MATRIX_SIZE = 3;
static const int MINOR_SIZE = 2;
static const double ACCURACY = 1000.0;

using namespace std;
typedef array <double, MATRIX_SIZE> MatrixRow;
typedef array <MatrixRow, MATRIX_SIZE> Matrix;

bool FileIsEmpty(ifstream &file);
bool ReadMatrixFrom(ifstream &file, Matrix & destMatrix);
double GetDeterminantOf(const Matrix &matrix);
double GetCofactor(const Matrix & matrix, const size_t row, const size_t colomn);
bool GetTheInverseMatrix(const Matrix & originalMatrix, Matrix & inversedMatrix);
void PrintMatrixTo(ostream &output, const Matrix & matrix);

int main(int argc, char * argv[])
{
	if (argc != NUM_OF_ARGUMENTS)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: invert.exe <matrix file>\n";
		return EXIT_FAILURE;
	}

	ifstream input(argv[1]);
	if (!input.is_open())
	{
		cout << argv[1] << ": failed to open.\n" 
			<< "Please, check the existence of the file or enter the name of another file.";
		return EXIT_FAILURE;
	}

	if (FileIsEmpty(input))
	{
		cout << "File is empty.\n"
			<< "Please, enter the matrix to the file or enter the name of another file.";
		return EXIT_FAILURE;
	}

	Matrix originalMatrix, inverseMatrix;

	if (!ReadMatrixFrom(input, originalMatrix))
	{
		cout << "An error occurred while reading matrix from file.\n"
			<< "Please, check number of values. In the file should be matrix " << MATRIX_SIZE << "x" << MATRIX_SIZE;
		return EXIT_FAILURE;
	}
	
	if (!GetTheInverseMatrix(originalMatrix, inverseMatrix))
	{
		cout << "The determinant of the matrix is zero.\n"
			<< "The inverse matrix does not exist.";
		return EXIT_FAILURE;
	}
	
	PrintMatrixTo(cout, inverseMatrix);

	return EXIT_SUCCESS;
}

bool FileIsEmpty(ifstream &file)
{
	return file.peek() == EOF;
}

bool ReadMatrixFrom(ifstream &file, Matrix & destMatrix)
{
	for (size_t j, i = 0; i < MATRIX_SIZE; i++)
	{
		for (j = 0; j < MATRIX_SIZE; j++)
		{
			if (file.eof())
			{
				return false;
			}
			file >> destMatrix[i][j];
		}
	}
	return true;
}

double GetCofactor(const Matrix &matrix, const size_t row, const size_t colomn)
{
	array <double, MINOR_SIZE * 2> minorValues;
	int minorValueNumber = 0;
	double cofactor;
	for (size_t j, i = 0; i < MATRIX_SIZE; i++)
	{
		for (j = 0; (j < MATRIX_SIZE) && (i != row); j++)
		{
			if (j == colomn)
			{
				continue;
			}
			else
			{
				minorValues[minorValueNumber++] = matrix[i][j];
			}
		}
	}
	cofactor = (minorValues[0] * minorValues[3]) - (minorValues[1] * minorValues[2]);
	return cofactor;
}

double GetDeterminantOf(const Matrix &matrix)
{
	const size_t ROW_FOR_DETERMINANT_COUNT = 0;
	double determinant = 0;
	int signSwitch;
	size_t colomn;
	for (colomn = 0, signSwitch = 1; colomn < MATRIX_SIZE; colomn++, signSwitch *= -1)
	{
		determinant += matrix[ROW_FOR_DETERMINANT_COUNT][colomn] * GetCofactor(matrix, ROW_FOR_DETERMINANT_COUNT, colomn) * signSwitch;
	}
	return determinant;
}

bool GetTheInverseMatrix(const Matrix & originalMatrix, Matrix & inversedMatrix)
{
	int signSwitch = 1;
	double matrixDeterminant = GetDeterminantOf(originalMatrix);
	matrixDeterminant = round(matrixDeterminant * ACCURACY) / ACCURACY;
	if (matrixDeterminant == 0)
	{
		return false;
	}

	for (size_t j, i = 0; i < MATRIX_SIZE; i++)
	{
		for (j = 0; j < MATRIX_SIZE; j++, signSwitch *= -1)
		{
			inversedMatrix[i][j] = signSwitch * GetCofactor(originalMatrix, i, j) / matrixDeterminant;
		}
	}
	return true;
}

void PrintMatrixTo(ostream &output, const Matrix & matrix)
{
	for (size_t j = 0; j < MATRIX_SIZE; j++)
	{
		for (size_t i = 0; i < MATRIX_SIZE; i++)
		{
			output << matrix[i][j] << '\t';
		}
		output << '\n';
	}
}