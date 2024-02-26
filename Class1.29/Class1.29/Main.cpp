#include <iostream>
#include <iomanip>

using namespace std;

//prints the contents of an array
void printArray2d(int* A[], int m, int n)
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

//fills an array with random elements with values between lower_bound and upper_bound
void fillArray2D(int* A[], int m, int n)//A is an 'm' by 'n' array
{
	for (int row = 0; row < m; row++)
	{
		for (int col = 0; col < n; col++)
		{
			A[row][col] = rand() % 101;
		}
	}
}

//allocate memory for an m by n array of it
//return the address to that space
int** allocate2D(int m, int n)
{
	int** p;
	p = new int* [m];
	for (int row = 0; row < m; row++)
	{
		p[row] = new int[m];
	}
	return p;
}

void deallocate2D(int** p, int m)
{
	for (int row = 0; row < m; row++)
	{
		delete[] p[row];
	}
}


//problem 1
//given an m by n array of int, return the sum of each row

int* sum(int** A, int m, int n)
{
	int* rs;//the dynamic array containing the sum of each row
	rs = new int[m];
	for (int row = 0; row < m; row++)
	{
		//calculate the sum of each row
		int sum = 0;
		for (int col = 0; col < n; col++)
		{
			sum += A[row][col];
		}
		rs[row] = sum;
	}


	return rs;
}


int main()
{
	
	int** A;
	int m = 4;
	int n = 10;
	A = allocate2D(m, n);

	for (int i = 0; i < m; i++)//adds column arrays
	{
		A[i] = new int[n];
	}

	fillArray2D(A, m, n);

	cout << "Array A: \n";
	printArray2d(A, m, n);

	cout << "The element at (2,3) is " << A[2][3] << endl;

	deallocate2D(A, m);
	system("pause");
	return 0;
}