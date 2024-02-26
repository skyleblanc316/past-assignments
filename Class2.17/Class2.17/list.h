#ifndef LIST_H
#define LIST_H
#include <iostream>

using namespace std;

//implement a list of doubles

class list
{
	//overload << operator
	friend ostream& operator<<(ostream&, const list&);

	//overload == operator
	//l1==l2 is they have the same size and the same 
	//elements in the same order
	friend bool operator==(const list&, const list&);


public:
	list(int = 30);
	//default constructor: initialize data,size and capacity
	//the argument passed is the capacity of the list

	list(const list&);
	//overload the copy constructor

	void print() const;
	//print the contents of the list

	bool insert(double);
	//inserts the argument to the back of the list
	//return true if successful

	bool remove_at(int);
	//given an index, remove the element at that position
	//return true if successful

	void insert2(double);
	//insert at the end
	//if list is full, increase the capacity by 10

	int size() { return msize; }
	//returns the number of elements in the list


	const list operator=(const list&);
	//copies the list given as an argument

	//overload + operator
	//l3=l1+l2, means l1 and l2 do not change
	//and l3= {l1, l2} (l2 appended at the end of l1)
	list operator+(const list&);

	//overload the [] operator
	//so that cout << l1[k] makes sense

	double& operator[](int);

	~list() { delete[] data; }  //destructor

	static int listcount;
private:
	double* data; //contains the elements of the list
	int capacity; //the capacity of the list
	int msize; //the number of the elements in the list
	void changeCapacity(int);
	//change the list capacity
};



#endif