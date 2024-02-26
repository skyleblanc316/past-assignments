#include <iostream>
#include "list.h"

using namespace std;

int list::listcount = 0;

list::list(int c)
{
	capacity = c;
	msize = 0;
	data = new double[c];
	listcount++;
}

list::list(const list& oL)
{
	capacity = oL.capacity;
	msize = oL.msize;
	data = new double[capacity];
	for (int i = 0; i < msize; i++)
		data[i] = oL.data[i];
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
//	if (k < 0 || k >= msize)
//		return false;
//	for (int i = k; i <= msize - 2; i++)
//		data[i] = data[i + 1];  //shift the data over 1
//	msize--;  //decrease the msize by 1
//	return true;
//}

bool list::remove_at(int k)
{
	if (k < 0 || k >= msize)
		return false;
	data[k] = data[msize - 1];
	msize--;  //decrease the msize by 1
	return true;
}

void list::changeCapacity(int c)
{
	if (c > 0)
	{
		double* newd = new double[c];
		if (c < msize)   //if the list is shrinking, update the msize
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


const list list::operator=(const list& oR)
//copies the list given as an argument
{
	if (this != &oR)
	{
		msize = oR.msize;
		capacity = oR.capacity;
		delete[] data; //deallocate the old data
		data = new double[capacity]; //allocate new memory for data
		for (int i = 0; i < msize; i++)
			data[i] = oR.data[i];  //copy elements over one by one
	}
	return *this;
}

ostream& operator<<(ostream& outstream, const list& oR)
{
	outstream << "{";
	for (int i = 0; i < oR.msize; i++)
		outstream << oR.data[i] << ", ";
	outstream << "}";
	return outstream;
}

bool operator==(const list& oL, const list& oR)
{
	//if sizes differ return false
	if (oL.msize != oR.msize)
		return false;
	//if any of the elements differ, return false
	for (int i = 0; i < oL.msize; i++)
		if (oL.data[i] != oR.data[i])
			return false;
	return true;
}


//overload + operator
//l3=l1+l2, means l1 and l2 do not change
//and l3= {l1, l2} (l2 appended at the end of l1)
list list::operator+(const list& oR)
{
	list tempL(*this);
	for (int i = 0; i < oR.msize; i++)
		tempL.insert2(oR.data[i]);
	return tempL;
}


double& list::operator[](int k)
{
	if (k < 0 || k >= msize)
	{
		cout << "index out of bounds" << endl;
		exit(0);
	}
	return data[k];
}

//list operator++(int u)
//{list temp (*this);
//	for (int i 0; i< msize; i++)
//	{
//		data[i] += 1;
//	}
//	return *this; temp;
//}

//friend list operator++(list& l)
//{
//	for (int i =0; i < l.msize; i++)
//	{
//		l.data[i] += i;
//	}
//	return l;
