#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	list l1(2);
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

	system("pause");
	return 0;
}