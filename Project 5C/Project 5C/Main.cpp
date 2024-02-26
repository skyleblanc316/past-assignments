//all functions are within this file

#include <iostream>
using namespace std;

bool isleapyear(int Year)//leap year check function
{
	bool isLeapYear;
	if ((Year % 4) == 0 && (Year % 100) != 0) //is the year divisible by 4 and not divisible by 100
		isLeapYear = true;
	else
		if ((Year % 400) == 0) //is the year divisible by 400
			isLeapYear = true;
		else
			isLeapYear = false;
	return isLeapYear;//return true or false value
}

bool ValidDate(int Month, int Day, int Year)
{
	//call leap year check for February
	bool isLeapYear;
	if (isleapyear(Year))
	{
		isLeapYear = true;
	}
	else
	{
		isLeapYear = false;
	}
	//month validation
	bool isMonth;
	if (Month >= 1 && Month <= 12) //is the month value within the range 1-12 (including 1 and 12)
		isMonth = true;
	else
		isMonth = false;

	//day validation
	bool isDay;
	if (Month == 4 || Month == 6 || Month == 9 || Month == 11) //30 day month
		if (Day >= 1 && Day <= 30)
			isDay = true;
		else
			isDay = false;
	else
		if (Month == 2 && isLeapYear == true) //February on a leap year
			if (Day >= 1 && Day <= 29)
			{
				isDay = true;
			}
			else
			{
				isDay = false;
			}
		else
			if (Month == 2 && isLeapYear == false) //February on a non leap year
				if (Day >= 1 && Day <= 28)
					isDay = true;
				else
					isDay = false;
			else
				if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12) //31 day month
					if (Day >= 1 && Day <= 31)
						isDay = true;
					else
						isDay = false;
				else
					isDay = false;
	bool ValidDate;//stores if date is valid
	if (isDay)
	{
		ValidDate = true;
	}
	else
	{
		ValidDate = false;
	}
	return ValidDate;
}
int main()
{
	//variables
	int Day, Month, Year;
	//Birthdate validation of user
	cout << "Input your birthdate\n"
		<< "Month ";
	cin >> Month;
	cout << "Day ";
	cin >> Day;
	cout << "Year ";
	cin >> Year;

	if (isleapyear(Year))
		cout << "\n" << Year << " is a leap year\n";
	else
		cout << "\n" << Year << " is not a leap year\n";

	if (ValidDate(Month, Day, Year))
		cout << "Date is valid\n\n";
	else
		cout << "Date is invalid\n\n";

	//Birthdate validation of user's mother
	cout << "Input your mother's birthdate\n"
		<< "Month ";
	cin >> Month;
	cout << "Day ";
	cin >> Day;
	cout << "Year ";
	cin >> Year;

	if (isleapyear(Year))
		cout << "\n" << Year << " is a leap year\n";
	else
		cout << "\n" << Year << " is not a leap year\n";

	if (ValidDate(Month, Day, Year))
		cout << "Date is valid\n\n";
	else
		cout << "Date is invalid\n\n";

	//Birthdate validation of user's father
	cout << "Input your father's birthdate\n"
		<< "Month ";
	cin >> Month;
	cout << "Day ";
	cin >> Day;
	cout << "Year ";
	cin >> Year;

	if (isleapyear(Year))
		cout << "\n" << Year << " is a leap year\n";
	else
		cout << "\n" << Year << " is not a leap year\n";

	if (ValidDate(Month, Day, Year))
		cout << "Date is valid\n\n";
	else
		cout << "Date is invalid\n\n";

	char end;
	cout << "End of program\n" << "Goodbye\n";
	cin >> end;
}