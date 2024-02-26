

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include "list.h"

 using namespace std;


//problem 1 subset vector
template <class T>
bool isSubset(const vector<T>& v1, const vector<T>& v2)
{
	int counter = 0;//keeps track of similar values
	for (int i = 0; i < v1.size(); i++)
	{
		for (int j = 0; j < v2.size(); j++)
		{
			if (v1[i] == v2[j])
			{
				counter++;//add to the counter if there are similar elements
			}
		}
	}
	if (counter == v1.size())//return true if counter is the same size as v1
		return true;
	else
		return false;
}

//problem 2 recurrsion
int R(int n)
{
	if (n == 1)//base case
		return 0;
	else//general case
		return 2 * R(n / 2) + n - 1;
}

//problem 3 vector recurrsion
int zeroCount(const vector<int>& v, int k)
{
	if (k < 1)
		return 0;
	//general case
	else if (v[k - 1] == 0)
		return 1 + zeroCount(v, k - 1);
	else
		return 0 + zeroCount(v, k - 1);
}
//problem 4 common entries (queue)
template <class T>
queue<T> commonEntries(queue<T> Q1, queue<T> Q2)
{
	queue<T> Q3;
	while (!Q1.empty())
	{
		if (Q1.front() == Q2.front())//if there is a common element
		{
			Q3.push(Q1.front());//add to new queue
			Q1.pop();
			Q2.pop();
		}
		else//not a common element
		{
			Q1.pop();
			Q2.pop();
		}
	}
	return Q3;
}

//problem 5 stack element removal
template <class T>
void remove(stack<T>& s, T x)
{
	stack<T> s2;
	while (!s.empty())//loop till s is empty
	{
		if (s.top() == x)//move on to next element and do nothing if equal to x
			s.pop();
		else//add to temporary stack if element is not x
		{
			s2.push(s.top());
			s.pop();
		}
	}
	while (!s2.empty())
	{
		s.push(s2.top());
		s2.pop();
	}
	return;
}

//problem 6 conncected map
bool connected(map<char, vector<char>>& G, char x, char y)
{

	auto it = G.find(x); //itterator
	if (it->second.size() == 0)//if value is empty
		return false;
	for (int i = 0; i < it->second.size(); i++)//search the vector for the value
	{
		if (it->second[i] == y)
			return true;//if found return true
	}
	return false;
}
int main()
{
	BST<int> t;
	int n = 20;
	system("cls");
	cout << "A Binary Search Tree: \n\n";
	for (int i = 0; i < n; i++)
	{
		int x = rand() % 100 - 50;
		t.insert(x);
	}
	t.displayTree();
	t.height();

	system("pause");
	return 0;
}

