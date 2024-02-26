#include <iostream>
#include <string>
#include "coord2d.h"

using namespace std;

int main()
{
	coord2d p(3.4, 7);
	cout << p << endl;

	coord2d x(2.2, 6);
	if (p > x)
	{
		cout << p << " is greater than " << x << endl;
	}
	else
		cout << x << " is greater than " << p << endl;

	if (p < x)
	{
		cout << p << " is less than " << x << endl;
	}
	else
		cout << x << " is less than " << p << endl;

	double k = 2;
	p = k * x;
	cout << "p = k * x = " << p << endl;

	p = k + x;
	cout << "p = k + x = " << p << endl;

	cout << "p * x = "<< p * x << endl;

	coord2d y;
	y = p + x;

	cout << "y = p + x = " << y << endl;

	cout << "x_coord = " << p[0] << endl;
	cout << "y_coord = " << p[1] << endl;
	system("pause");
	return 0;
}