#include <iostream>
#include "list.h"
#include <string>


using namespace std;

//Problem 1
//write a function that given a list and
// an array of doubles of size n
//will append the elements of the array to the list

void appendA(list& L, double A[], int n)
{
	for (int i = 0; i < n; i++)
		L.insert2(A[i]);
}

int main()
{
	list l1(100);
	cout << l1;
	cout << endl;

	l1.insert(10);
	cout << l1;
	cout << endl;
	l1.insert(-30);
	cout << l1;
	cout << endl;
	l1.insert2(200);
	cout << l1;
	cout << endl;

	l1.remove_at(0);
	l1.print();
	cout << endl;

	cout << "List size is : " << l1.size() << endl;

	double A[5] = { 23,-50,-70,123,54 };
	int n = 5;
	appendA(l1, A, n);
	cout << "L1 = " << l1 << endl;
	cout << "List size is : " << l1.size() << endl;
	list l2(l1);
	l2.insert(4);
	cout << "L2 = " << l2 << endl;
	cout << endl;
	if (l2 == l1)
		cout << "L2 and L1 are the same" << endl;
	else
		cout << "L2 and L1 are different" << endl;

	list l3;
	l3 = l1 + l2;
	cout << "L3=L1+L2 : " << l3 << endl;

	int k = 2;
	l3[k] = 2020;
	cout << "Entry with index " << k << " is given by " << l3[k] << endl;

	cout << "listcount = " << list::listcount << endl;
	
	system("pause");
	return 0;

}