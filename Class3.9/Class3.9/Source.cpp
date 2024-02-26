#include <iostream>
#include <string>

#include <vector> //for the vector template
#include <algorithm>

using namespace std;

template <class t>
void print(vector<t> v)
{
	/*for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ", ";
	}*/

	for (t value : v)
		cout << value << ", ";
}

//given int data in a vector, return true if there are any two elements that add to 0
bool matchingPair(vector<int> v)
{
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		int x = -v[i];
		/*for (int j = i + 1; j < v.size(); j++)
			if (v[j] == x)
				return true;*/
		//if v was sorted we can use binary search
		bool found = binary_search(v.begin(), v.end(), x);
		if (found)
			return true;
	}
	return false;
}



int main()//next step how to implement the language in an efficient manner
{
	vector <int> vi; //vector of integers
	vector <string> vx; //vector of strings
	//allocates memory automatically

	vector<int>::iterator it; //iterator for all integer vectors


	cout << "size of vi is " << vi.size() << endl;
	int n = 20;
	for (int i = 0; i < n; i++)
	{
		int x = rand() % 201 - 100;
		vi.push_back(x);
	}
	cout << "vi: ";
	print(vi);
	cout << endl;

	sort(vi.begin(), vi.end());

	cout << "vi: ";
	print(vi);
	cout << endl;

	








	system("pause");
	return 0;
}