#ifndef LIST_H
#define LIST_H

//implement a list of doubles

class list
{
public:
	list(int = 30);
	//default constructor: initialize data, size, and capacity
	//the argument passed is the capacity of the list
	void print() const;
	//print the contents fo the list

	bool insert(double);
	//insert the argument to the back of the list
	//return true if seccessful

	bool remove_at(int);
	//given an index, remove the element at that position
	//return true if seccessful

	void insert2(double);
	//insert at the end
	//if list is full, increase the capacity to 10

	~list() { delete[] data; } //destructor

private:
	double* data; //contains the elements of the list
	int capacity; //the capacity of the list
	int size; //the number of elents in the list
	void changeCapacity(int);
	//changes capacity of the list
};


#endif