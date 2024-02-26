//main.cpp all functions of the program are within this folder

	#include <iostream>
	using namespace std;

	int main()
	{
		//given a natural number stored in n
		//find all the non-trivial divisers (divisors greater than 1)
		
		//variables
		int n; //input number
		int x; //number that changes and tests if a given number is a divisor (for input calculations)
		int num; //number that counts up from 2 to a given number (used in part 2 and 3)
		int DIL; //divisor for inner loop
		int D; //stores if a number is a divisor or not
		int divcounter; //keeps track of number of divisors
		int primecounter; //keeps track of number of prime numbers
		
		//initial information
		divcounter = 0;//starting point for the counter
						  
		//part 1: finding prime number based on input
		//input of number
		for (n = -1; n < 0;) //program won't start until a positive integer is used as an input
		{
			cout << "input a positive integer\n";
			cin >> n;
		}
		cout << endl;
		
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

		//part 2: finding prime numbers less than 100
		cout << "Prime numbers less than 100: ";

		primecounter = 0;
		for (num = 2; num <= 100; num++)
		{
			divcounter = 0; //reset number of divisors for new number
				for (DIL = 2; DIL < num; DIL++)
				{
					D = num % DIL;
					if (D == 0)
					{
						divcounter++;
					}
				}
				if (divcounter == 0)
				{//display that will only show prime numbers and increase the total of prime numbers
					cout << num << ",";
					primecounter++;
				}
		}
		cout << endl;//indents after all prime numbers have been displayed
		cout << "The total number of prime numbers less than 100 is: " << primecounter << endl << endl << endl;
		
		//part 3: finding first 30 prime numbers
		cout << "The first 30 prime numbers are:\n";
		primecounter = 0; //reset prime counter
		
		for (num = 2; primecounter < 30; num++) //loop that counts and divides endlessly till the number of prime numbers found is 30
		{
			divcounter = 0; //reset number of divisors for new number
			for (DIL = 2; DIL < num; DIL++)
			{
				D = num % DIL;
				if (D == 0)
				{
					divcounter++;
				}
			}
				if (divcounter == 0)
				{//display that will only show prime numbers and increase the total of prime numbers
					cout << num << ",";
					primecounter++;
				}
		}
		cout << endl << endl; //couple of indents to keep everything separated
		//end of program message
		cout << "end of program\n" << "input any character and enter to exit this program\n";
		char input;
		cin >> input;
	}