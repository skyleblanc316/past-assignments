#include <iostream>
#include "coord.h"

using namespace std;

int main()
{
	coord c1;
	c1.display();

	c1.set(10, -9);
	c1.display();

	c1.scale(10);
	c1.display();

	c1.set(3, -4);
	cout << c1.distance() << endl;
	coord p;
	p.set(-1, 1);
	c1.set(2, -5);
	cout << c1.distance(p) << endl;



	system("pause");
	return 0;
}