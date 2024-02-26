#include <iostream>
#include "milTime.h"

using namespace std;

milTime::milTime()//default constructor
{
	hours = 12;
	minutes = 0;
	seconds = 0;
}

void milTime::print()
{
	if (hours < 10)
		cout << "0";
	cout << hours << ":";
	if (minutes < 10)
		cout << "0";
	cout << minutes << ":";
	if (seconds < 10)
		cout << "0";
	cout << seconds;
}

void milTime::set(int h, int m, int s) //set time to h:m:s
{
	hours = h;
	minutes = m;
	seconds = s;
}

void milTime::reset() //resets the time to 0:0:0
{
	hours = 0;
	minutes = 0;
	seconds = 0;
}

