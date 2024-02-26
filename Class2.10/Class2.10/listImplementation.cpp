#include <iostream>
#include "list.h"
using namespace std;
list::list(int c)
{
	capacity = c;
	msize = 0;
	data = new double[c];
}

list::list(const list& oL)
{
	capacity = oL.capacity;
	msize = oL.msize;
	data = new double[capacity];
	for (int i = 0; i < msize; i++)
	{
		data[i] = oL.data[i];
	}
}


void list::print() const
{
	cout << "{";
	for (int i = 0; i < msize; i++)
		cout << data[i] << ", ";
	cout << "}";
}
bool list::insert(double x)
{
	if (msize >= capacity)
		return false;
	data[msize] = x;
	msize++;
	return true;
}
//
//bool list::remove_at(int k)
//{
//    if (k < 0 || k >= size)
//          return false;
//    for (int i = k; i <= size - 2; i++)
//          data[i] = data[i + 1];  //shift the data over 1
//    size--;  //decrease the size by 1
//    return true;
//}
bool list::remove_at(int k)
{
	if (k < 0 || k >= msize)
		return false;
	data[k] = data[msize - 1];
	msize--;  //decrease the size by 1
	return true;
}
void list::changeCapacity(int c)
{
	if (c > 0)
	{
		double* newd = new double[c];
		if (c < msize)   //if the list is shrinking, update the size
			msize = c;
		for (int i = 0; i < msize; i++)
			newd[i] = data[i];
		delete[] data;
		data = newd; 
		capacity = c;
	}
}
void list::insert2(double x)
{
	if (msize >= capacity)
		changeCapacity(capacity + 10);
	insert(x);
}
