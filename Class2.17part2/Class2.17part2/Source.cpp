#include <iostream>
#include <string>

using namespace std;

struct pp {
	int p1;
	int p2;
	int p3;
	friend ostream& (ostream& os, const pp l)
	{
		os << "(" << l.p1<< ", " << l.p2 << ", " << l.p3 << ", " << ")"
	}
	friend bool operator>(const pp& l)
	{
		return l.p1>r.p1
	}
};
//T can stand for double, string or anything you like
template <class T>
T larger(double a, double b)
{
	if (T a > T b)
	{
		return a;
	}
	return b;
}

int main()
{
	double a = 7, b = 10;

	cout << "the larger of " << a << " and " << b << " is " << larger(a, b) << endl;

	string c = "AAA", d = "WWW";

	cout << "the larger of " << c << " and " << d << " is " << larger(c, d) << endl;

	x = { 1, 1, 1 }, y = { 2, 2, 2 };

	cout << "the larger of " << x << " and " << y << " is " << larger(x, y) << endl;
}