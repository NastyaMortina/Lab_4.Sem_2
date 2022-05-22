#pragma once
#include <iostream>
using namespace std;

template<class T>
class Matrix
{
protected:
	T** matrix;
	int w;
	int l;

public:
	Matrix();
	Matrix(int s1, int s2, T** arr);
	Matrix(int _w, int _l);
	Matrix(const Matrix& M);
	~Matrix();

	int GetW();
	int GetL();
	void SetM(int i, int j, T val);
	void SetI(int i1, int i2, T t);
	T GetM(int i, int j);

	T*& operator[](const int _n);
	Matrix<T> operator+(const Matrix<T>& M);
	Matrix<T> operator-(const Matrix<T>& M);
	Matrix<T> operator=(const Matrix<T>& M);
	bool operator==(const Matrix<T>& M);
	Matrix<T> operator*(const Matrix<T>& M);

	template<class T>
	friend ostream& operator<<(ostream& os, const Matrix<T>& mat);
	template<class T>
	friend istream& operator>>(istream& in, Matrix<T>& mat);
};

template<class T>
Matrix<T>::Matrix(int s1, int s2, T** arr)
{
	w = s1;
	l = s2;
	matrix = new T * [w];
	for (int i = 0; i < w; i++)
		matrix[i] = new T[l];
	for (int i = 0; i < w; i++)
		for (int j = 0; j < l; j++)
			matrix[i][j] = arr[i][j];
}

template<class T>
int Matrix<T>::GetW()
{
	return w;
}

template<class T>
int Matrix<T>::GetL()
{
	return l;
}

template<class T>
void Matrix<T>::SetI(int i1, int i2, T t)
{
	for (int i = 0; i < w; i++)
		for (int j = 0; j < l; j++)
			if (i == i1 && j == i2)
				matrix[i][j] = t;
}

template<class T>
Matrix<T>::Matrix()
{
	w = 0;
	l = 0;
}

template<class T>
Matrix<T>::Matrix(int _w, int _l)
{
	w = _w;
	l = _l;
	matrix = new T * [w];

	for (int i = 0; i < w; i++)
		matrix[i] = new T[l];

	for (int i = 0; i < w; i++)
		for (int j = 0; j < l; j++)
			matrix[i][j] = 0;
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& M)
{
	w = M.w;
	l = M.l;
	matrix = (T**) new T * [w];
	for (int i = 0; i < l; i++)
		matrix[i] = (T*) new T[l];
	for (int i = 0; i < l; i++)
		for (int j = 0; j < l; j++)
			matrix[i][j] = M.matrix[i][j];
}

template <class T>
Matrix<T>::~Matrix()
{
	if (l > 0)
	{
		for (int i = 0; i < w; i++)
			delete[] matrix[i];
	}
	if (w > 0)
		delete[] matrix;
}

template<class T>
T Matrix<T>::GetM(int i, int j)
{
	if ((w >= i) && (l >= j) && (i >= 0) && (j >= 0)) {
		return matrix[i][j];
	}
	else
	{
		return 0;
	}
}

template<class T>
void Matrix<T>::SetM(int i, int j, T val)
{
	if ((w >= i) && (l >= j) && (i >= 0) && (j >= 0))
		matrix[i][j] = val;
}

template<class T>
Matrix<T> Matrix<T>::operator=(const Matrix<T>& M)
{
	if (*this == M)
		return *this;
	for (int i = 0; i < w; i++)
		delete[] matrix[i];
	delete[] matrix;
	this->w = M.w;
	this->l = M.l;
	matrix = new T * [w];
	for (int i = 0; i < w; i++)
		matrix[i] = new T[l];
	for (int i = 0; i < w; i++)
		for (int j = 0; j < l; j++)
			matrix[i][j] = M.matrix[i][j];
	return *this;
}

template <class T>
bool Matrix<T>::operator==(const Matrix<T>& M)
{
	if ((*this).w == M.w && (*this).l == M.l)
	{
		for (int i = 0; i < (*this).w; i++)
			for (int j = 0; j < (*this).l; j++)
				if ((*this).matrix[i][j] != M.matrix[i][j])
					return false;
		return true;
	}
	else
		return false;
}

template <class T>
T*& Matrix<T>::operator[](const int _n)
{
	return matrix[_n];
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& M)
{
	if (w == M.w && l == M.l)
	{
		Matrix<T> Ex(w, l, M.matrix);

		for (int i = 0; i < w; i++)
			for (int j = 0; j < l; j++)
				Ex.matrix[i][j] = M.matrix[i][j] + matrix[i][j];
		return Ex;
	}
	else
		throw - 1;
}

template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& M)
{
	if (w == M.w && l == M.l) {
		Matrix<T> Ex(w, l, M.matrix);

		for (int i = 0; i < w; i++)
			for (int j = 0; j < l; j++)
				Ex.matrix[i][j] = M.matrix[i][j] - matrix[i][j];
		return Ex;
	}
	else
		throw - 1;
}

template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& M)
{
	if (this->l == M.w) {
		Matrix<T> Ex;

		Ex.w = this->w;
		Ex.l = M.l;
		Ex.matrix = new T * [Ex.w];
		for (int i = 0; i < Ex.w; i++)
			Ex.matrix[i] = new T[Ex.l];
		for (int i = 0; i < Ex.w; i++)
			for (int j = 0; j < Ex.l; j++)
			{
				Ex.matrix[i][j] = 0;
				for (int k = 0; k < this->l; k++)
				{
					Ex.matrix[i][j] = Ex.matrix[i][j] + (matrix[i][k] * M.matrix[k][j]);
				}
			}
		return Ex;
	}
	else
		throw - 1;
}

template<class T>
ostream& operator<<(ostream& os, const Matrix<T>& mat)
{
	for (int i = 0; i < mat.w; i++)
	{
		if (i > 0) os << endl;
		os << "| ";
		for (int j = 0; j < mat.l; j++)
			os << mat.matrix[i][j] << " ";
		os << "|";
	}
	cout << endl;
	return os;
}

template<class T>
istream& operator>>(istream& in, Matrix<T>& mat)
{
	for (int i = 0; i < mat.w; i++)
		delete[] mat.matrix[i];
	delete[] mat.matrix;

	cout << "Enter size:" << endl;
	cout << "weight = ";
	in >> mat.w;
	cout << endl;
	cout << "long = ";
	in >> mat.l;
	cout << endl;

	T** temp;
	temp = new T * [mat.w];
	for (int i = 0; i < mat.w; i++)
		temp[i] = new T[mat.l];

	for (int i = 0; i < mat.w; i++)
	{
		cout << "Enter " << i + 1 << " line" << endl;
		for (int j = 0; j < mat.l; j++)
			in >> temp[i][j];
	}

	mat.matrix = new T * [mat.w];
	for (int i = 0; i < mat.w; i++)
		mat.matrix[i] = new T[mat.l];
	for (int i = 0; i < mat.w; i++)
		for (int j = 0; j < mat.l; j++)
			mat.SetM(i, j, temp[i][j]);
	for (int i = 0; i < mat.w; i++)
		delete[] temp[i];

	delete[] temp;
	return in;
}