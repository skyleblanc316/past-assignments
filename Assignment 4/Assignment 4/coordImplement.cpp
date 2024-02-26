#include <iostream>
#include "coord.h"

using namespace std;

coord::coord(double a, double b)
{
	x_coord = a;
	y_coord = b;
}

void coord::set(double a, double b)//sets a and b
{
	x_coord = a;
	y_coord = b;
}

void coord::display() const
{
	cout << "(" << x_coord << ", " << y_coord << ")\n";
}

void coord::scale(double k)
{
	x_coord = x_coord * k;
	y_coord = y_coord * k;
}

double coord::distance() const
{
	double d;
	d = pow(x_coord, 2) + pow(y_coord, 2);
	d = sqrt(d);

	return d;
}

double coord::distance(coord p) const
{
	double d;
	d = pow(x_coord - p.x_coord, 2) + pow(y_coord - p.y_coord, 2);
	d = sqrt(d);

	return d;
}
