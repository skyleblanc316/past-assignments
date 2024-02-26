#include "list.h"

#include <iostream>
#include <string>
using namespace std;

int main()
{
	list<double> l1(10);
	l1.insert(34); l1.insert(40); l1.insert(44); l1.insert(54);
	//cout << l1 << endl;
	l1.print(); cout << endl;

	list<double> l2;
	l2 = l1;
	l2.remove_at(1);
	l2[0] = 1000;
	l2 = l1 * (-1.0);
	cout << "l1 : " << l1 << endl;
	cout << "l2 : " << l2 << endl;

	if (l2 > l1)
		cout << "l2 is longer than l1" << endl;
	else
		cout << "l2 is not longer than l1" << endl;

	list<string> s1(30);
	s1.insert("AAA");	s1.insert("WWW"); 	s1.insert("Hi");
	s1.print(); cout << endl;
	system("pause");
	return 0;
}
