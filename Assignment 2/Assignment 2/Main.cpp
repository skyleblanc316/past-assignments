//all functions are withing this folder

#include <iostream>
using namespace std;

//problem 1
//mode
int findMode(int *, int);

//problem 2
//reverse array
int* reverseArray(int*, int);

//problem 3
//right shift
int* rightShift(int*, int);


int main()
{
	int A[100] = { 3,6,9,12,15,18,21 };
	int* X;
	X = rightShift(A, 7);//saves the new array created
	cout << "The new array is: ";
	for (int i = 0; i < 8; i++)
	{
		cout << X[i] << ", ";
	}
	cout << endl;
	system("pause");
	return 0;
}

int* rightShift(int* A, int size)
{
	int* B = new int [size + 1] { 0 };
	for (int i = 1; i < (size + 1); i++)//adds elements of A to B
	{
		B[i] = A[i - 1];
	}

	return B;
}

int* reverseArray(int* A, int size)
{
	for (int i = 0; i < (size / 2); i++)
	{
		swap(A[i], A[size - i]);
	}
	return A;
}


int findMode(int* A, int size)
{
	int counter = 0, max = 0, mode;
	for (int i = 0; i < size; i++)
	{
		counter = 0;
		for (int x = 0; x < size; x++)
		{
			if (A[i] == A[x])
			{
				counter++;
			}
		}
		if (counter > max)
		{
			max = counter;
			mode = A[i];
		}
	}
	return mode;
}