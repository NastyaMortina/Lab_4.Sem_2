#pragma once
#include "Vector.h"
#include "Matrix.h"

template <class T>
Vector<T> operator *(Matrix<T>& m, Vector<T>& v)
{
	if (m.GetW() == v.GetW()) {
		T* vector = new T[m.GetL()];
		Vector<T> result(m.GetL(), vector);

		for (int i = 0; i < result.GetW(); i++) 
		{
			result.SetI(i, 0);
			for (int j = 0; j < v.GetW(); j++) 
			{
				result.SetI(i, result[i] + (m[i][j] * v[j]));
			}
		}
		delete[] vector;
		return result;
	}
	else
		throw - 1;
};

template <class T>
Matrix<T> operator *(Vector<T>& v, Matrix<T>& m)
{
	if ((m.GetL() == v.GetW())) 
	{
		T** matrix = new T * [m.GetL()];

		for (int i = 0; i < v.GetW(); i++)
			matrix[i - 1] = new T[v.GetW() - 1];

		Matrix<T> result(m.GetL(), v.GetW(), matrix);

		for (int i = 0; i < result.GetW(); i++)
			for (int j = 0; j < result.GetL(); j++) 
			{
				result.SetI(i, j, m[0][j] * v[i]);
			}

		for (int i = 0; i < v.GetW(); i++)
			delete[] m[i];

		delete[] matrix;
		return result;
	}
};

template<class T>
void Vector<T>::Bubble_sort()
{
	T temp = 0;

	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - i - 1; j++)
		{
			if (vector[j] > vector[j + 1])
			{
				temp = vector[j + 1];
				vector[j + 1] = vector[j];
				vector[j] = temp;
			}
		}
}

template<class T>
void Vector<T>::Insertion_sort()
{
	T temp;

	for (int i = 1; i < N; i++)
	{
		int j = i;
		while ((j > 0) && (vector[j - 1] < vector[j]))
		{
			temp = vector[j - 1];
			vector[j - 1] = vector[j];
			vector[j] = temp;
			j--;
		}
	}

}

template<class T>
void Vector<T>::Quick_sort(int first, int last)
{
	T mid, count;
	int f = first, l = last;

	mid = vector[(f + l) / 2];
	do
	{
		while (vector[f] < mid) f++;
		while (vector[l] > mid) l--;
		if (f <= l)
		{
			count = vector[f];
			vector[f] = vector[l];
			vector[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) Quick_sort(first, l);
	if (f < last) Quick_sort(f, last);
}