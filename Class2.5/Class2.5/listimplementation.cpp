#include <iostream>
#include "List.h"

using namespace std;

list::list(int c)
{
	capacity = c;
	size = 0;
	data = new double[c];
}

void list::print() const
{
	cout << "{";
	for (int i = 0; i < size; i++)
	{
		cout << data[i] << ", ";
	}
	cout << "}";
}
//print the contents fo the list

bool list::insert(double x)
{
	if (size >= capacity)
		return false;
	data[size] = x;
	size++;
	return true;
}
//insert the argument to the back of the list

bool list::remove_at(int k)
{
	if (k < 0 || k >= size)
		return false;
	data[k] = data[size - 1];//replaces element k with the last element on the list
	//for (int i = k; i <= size - 2; i++)
	//	data[i] = data[i + 1];//shift the data over by one and decrease the size by 1
	size--;
	return true;
}

void list::changeCapacity(int c)
{
	if (c > 0)
	{
		double* newd = new double[c];
		if (size > c) //if the list is shrinking, update the size
			size = c;
		for (int i = 0; i < size; i++)
			newd[i] = data[i];
		delete[] data;
		data = newd;
		capacity = c;
	}
}

void list::insert2(double x)
{
	if (size >= capacity)
		changeCapacity(capacity + 10);
	insert(x);
}