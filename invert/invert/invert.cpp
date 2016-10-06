#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <array>

static const int NUM_OF_ARGUMENTS = 2;
static const int MATRIX_SIZE = 3;
static const double ACCURACY = 0.0001;

using namespace std;
typedef array <double, MATRIX_SIZE> MatrixRow;
typedef array <MatrixRow, MATRIX_SIZE> Matrix;

bool FileIsEmpty(ifstream &file);
bool ReadMatrixFrom(ifstream &file, Matrix & destMatrix);
double GetDeterminantOf(const Matrix &matrix);
double GetMinor(const Matrix & matrix, const size_t row, const size_t colomn);
bool GetTheInverseMatrix(const Matrix & originalMatrix, const Matrix & inversedMatrix);
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
	if (!input.is_open)
	{
		cout << argv[1] << ": failed to open.\n Please, check the existence of the file or enter the name of another file.";
		return EXIT_FAILURE;
	}

	if (FileIsEmpty(input))
	{
		cout << "File is empty.\nPlease, enter the matrix to the file or enter the name of another file.";
		return EXIT_FAILURE;
	}
    
	Matrix originalMatrix, inverseMatrix;

	if (!ReadMatrixFrom(input, originalMatrix))
	{
		cout << "An error occurred while reading matrix from file.\nPlease, check number of values. In the file should be matrix " << MATRIX_SIZE << "x" << MATRIX_SIZE;
		return EXIT_FAILURE;
	}

	if (!GetTheInverseMatrix(originalMatrix, inverseMatrix))
	{
		cout << "The determinant of the matrix is zero.\nSo, the inverse matrix does not exist.";
		return EXIT_FAILURE;
	}

	PrintMatrixTo(cout, inverseMatrix);

	return EXIT_SUCCESS;
;
}
