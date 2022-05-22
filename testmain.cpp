#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include "Operations.h"
using namespace std;

void PrintFunctions()
{
	cout << "Select function:\n";
	cout << "1.v + v.\n" << "2.v - v.\n" << "3.v * v.\n";
	cout << "4.m + m.\n" << "5.m - m.\n" << "6.m * m.\n";
	cout << "7.v * m.\n" << "8.m * v.\n";
	cout << "choice: ";
}

int main()
{
	Matrix<int>B(3, 3);
	cout << B << endl;
	Vector<int>a1(3), a2(5);
	cout << a1 << endl;

	Vector<int> V1, V2, V3;
	Matrix<int> M1, M2, M3;

	int Scalar;
	int type;

	PrintFunctions();
	cin >> type;
	cout << endl;

	switch (type)
	{
	case (1):
		cout << "1 vector: " << endl;
		cin >> V1;
		cout << endl;
		cout << "2 vector: " << endl;
		cin >> V2;
		cout << endl;
		V3 = V1 + V2;
		cout << "vector: " << V3 << endl;
		break;
	case (2):
		cout << "1 vector: " << endl;
		cin >> V1;
		cout << endl;
		cout << "2 vector: " << endl;
		cin >> V2;
		cout << endl;
		V3 = V1 - V2;
		cout << "vector: " << V3 << endl;
		break;
	case (3):
		cout << "1 vector: " << endl;
		cin >> V1;
		cout << endl;
		cout << "2 vector: " << endl;
		cin >> V2;
		cout << endl;
		Scalar = V1 * V2;
		cout << "answer: " << Scalar << endl;
		break;
	case (4):
		cout << "1 matrix: " << endl;
		cin >> M1;
		cout << endl;
		cout << "2 matrix: " << endl;
		cin >> M2;
		cout << endl;
		M3 = M1 + M2;
		cout << "matrix: " << M3 << endl;
		break;
	case (5):
		cout << "1 matrix: " << endl;
		cin >> M1;
		cout << endl;
		cout << "2 matrix: " << endl;
		cin >> M2;
		cout << endl;
		M3 = M1 - M2;
		cout << "matrix: " << M3 << endl;
		break;
	case (6):
		cout << "1 matrix: " << endl;
		cin >> M1;
		cout << endl;
		cout << "2 matrix: " << endl;
		cin >> M2;
		cout << endl;
		M3 = M1 * M2;
		cout << "matrix: " << M3 << endl;
		break;
	case (7):
		cout << "vector: " << endl;
		cin >> V1;
		cout << endl;
		cout << "matrix: " << endl;
		cin >> M2;
		cout << endl;
		M3 = V1 * M2;
		cout << "answer: " << M3 << endl;
		break;
	case (8):
		cout << "matrix: " << endl;
		cin >> M1;
		cout << endl;
		cout << "vector: " << endl;
		cin >> V2;
		cout << endl;
		V3 = M1 * V2;
		cout << "answer: " << V3 << endl;
		break;
	}
	return 0;
}