#include <iostream>

#include <cmath>

using namespace std;

class Matrix {
private:
	int rows, columns;
	int mat[10][10];
public:
	Matrix(int a, int b, int c[][10]) {
		rows = a;
		columns = b;
		int i = 0, j = 0;
		for (i = 0; i < rows; i++) {
			for (j = 0; j < columns; j++) {
				mat[i][j] = c[i][j];
			}
		}
	}

	~Matrix() {}

	int GetById(int i, int j);
	void MultiplyOnNum(int mult);
	void Reset(int a, int b, int c[][10]);
	void Print(void);
	int GetRows(){ return rows; }
	int GetColumns() { return columns; }
	int Add(Matrix matrix2);
	int Sub(Matrix matrix2);
	int Multiply(Matrix matrix2);
};

void Matrix::Reset(int a, int b, int c[][10]) {
	rows = a;
	columns = b;
	int i = 0, j = 0;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++) {
			mat[i][j] = c[i][j];
		}
	}
}

int Matrix::Multiply(Matrix matrix2) {
	int arr[10][10];
	int a, b=0;
	int rows2 = matrix2.GetRows();
	int columns2 = matrix2.GetColumns();
	if (columns != rows2){
		return 0; 
	}
	else {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns2; j++) {
				for (a = 0; a < columns; a++) {
					b += mat[i][a] * matrix2.GetById(a, j);
				}
				arr[i][j] = b;
				b = 0;
			}
		}
		Reset(rows, columns2, arr);
	}
}

int Matrix::Add(Matrix matrix2) {
	if (matrix2.GetColumns() == columns and matrix2.GetRows() == rows) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				mat[i][j] += matrix2.GetById(i,j);
			}
		}
		return 1;
	} 
	return 0;
}

int Matrix::Sub(Matrix matrix2) {
	if (matrix2.GetColumns() == columns and matrix2.GetRows() == rows) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				mat[i][j] -= matrix2.GetById(i, j);
			}
		}
		return 1;
	}
	return 0;
}

void Matrix::Print(void) {
	printf("\n");
	for (int i = 0; i < rows; i++) {
		printf("  ");
		for (int j = 0; j < columns; j++) {
			printf("|%4d", mat[i][j]);
		}
		printf("|\n");

	}
}

int Matrix::GetById(int i, int j) {
	if (i < rows and j < columns) {
		return mat[i][j];
	} 
}

void Matrix::MultiplyOnNum(int mult){
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			mat[i][j] *= mult;
		}
	}
}


int main()

{
	int arr[][10] = { {1,2,3}, {4,5,6} };
	int arr2[][10] = { {-7,-8,-9}, {-1,-2,-3} };
	int arr3[][10] = { {1,2}, {2,3}, {4,5} };


	Matrix matrix1(2, 3, arr);
	Matrix matrix2(2, 3, arr2);
	Matrix matrix3(3, 2, arr3);
	Matrix matrix4(4, 2, arr4);
	Matrix matrix5(2, 4, arr5);
	matrix1.Print();

	int x = matrix1.GetById(1, 2);
	printf("\n  Num that was gotten by function GetById(1, 2): %d\n", x);
	matrix1.MultiplyOnNum(x);
	printf("  First Matrix multiplied on previous num:");
	matrix1.Print();
	printf("  Matrix2: ");
	matrix2.Print();
	matrix1.Add(matrix2);
	printf("  Matrix1+Matrix2: ");
	matrix1.Print();
	matrix1.Sub(matrix2);
	printf("  Matrix1-Matrix2: ");
	matrix1.Print();
	printf("  Matrix3: ");
	matrix3.Print();
	matrix1.Multiply(matrix3);
	printf("  Matrix1*Matrix3: ");
	matrix1.Print();

	return 0;
}