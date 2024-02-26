//entire program is perfomed here

#include <iostream>
using namespace std;


//function prototype for menu options
void LeapYear();
void CheckPrime();

//displays menu options
void Display_Menu()
{
	cout << "\tProgram menu\n" << "Select one of the given options\n"
		<< "'L' determine if a year is a leap year\n"
		<< "'P' determine if a number is a prime number\n"
		<< "'Q' end program\n";
	return;
}

//main function (processes menu choices)
int main()
{
	//menu choice variable
	char option;

	do //display menu and process menu options
	{
		Display_Menu();
		cin >> option;
		if (option != 'Q' && option != 'q')
		{
			switch (option)
			{
			case 'l':
			case 'L': LeapYear();
				break;
			case 'p':
			case 'P': CheckPrime();
				break;
			default: cout << "invalid input\n";
			}
		}
	} while (option != 'Q' && option != 'q');

	cout << "End of program.\n" << "Good Bye.\n";
	char endprogram;
	cin >> endprogram;
	return 0;
}

void LeapYear() //function to check if year is a leap year
{
	int year;
	bool isLeapYear;

	cout << "\n\tLeap Year Processor\n" << "input the year\n",
		cin >> year;
	if ((year % 4) == 0 && (year % 100) != 0) //is the year divisible by 4 and not divisible by 100
		isLeapYear = true;
	else
		if ((year % 400) == 0) //is the year divisible by 400
			isLeapYear = true;
		else
			isLeapYear = false;
	if (isLeapYear)
		cout << year << " is a leap year.\n\n\n";
	return;
}

void CheckPrime() //funtion to check if input is a prime number
{
	int n; //input number
	int x; //number that changes and tests if a given number is a divisor (for input calculations)
	int D; //stores if a number is a divisor or not
	int divcounter; //keeps track of number of divisors
	
	for (n = -1; n < 0;) //program won't start until a positive integer is used as an input
	{
		cout << "\n\tPrime Number Test";
		cout << "input a positive integer\n";
		cin >> n;
	}
	cout << endl;
	divcounter = 0;
	for (x = 2; x < n; x++)
	{
		D = n % x; //divide input number by ever number between itself and 1
		if (D == 0)
		{
			cout << n << " is divisible by " << x << endl;
			divcounter++;
		}
	}

	if (divcounter == 0)
		cout << n << " is a prime number\n\n\n";
	else
		cout << n << " is not a prime number\n\n\n";
}