#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

//implement a list 

template <class T>
class list
{
	template <class T1>
	friend ostream& operator<<(ostream& outstream, const list<T1>& oR);

	template <class T1>
	friend bool operator>(const list<T1>&, const list<T1>&);

public:
	list(int = 30);
	//default constructor: initialize data,size and capacity
	//the argument passed is the capacity of the list
	list(const list<T>&);
	//overload the copy constructor
	void print() const;
	//print the contents of the list

	bool remove_at(int);
	//given an index, remove the element at that position
	//preserve the order of the other elements
	//return true if successful

	void insert(T);
	//inserts the argument to the back of the list
	//if list is full, increase the capacity by 10

	int size() { return msize; }
	//returns the number of elements in the list

	const list<T> operator=(const list<T>&);
	//copies the list given as an argument

	T& operator[](int);

	list<T> operator*(double) const;
	~list() { delete[] data; }  //destructor
private:
	T* data; //contains the elements of the list
	int capacity; //the capacity of the list
	int msize; //the number of the elements in the list
	void changeCapacity(int);
	//change the list capacity
};

template <class T>
list<T> list<T>::operator*(double x) const
{
	list<T> temp(*this);
	for (int i = 0; i < temp.msize; i++)
		temp.data[i] *= x;
	return temp;
}


template <class T>
list<T>::list(int c)
{
	capacity = c;
	msize = 0;
	data = new T[c];
}
template <class T>
list<T>::list(const list<T>& oL)
{
	capacity = oL.capacity;
	msize = oL.msize;
	data = new T[capacity];
	for (int i = 0; i < msize; i++)
		data[i] = oL.data[i];
}

template <class T>
void list<T>::print() const
{
	cout << "{";
	for (int i = 0; i < msize; i++)
		cout << data[i] << ", ";
	cout << "}";
}

template <class T>
bool list<T>::remove_at(int k)
{
	if (k < 0 || k >= msize)
		return false;
	for (int i = k; i <= msize - 2; i++)
		data[i] = data[i + 1];  //shift the data over 1
	msize--;  //decrease the msize by 1
	return true;
}


template <class T>
void list<T>::changeCapacity(int c)
{
	if (c > 0)
	{
		T* newd = new T[c];
		if (c < msize)   //if the list is shrinking, update the msize
			msize = c;
		for (int i = 0; i < msize; i++)
			newd[i] = data[i];
		delete[] data;
		data = newd;
		capacity = c;
	}
}

template <class T>
void list<T>::insert(T x)
{
	if (msize >= capacity)
		changeCapacity(capacity + 10);
	data[msize] = x;
	msize++;
}


template <class T>
const list<T> list<T>::operator=(const list<T>& oR)
//copies the list given as an argument
{
	if (this != &oR)
	{
		msize = oR.msize;
		capacity = oR.capacity;
		delete[] data; //deallocate the old data
		data = new T[capacity]; //allocate new memory for data
		for (int i = 0; i < msize; i++)
			data[i] = oR.data[i];  //copy elements over one by one
	}
	return *this;
}

template <class T>
ostream& operator<<(ostream& outstream, const list<T>& oR)
{
	outstream << "{";
	for (int i = 0; i < oR.msize; i++)
		outstream << oR.data[i] << ", ";
	outstream << "}";
	return outstream;
}

template <class T1>
bool operator>(const list<T1>& oL, const list<T1>& oR)
{
	return oL.msize > oR.msize;
}

template <class T>
T& list<T>::operator[](int k)
{
	if (k < 0 || k >= msize)
	{
		cout << "Index out of range" << endl;
		exit(0);
	}
	return data[k];
}


#endif