#include "DynStackQueue.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Testing stack operations ... " << endl;
	DynStack<int> s1;
	cout << "s1 : ";  s1.print(); cout << endl;
	
	//testing push and top
	for (int i = 0; i < 5; i++)
	{
		int x = rand() % 101;
		s1.push(x);
		cout << "\nPush (" << x << ")" << endl;
		cout << "s1 : ";  s1.print(); cout << endl;
		cout << "Top element : " << s1.top() << endl;
	}

	//testing pop

	cout<<endl;
	for (int i = 0; i < 5; i++)
	{
		int x = s1.pop();
		cout << "\nPopped " << x << endl;
		cout << "s1 : ";  s1.print(); cout << endl;
	}
	

	
	system("pause");
	system("cls");
	cout << "Testing queue operations ... " << endl;
	DynQueue<int> q1;
	cout << "q1 : ";  q1.print(); cout << endl;

	//testing enqueue
	for (int i = 0; i < 5; i++)
	{
		int x = rand() % 101;
		q1.enqueue(x);
		cout << "\nEnqueue (" << x << ")" << endl;
		cout << "q1 : ";  q1.print(); cout << endl;
	}
	
	//testing dequeue
	cout<<endl;
	for (int i = 0; i < 5; i++)
	{
		int x = q1.dequeue();
		cout << "\nRemoved " << x << endl;
		cout << "q1 : ";  q1.print(); cout << endl;
		cout << "Front element : " << q1.front() << endl;
	}
	
	

	system("pause");
	return 0;
}