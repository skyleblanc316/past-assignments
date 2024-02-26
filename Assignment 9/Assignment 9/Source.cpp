#include <iostream>
#include <stack>
#include <cassert>
#include <queue>
#include <algorithm>


using namespace std;
template <class T>
void print(queue<T> q)
{
	while (!q.empty())
	{
		cout << q.front() << ", ";
		q.pop();
	}
}
//problem 1 alpha numeric characters
void removeNonAlphaNum(stack<char>& s)
{
	stack<char> temp;
	while (!s.empty())//loop opperation till empty
	{
		if (isalnum(s.top()))//isalnum gives true if the character is alphanumeric
		{
			temp.push(s.top());//add alphanumeric character to temp stack
			s.pop();
		}
		else
		{
			s.pop();//delete non alpha numeric character
		}
	}
	while (!temp.empty())//loop till empty
	{
		s.push(temp.top());//order already reversed in temp so it can go straight back to s;
		temp.pop();
	}
	return;
}

//problem 2 reverse a queue with a stack
template <class T>
void reverse(queue<T>& q)
{
	stack<T> reverse;
	while (!q.empty())//reverses the queue in the stack
	{
		reverse.push(q.front());
		q.pop();
	}
	while (!reverse.empty())//fills the queue back up
	{
		q.push(reverse.top());
		reverse.pop();
	}
}

//problem 3 balanced delimiters
bool balancedDelimiters(string s)
{
	stack<char> A;
	for (int i = 0; i < s.size(); i++)
	{
		char ch = s[i];
		if (ch == '(')
			A.push(ch);
		else if (ch == ')')
		{
			if (A.empty() || A.top() != '(')
				return false;
			A.pop();
		}
		else if (ch == '[')
			A.push(ch);
		else if (ch == ']')
		{
			if (A.empty() || A.top() != '[')
				return false;
			A.pop(); 
		}
		else if (ch == '{')
			A.push(ch);
		else if (ch == '}')
		{
			if (A.empty() || A.top() != '{')
				return false;
			A.pop();
		}
	}
	return A.empty();
}

int main()
{
	string s = "{[()]";

	if (balancedDelimiters(s))
	{
		cout << "balanced";
	}
	else
		cout << "not balanced";

	return 0;
}