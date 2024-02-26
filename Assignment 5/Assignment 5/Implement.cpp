#include <iostream>
#include "coord2d.h"

using namespace std;

ostream& operator<<(ostream& outstream, const coord2d& oL)
{
	outstream << "(";
	outstream << oL.x_coord << ", " << oL.y_coord;
	outstream << ")";
	return outstream;

}

bool operator>(const coord2d& a, const coord2d& b)
{
	if ((a.x_coord > b.x_coord) && (a.y_coord > b.y_coord))
	{
		return true;
	}
	return false;
}

bool operator<(const coord2d& a, const coord2d& b)
{
	if ((a.x_coord < b.x_coord) && (a.y_coord < b.y_coord))
	{
		return true;
	}
	return false;
}

//e.g., p1=(3,5), p2=(4,-2), k=2
//then p1=k*p2 will result in p1=(8,-4) and p2=(4,-2)
coord2d operator*(double k, const coord2d& a)//friend version
{
	coord2d tempC(0, 0);
	tempC.x_coord = k * a.x_coord;
	tempC.y_coord = k * a.y_coord;

	return tempC;
}

//if p1=(a,b), p2=(c,d)
//then p1*p2  will return a*c+b*d
double coord2d::operator*(const coord2d& a) const//member version
{
	double product;
	product = (this->x_coord * a.x_coord) + (this->y_coord * a.y_coord);

	return product;
}

//e.g., p1=(3,5), p2=(4,-2), x=3
//then p1=x+p2 will result in p1=(7, 1) and p2=(4,-2)
coord2d operator+(double k, const coord2d& a)//friend version
{
	coord2d tempC(0, 0);
	tempC.x_coord = k + a.x_coord;
	tempC.y_coord = k + a.y_coord;

	return tempC;

}

//e.g., p1=(3,5), p2=(4,-2), p3=(10,20)
//then p1=p2+p3 will result in p1=(14,18), p2=(4,-2), p3=(10,20)
coord2d coord2d::operator+(const coord2d& a) const//member version
{
	coord2d tempC(0, 0);
	tempC.x_coord = this->x_coord + a.x_coord;
	tempC.y_coord = this->y_coord + a.y_coord;

	return tempC;
}

double& coord2d::operator[](int k)
{
	if (k == 0)
	{
		return this->x_coord;
	}
	else if (k == 1)
	{
		return this->y_coord;
	}
	else if (k < 0 || k > 1)
	{
		cout << "Error: value is out of bounds\n";
		exit(0);
	}
}