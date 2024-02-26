#include <iostream>
#include "list.h"
#include <string>

using namespace std;

//problem 1
//write a function that given a list and
//an array of doubles of size n
//will append the elements of the array to the list

void appendA(list& L, double A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		L.insert2(A[i]);
	}
}


int main()
{
	list l1(100);
	l1.print();
	cout << endl;

	l1.insert(10);
	l1.print();
	cout << endl;
	l1.insert(-30);
	l1.print();
	cout << endl;
	
	l1.insert2(200);
	l1.print();
	cout << endl;
	
	l1.remove_at(0);
	l1.print();
	cout << endl;

	cout << "List size is:" << l1.size() << endl;

	double A[5] = { 23, -50, -70, 123, 54 };
	int n = 5;
	appendA(l1, A, n);
	
	l1.print();
	cout << endl;
	cout << "List size is:" << l1.size() << endl;

	list l2(l1);

	l2.print();
	cout << endl;

	system("pause");
	return 0;
}