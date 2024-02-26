//Main.cpp all functions of the program are within this file

#include <iostream>
using namespace std;

int main()
{
	//Variables
	int P; //input for # of pennies
	int N; //input for # of nickels
	int D; //input for # of dimes
	int Q; //input for # of quarters
	int USC; //output to total number of cents
	int USD; // cents converted to dollars and cents
	int USRC; //remainder of cents after dollar calculation
	int TWC; //total in Taiwanese cents
	int TWD; //total in Taewanese dollars
	int TWCR; //remainder of Taiwanese cent after dollar calculation


	//input
	cout << "The number of pennies is?" << endl;
	cin >> P;
	cout << "The number of nickels is?" << endl;
	cin >> N;
	cout << "The number of dimes is?" << endl;
	cin >> D;
	cout << "The number of quarters is?" << endl;
	cin >> Q;

	//calculations
	USC = P + N * 5 + D * 10 + Q * 25;
	USD = USC / 100;
	USRC = USC % 100;


	//output
	cout << "The total number of cents is " << USC << endl;

	cout << "The amount in dollars is $" << USD << endl;
	cout << "The amuont of cents left over is $0." << USRC << endl;

	//conversion to Taiwanese (conversion number based off of PDF example not current rates)

	TWC = 33 * USC;
	TWD = TWC / 100;
	TWCR = TWC % 100;

	//output of conversion
	cout << "the total number of Taiwanese cents is " << TWC << endl;
	cout << "the amount in Taiwanese dollars is $" << TWD << endl;
	cout << "the amount of Taiwanese cents left over is $0." << TWCR << endl;

	// good bye message

	cout << "Conversion complete" << endl; cout << "Press any character and enter to exit this program." << endl;

	//charcter input to end program
	char inputCharacter; //input character that will end program
	cin >> inputCharacter; //wait for input character

	//end program
	return 0;
}
