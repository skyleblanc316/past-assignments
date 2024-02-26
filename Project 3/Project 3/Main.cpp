//Main.cpp all functions of the program are within this folder

#include <iostream>
using namespace std;

int main()
{
	//declare variables
	//input variables
	int DayUser, MonthUser, YearUser; //birthday of user
	int DayMom, MonthMom, YearMom; //birthday of the mother
	int DayDad, MonthDad, YearDad; //birthday of the father
	//calculation variables (variables that remember true or false)
	bool isMonthU, isMonthM, isMonthD; //remember if birth month is true
	bool isDayU, isDayM, isDayD; //remember if birth day is true
	bool isLeapYearU, isLeapYearM, isLeapYearD; //remember if birth year is a leap year or not
	//birthday integer
	int BIU; //birthday integer of user
	int BIM; //birthday integer of mom
	int BID; //birthday integer of dad
	
	//inputs
	cout << "When is your birthday?" << endl; //request inputs of user's birthday
	cout << "Month "; cin >> MonthUser;
	cout << "Day "; cin >> DayUser;
	cout << "Year "; cin >> YearUser;

	cout << "When is your Mom's birthday?" << endl; //request inputs of the birthday of the user's mom
	cout << "Month "; cin >> MonthMom;
	cout << "Day "; cin >> DayMom;
	cout << "Year "; cin >> YearMom;

	cout << "When is your Dad's birthday?" << endl; //request inputs of the birthday of the user's dad
	cout << "Month "; cin >> MonthDad;
	cout << "Day "; cin >> DayDad;
	cout << "Year "; cin >> YearDad;

	//calculations and/or operations
	//is the year a leap year
		
	//user
	if ((YearUser % 4) == 0 && (YearUser % 100) != 0) //is the year divisible by 4 and not divisible by 100
		isLeapYearU = true;
	else
		if ((YearUser % 400) == 0) //is the year divisible by 400
			isLeapYearU = true;
		else
			isLeapYearU = false;
	//mom
	if ((YearMom % 4) == 0 && (YearMom % 100) != 0)
		isLeapYearM = true;
	else
		if ((YearMom % 400) == 0)
			isLeapYearM = true;
		else
			isLeapYearM = false;
	//dad
	if ((YearDad % 4) == 0 && (YearDad % 100) != 0)
		isLeapYearD = true;
	else
		if ((YearDad % 400) == 0)
			isLeapYearD = true;
		else
			isLeapYearD = false;
	
	//is the month real
	
	//user
	if (MonthUser >= 1 && MonthUser <= 12) //is the month value within the range 1-12 (including 1 and 12)
		isMonthU = true;
	else
		isMonthU = false;
	//mom
	if (MonthMom >= 1 && MonthMom <= 12)
		isMonthM = true;
	else
		isMonthM = false;
	//dad
	if (MonthDad >= 1 && MonthDad <= 12)
		isMonthD = true;
	else
		isMonthD = false;
	
	//is the day real
	
	//user
	if (MonthUser == 4 || MonthUser == 6 || MonthUser == 9 || MonthUser == 11) //30 day month
		if (DayUser >= 1 && DayUser <= 30)
			isDayU = true;
		else
			isDayU = false;
	else
		if (MonthUser == 2 && isLeapYearU == true) //February on a leap year
			if (DayUser >= 1 && DayUser <= 29)
				isDayU = true;
			else
				isDayU = false;
		else
			if (MonthUser == 2 && isLeapYearU == false) //February on a non leap year
				if (DayUser >= 1 && DayUser <= 28)
					isDayU = true;
				else
					isDayU = false;
			else
				if (MonthUser == 1 || MonthUser == 3 || MonthUser == 5 || MonthUser == 7 || MonthUser == 8 || MonthUser == 10 || MonthUser == 12) //31 day month
					if (DayUser >= 1 && DayUser <= 31)
						isDayU = true;
					else
						isDayU = false;
				else
					isDayU = false; //day on a month value outside of the proper range
	//mom
	if (MonthMom == 4 || MonthMom == 6 || MonthMom == 9 || MonthMom == 11)
		if (DayMom >= 1 && DayMom <= 30)
			isDayM = true;
		else
			isDayM = false;
	else
		if (MonthMom == 2 && isLeapYearM == true)
			if (DayMom >= 1 && DayMom <= 29)
				isDayM = true;
			else
				isDayM = false;
		else
			if (MonthMom == 2 && isLeapYearM == false)
				if (DayMom >= 1 && DayMom <= 28)
					isDayM = true;
				else
					isDayM = false;
			else
				if (MonthMom == 1 || MonthMom == 3 || MonthMom == 5 || MonthMom == 7 || MonthMom == 8 || MonthMom == 10 || MonthMom == 12)
					if (DayMom >= 1 && DayMom <= 31)
						isDayM = true;
					else
						isDayM = false;
				else
					isDayM = false;
	//dad
	if (MonthDad == 4 || MonthDad == 6 || MonthDad == 9 || MonthDad == 11) //30 day month
		if (DayDad >= 1 && DayDad <= 30)
			isDayD = true;
		else
			isDayD = false;
	else
		if (MonthDad == 2 && isLeapYearD == true) //February on a leap year
			if (DayDad >= 1 && DayDad <= 29)
				isDayD = true;
			else
				isDayD = false;
		else
			if (MonthDad == 2 && isLeapYearD == false) //Febraury on a non leap year
				if (DayDad >= 1 && DayDad <= 28)
					isDayD = true;
				else
					isDayD = false;
			else
				if (MonthDad == 1 || MonthDad == 3 || MonthDad == 5 || MonthDad == 7 || MonthDad == 8 || MonthDad == 10 || MonthDad == 12) //31 day month
					if (DayDad >= 1 && DayDad <= 31)
						isDayD = true;
					else
						isDayD = false;
				else
					isDayD = false; //any day within a month value outside the range
	//outputs (output order: month,day,year)
	
	//user
	if (isMonthU && isDayU) //validity of the date
		cout << "User's birthdate valid" << endl;
	else
		if (!isMonthU && !isDayU) //month is invalid
			cout << "User's birthdate invalid. Month value invalid" << endl;
		else
			cout << "User's birthdate invalid. Day value invalid" << endl;
	
	if (isLeapYearU) //display whether or not given year is a leap year or not
		cout << YearUser << " is a leap year" << endl;
	else
		cout << YearUser << " is not a leap year" << endl;
	//mom
	if (isMonthM && isDayM) //validity of the date
		cout << "Mother's birthdate valid" << endl;
	else
		if (!isMonthM && !isDayM) //month is invalid
			cout << "Birthdate of mother is invalid. Month value invalid" << endl;
		else
			cout << "Birthdate of mother is invalid. Day value invalid" << endl;

	if (isLeapYearM) //display whether or not given year is a leap year or not
		cout << YearMom << " is a leap year" << endl;
	else
		cout << YearMom << " is not a leap year" << endl;
	//dad
	if (isMonthD && isDayD) //validity of the date
		cout << "Father's birthdate valid" << endl;
	else
		if (!isMonthD && !isDayD) //month is invalid
			cout << "Birthdate of father is invalid. Month value invalid" << endl;
		else
			cout << "Birthdate of father is invalid. Day value invalid" << endl;

	if (isLeapYearD) //display whether or not given year is a leap year or not
		cout << YearDad << " is a leap year" << endl;
	else
		cout << YearDad << " is not a leap year" << endl;
	
	//Check that user is younger than parents (birthday integer calculations here as well)
	BIU = (YearUser * 10000) + (MonthUser * 100) + (DayUser * 1);
	BIM = (YearMom * 10000) + (MonthMom * 100) + (DayMom * 1);
	BID = (YearDad * 10000) + (MonthDad * 100) + (DayDad * 1);

	if (BIU < BIM || BIU < BID)
		cout << "User's age invalid. User cannot be older than their parents." << endl; //output if user is older than parents
	else if (BIU == BIM || BIU == BID)
		cout << "User's age invalid. User cannot be the same age as their parents." << endl; //output if user is same age as one parent

	cout << "Birthday program complete. Select any character and enter to exit this program" << endl;
	char characterinput;
	cin >> characterinput;

	return 0;

}
//logic of calculations
//check leap year: 
	//is year divisible by 4 and not by 100; if not => is it divisible by 400; if not => is not leap year
//check month: 
	//is month within the range 1-12 (including 1 and 12) month is valid; if not => month is invalid
//check day: 
	//if month is a 30 day month then day is between 1-30; 
	//if not => if month is 2 and a leap year then day range is 1-29; 
	//if not => if month is 2 and not a leap year then day range is 1-28; 
	//if not => if month has 31 days then day range is 1-31; 
	//if not => then day is invalid



//notes
//bool can be used to make calculations before implementing them into logic statements
//output of logic statement still needs to be bool
