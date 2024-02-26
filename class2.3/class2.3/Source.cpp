#include <iostream>
#include "milTime.h"

using namespace std;


int main()
{
	milTime t;
	t.print();
	cout << endl;
	t.set( 9, 32, 7);
	t.print();
	cout << endl;

	t.reset();
	t.print();
	cout << endl;
	
	system("pause");
	return 0;
}