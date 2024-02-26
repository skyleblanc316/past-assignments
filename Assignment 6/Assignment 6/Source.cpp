#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

template <class eType>
void selectionSort(eType*, int);

template <class eType>
eType** allocate2D(eType m, eType n);

template <class eType>
void fillArray2D(eType* A[], int m, int n);//A is an 'm' by 'n' array

template <class eType>
void printArray2d(eType* A[], int m, int n);


//problem 2 template with binary search

template <class eType>
int binSearch(eType x, eType* A, int size)
{
	for (int i = 0; i < size; i++)
		if (A[i] == x)
			return i;
	return -1;
}

//problem 3 median array
//template <class eType>
//eType median(eType* A, int size)
//{
//	selectionSort(A, size);
//	int mE = (size / 2) + 1;//since it is assumed to be odd
//
//	eType median = A[mE];
//	return median;
//}

//problem 4 reshape array
template <class eType>
eType* reshape(eType** A, int m, int n)
{
	int x = m * n;
	eType* B = new int[x];
	int k = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			B[k] = A[i][j];
			k++;
		}
	return B;
}

int main()
{
	int m = 2;//row
	int n = 5;//collumn
	int** A;//integer array
	A = allocate2D(m, n);


	for (int i = 0; i < m; i++)
	{
		A[i] = new int[n];
	}

	fillArray2D(A, m, n);//fill the array with a random set of integers between -50 and 50
	
	printArray2d(A, m, n);//print the array

	int z = m * n;
	int* X = reshape(A, m, n);
	cout << "{ ";
	for (int i = 0; i < z; i++)
		cout << X[i] << ", ";
	cout << "}\n";


	system("pause");
	return 0;
}

template <class eType>
void selectionSort(eType* A, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int mini = i;
		for (int j = i + 1; j < size; j++)
			if (A[mini] > A[j])
				mini = j;
		if (mini > i)
			swap(A[mini], A[i]);
	}
}

template <class eType>
eType** allocate2D(eType m, eType n)
{
	eType** p;
	p = new eType* [m];
	for (int row = 0; row < m; row++)
	{
		p[row] = new eType[m];
	}
	return p;
}

template <class eType>
void fillArray2D(eType* A[], int m, int n)//A is an 'm' by 'n' array
{
	for (int row = 0; row < m; row++)
	{
		for (int col = 0; col < n; col++)
		{
			A[row][col] = rand() % 101 + (-50);
		}
	}
}

template <class eType>
void printArray2d(eType* A[], int m, int n)
{
	for (int row = 0; row < m; row++)
	{
		for (int col = 0; col < n; col++)
		{
			cout << setw(5) << A[row][col];
		}
		cout << endl;
	}
}