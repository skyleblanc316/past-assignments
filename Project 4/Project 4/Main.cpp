//main.cpp all program fucntions are within this file

#include <iostream>
using namespace std;

int main()
{
	//variables
	bool inservice; //store if program should be running
	char select; //store the input value
	int year; //input for leap year calculation
	double miles; //input for distance in miles
	double kilometer; //output for distance in kilometers
	bool isLeapYear; //output for leap year
	
	//loop output
	inservice = true;
	
	//loop
	while (inservice) //start of loop
	{
		cout << "Welcome\n"; //display of input options
		cout << "Select a given character and enter to begin calculations\n";
		cout << "Leap year (L)\n";
		cout << "Distance in miles to kilometers (D)\n";
		cout << "Quit program (Q)\n";
		cin >> select;
		if (select == 'L' || select == 'l') //if leap year is selected
		{
			cout << "input the year\n",
				cin >> year;
			if ((year % 4) == 0 && (year % 100) != 0) //is the year divisible by 4 and not divisible by 100
				isLeapYear = true;
			else
				if ((year % 400) == 0) //is the year divisible by 400
					isLeapYear = true;
				else
					isLeapYear = false;
			if (isLeapYear)
				cout << year << " is a leap year.\n";
		}
		else
			if (select == 'D' || select == 'd') //if distance is selected
			{
				cout << "input the distance in miles\n";
				cin >> miles;
				kilometer = miles * 1.609; //conversion to kilometers
				cout << "The distance in kilometers is " << kilometer << "km\n";
			}
			else
				if (select == 'Q' || select == 'q') //if quit is selected
				{
					cout << "Thank you for using this program.\n" << "Select any character and enter to end this program.\n";
					char end;
					cin >> end;
					inservice = false;
				}
				else //to let user know they selected an input that did not match any of the given inputs
					cout << "Input does not match any of the given characters.\n" << "Please select a proper character.\n";

	}
	//program automatically ends as soon as the loop ends
	return 0;

}