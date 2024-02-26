#include <iostream>
#include <iomanip>

using namespace std;
int** allocate2D(int m, int n); //allocates memory for the array
void fillArray2D(int* A[], int m, int n); //fills array with random integers
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


//question 2
//balanced array
bool isBalanced(int** A[], int m, int n)
{
	int plusCount = 0;//keeps count of total positive numbers
	int negCount = 0;//keeps count of total negative numbers
	for (int row = 0; row < m; row++)
	{
		for (int col = 0; col < n; col++)
		{
			if (A[row][col] < 0)
			{
				negCount++;
			}
			else if (A[row][col] > 0)
			{
				plusCount++;
			}
		}
	}
	if (negCount == plusCount)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

//question 3
//adding columns
int* columnSum(int** A, int m, int n)
{
	int* cs;//array containing the sum of each column
	cs = new int[n];
	for (int col = 0; col < n; col++)
	{
		//calculate the sum of each col
		int sum = 0;
		for (int row = 0; row < m; row++)
		{
			sum += A[row][col];
		}
		cs[col] = sum;
	}


	return cs;
}

//question 4
//max of a row
int* rowMax(int** A, int m, int n)
{
	int* max;//array containing the max of the row
	max = new int[m];
	

	for (int row = 0; row < m; row++)
	{
		int maxP = 0;//keeps track of the max for a specific row
		for (int col = 0; col < n; col++)
		{
			if (A[row][col] > maxP)
			{
				maxP = A[row][col];
				max[row] = A[row][col];
			}
		}
	}
	return max;
}

int main()
{
	int** A;
	int m = 4;
	int n = 10;
	A = allocate2D(m, n);

	for (int i = 0; i < m; i++)
	{
		A[i] = new int[n];
	}

	fillArray2D(A, m, n);//fill the array with a random set of integers between -50 and 50
	printArray2d(A, m, n);

	cout << "Row Max:\n";
	int* mr = rowMax(A, m, n);
	for (int i = 0; i < m; i++)
	{
		cout << mr[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
	
}

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

void fillArray2D(int* A[], int m, int n)//A is an 'm' by 'n' array
{
	for (int row = 0; row < m; row++)
	{
		for (int col = 0; col < n; col++)
		{
			A[row][col] = rand() % 101 + (-50);
		}
	}
}