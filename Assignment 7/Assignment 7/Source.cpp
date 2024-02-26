#include <iostream>
#include <string>

#include <vector>
#include <algorithm> 
#include <fstream>
#include <set>
#include <map>
using namespace std;

//problem 1 int pair
template <class T>
int pairCount(const vector<T>& v)//assuming it is sorted
{
	int count = 1;
	int pairCount = 0; //counts number of pairs
	for (int i = 0; i < v.size(); i++)//element to count
	{
		i = i + (count - 1);
		count = 0;
		if (i != 10)
		{
			for (int x = 0; x < v.size(); x++)//counts how many of an element there is
		{
			if (v[i] == v[x])
			{
				count++;

			}

		}
		if (count == 2)
			pairCount++;
		}
	}
	return pairCount;
}

//problem 3 listing characters
map<char, int> charFreq(string filename)
{
	ifstream ifile(filename);
	if (!ifile)
	{
		cout << "error opening file...";
		exit(1);
	}

	map<char, int> toBeM;

	char character;
	while (true)
	{
		ifile >> character;
		if (!ifile)
			break;


		auto it = toBeM.find(character);  //character search

		if (it == toBeM.end())  //character not found
			toBeM[character] = 1;
		else
			toBeM[character]++;
	}
	return toBeM;
}

//problem 2 common elements
template <class T>
vector<T> intersection(const vector<T>& va, const vector<T>& vb)
{
	vector<T> vc;
	for (int i = 0; i < va.size(); i++)
	{
		if (va[i] == vb[i])
			vc.push_back(va[i]);
	}
	return vc;
}

int main()
{
	
	vector<int> v = { 1,2,3,4,5 };
	vector<int> vb = { 6,7,3,4,5 };
	vector<int> vc = intersection(v, vb);
	cout << "Common elements: {";
	for (int i = 0; i < vc.size(); i++)
		cout << vc[i] << ", ";
	cout << "}" << endl;

	system("pause");
	return 0;
}