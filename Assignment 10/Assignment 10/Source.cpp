#include <iostream>
#include <vector>
#include <queue>

using namespace std;


//problem 1 exponent recursion
double power(double base, int exponent)
{
	if (exponent == 0)
		return 1;
	return base * power(base, exponent - 1);
}

//problem 2 vector search
template <class T>
bool find(const vector<T>& v, T value, int n)
{
	T x;
	if (n == 0)//base case (not found if n reaches 0)
		return false;
	x = v[n - 1];//get value at this element
	
	if (value == x)//check if value is at this element
		return true;
	else//move to next element if not found
		return find(v, value, n - 1);

}

//problem 3 reverse a queue recursively
template <class T>
void reversePrint(queue<T> q)
{
	if (q.empty())
		return;
	T store = q.front();//store front value
	q.pop();//remove front value
	reversePrint(q);//display next value
	cout << store << ", ";//display stored value

}

int main()
{
	queue<int> q;
	queue<int> q2;//temporary storage queue
	for (int i = 0; i < 8; i++)
	{
		q.push(rand() % 101);
	}
	cout << "original q: { ";
	while (!q.empty())//display the queue in the original order
	{
		cout << q.front() << ", ";
		q2.push(q.front());
		q.pop();
	}
	cout << "}" << endl;

	while (!q2.empty())//put the values back into the original queue
	{
		q.push(q2.front());
		q2.pop();
	}


	cout << "reversed q: { ";//display reversed queue
	reversePrint(q);
	cout << "}" << endl;
	

	system("pause");
	return 0;
}