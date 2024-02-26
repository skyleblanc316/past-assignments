#ifndef LIST_H
#define LIST_H
//implement a list of doubles
class list
{
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

	list operator=(const list&);
	//copies the list given as an argument

	~list() { delete[] data; }  //destructor
private:
	double* data; //contains the elements of the list
	int capacity; //the capacity of the list
	int msize; //the number of the elements in the list
	void changeCapacity(int);
	//change the list capacity
};
#endif