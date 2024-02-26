//all function are in this file

#include <iostream>
#include <string>
using namespace std;

//question 7
//frequent last name

struct Person
{
	string first_name;
	string last_name;
	int age;
};

string mostFrequentLastName(Person A[], int n)
{
	string frequent;
	int counter = 0, max = 0;
	for (int i = 0; i < n; i++)
	{
		counter = 0;
		for (int x = 0; x < n; x++)
		{
			if (A[i].last_name == A[x].last_name)
			{
				counter++;
			}
		}
		if (counter > max)
		{
			max = counter;
			frequent = A[i].last_name;
		}
	}
	return frequent;
}

int main()
{
	Person A[100] = { {"Monty", "Burns", 80}, {"Homer", "Simpson", 55}, {"Moe", "Szyslak", 57},{"Marge", "Simpson", 52}, {"Bart", "Simpson", 10} };
	cout << mostFrequentLastName(A, 5) << endl;
	
	system("pause");
	return 0;
}

