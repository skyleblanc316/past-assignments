#include <iostream>
#include <string>
using namespace std;

//prints the contents of an array
template <class eType>
void printArray(eType* A, int size)
{
	cout << "{";
	for (int i = 0; i < size; i++)
		cout << A[i] << ", ";
	cout << "}";
}

template <class eType>
eType getMode(eType* A, int size)
{
	eType mode = A[0];
	int modefreq = 0;

	for (int i = 0; i < size; i++)
	{
		int freq = 0;
		for (int j = i; j < size; j++)
			if (A[i] == A[j])
				freq++;
		if (freq > modefreq)
		{
			modefreq = freq;
			mode = A[i];
		}
	}
	return mode;
}

template <class eType>
eType* reverseArray(eType* A, int size)
{
	eType* R = new eType[size];
	for (int i = 0; i < size; i++)
		R[i] = A[size - i - 1];
	return R;
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

//write a function that returns the largest element in an array
//inputs : the array and size
//outputs: an element of the array
template <class eType>
eType getMax(eType* A, int size)
{
	eType maxe = A[0];
	for (int i = 1; i < size; i++)
		if (A[i] > maxe)
			maxe = A[i];
	return maxe;
}

//write a function that searches for an element x in an array
//returns the index of where it is first found
//returns -1 if not found

template <class eType>
int find(eType x, eType* A, int size)
{
	for (int i = 0; i < size; i++)
		if (A[i] == x)
			return i;
	return -1;
}


//Problem 1
//Write a function that given two sorted arrays A1 and A2 of size n
//will return a sorted array combining (merging) the two arrays A1, A2
//Restriction:  you cannot use nested loops

template <class eType>
eType* merge(eType* A1, eType* A2, int n)
{
	eType* M = new eType[2 * n];
	int i1 = 0, i2 = 0, im = 0;

	//repeat until one of the arrays is finished
	while (i1 < n && i2 < n)
	{
		if (A1[i1] < A2[i2])
		{
			M[im] = A1[i1];
			im++;
			i1++;
		}
		else
		{
			M[im] = A2[i2];
			im++;
			i2++;
		}
	}

	//if A1 finishes first
	while (i2 < n)
	{
		M[im] = A2[i2];
		im++;
		i2++;
	}

	//if A2 finishes first
	while (i1 < n)
	{
		M[im] = A1[i1];
		im++;
		i1++;
	}

	return M;
}





int main()
{
	int n = 10;
	int* A = new int[n];

	for (int i = 0; i < n; i++)
		A[i] = rand() % 21;

	cout << "A :";  printArray(A, n);  cout << endl;
	cout << "mode of A is : " << getMode(A, n) << endl;
	int* R = reverseArray(A, n);
	cout << "reverse of A (R) : ";  printArray(R, n);  cout << endl;
	selectionSort(A, n);
	cout << "A sorted : ";  printArray(A, n);  cout << endl;

	int ns = 10;
	string* S = new string[n];
	string collection[10] = { "AAA", "BBB", "hello", "XYZ", "aaa", "www", "name", "step", "code", "stop" };

	for (int i = 0; i < ns; i++)
		S[i] = collection[rand() % 10];

	cout << "S :";  printArray(S, ns);  cout << endl;
	cout << "mode of S is : " << getMode(S, ns) << endl;
	string* Sr = reverseArray(S, n);
	cout << "reverse of S (Sr) : ";  printArray(Sr, ns);  cout << endl;
	selectionSort(S, ns);
	cout << "S sorted : ";  printArray(S, ns);  cout << endl;

	int* B1 = new int[n];
	int* B2 = new int[n];

	for (int i = 0; i < n; i++)
	{
		B1[i] = rand() % 21;
		B2[i] = rand() % 21;
	}
	selectionSort(B1, n);
	selectionSort(B2, n);
	int* M = merge(B1, B2, n);
	cout << "\n\n\nB1 :";  printArray(B1, n);  cout << endl;
	cout << "B2 :";  printArray(B2, n);  cout << endl;
	cout << "M :";  printArray(M, 2 * n);  cout << endl;


	system("pause");
	return 0;
}