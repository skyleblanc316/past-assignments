	//Main.cpp all functions of this program are in this file

#include <iostream>
using namespace std;

int main()
{
	//variables
	int age; //input for age
	double hrw; //input for hours worked
	double HRR; //input for hourly rate
	double gross; //gross pay output
	double UnionDue; //union due output
	double net; //net pay output

	//inputs
	cout << "what is the age?" << endl;
	cin >> age;
	
	cout << "how many hours worked?" << endl;
	cin >> hrw;

	cout << "what is the hourly rate?" << endl;
	cin >> HRR;

	//calculations
	if (hrw <= 40) //if hours worked is 40 hours or less
	{
		gross = hrw * HRR;
	}
	else
	{
		gross = (40 * HRR) + ((hrw - 40) * (HRR * 1.5));
	}

	if (gross < 200) //if gross pay is less than 200 a week
	{
		UnionDue = 0;
	}
	else
	{
		if (age < 60)   //if age is less than 60
		{
			UnionDue = 15.00;
		}
		else
		{
			UnionDue = 5.00;
		}
	}

	net = gross - UnionDue;


	//output
	cout << "The gross pay is $" << gross << endl;
	cout << "The union due is $" << UnionDue << endl;
	cout << "The net pay is $" << net << endl;

	// good bye message

	cout << "Net pay calculations complete" << endl; cout << "Press any character and enter to exit this program." << endl;

	//charcter input to end program
	char inputCharacter; //input character that will end program
	cin >> inputCharacter; //wait for input character

	//end program
	return 0;
}

//–Declare appropriate variables of the double typeand /or the int type
//–Display guiding instructions to the userand
//read in the age, work hours, and regular hourly rate
//–Compute the gross payand store it in a variable
//–Compute the union dueand store it in a variable
//–Compute the net payand store it in a variable
//–Display the amount of gross pay, the union due, and the net pay