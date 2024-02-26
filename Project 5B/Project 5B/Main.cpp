

#include <iostream>
using namespace std;

bool PrimeCheck(int num)
{
	int D;
	int divcounter;
	bool IsPrime;
	divcounter = 0;

	for (int x = 2; x < num; x++)
	{
		D = num % x; //divide input number by ever number between itself and 1
		if (D == 0)
		{
			divcounter++;
		}
	}

	if (divcounter == 0)
	{
		IsPrime = true;
	}
	else
	{
		IsPrime = false;
	}
	return IsPrime;
}

void PrimeLessthan(int num)
{
	int DIL; //divisor for prime check
	int D; //stores if a number is a divisor or not
	int n;
	int divcounter; //stores the number of divisors
	int primecounter;
	primecounter = 0;
	for (n = 2; n <= 100; n++)
	{
		divcounter = 0; //reset number of divisors for new number
		for (DIL = 2; DIL < n; DIL++)
		{
			D = n % DIL;
			if (D == 0)
			{
				divcounter++;
			}
		}
		if (divcounter == 0)
		{//display that will only show prime numbers and increase the total of prime numbers
			cout << n << ",";
			primecounter++;
		}
		
	}
	cout << endl;
	cout << "The number of prime numbers less than " << num << " are:" << primecounter << endl << endl;
	

}

int PrimeNumN(int num)
{
	int DIL; //divisor for prime check
	int D; //stores if a number is a divisor or not
	int n;
	int divcounter; //stores the number of divisors
	int primecounter;
	primecounter = 0;
	for (n = 2; primecounter < num; n++) //loop that counts and divides endlessly till the number of prime numbers found is 30
	{
		divcounter = 0; //reset number of divisors for new number
		for (DIL = 2; DIL < n; DIL++)
		{
			D = n % DIL;
			if (D == 0)
			{
				divcounter++;
			}
		}
		if (divcounter == 0)
		{
			primecounter++;
		}
	}
	return n - 1;
}

//menu display
void MenuDisplay()
{
	cout << "Welcome\n" << "select a number to continue\n" 
		<< "1. Check if a number is a prime number\n"
		<< "2. List all prime numbers less than a given number\n" 
		<< "3. List the 'n'th prime number\n" 
		<< "4. Quit the program\n";
}
int main() //main fucntion that calls upon calculations
{
	int options; //stores input for list
	
	//variables
	int num;

	//options loop
	do
	{
		MenuDisplay();
		cin >> options;
		if (options != 4)
		{
			switch (options)
			{
			case 1: cout << "\tprime number check\n";
				cout << "input a positive number\n";
				cin >> num; //input for prime check function
				if (PrimeCheck(num)) //proper display if number is a prime or not
					cout << num << " is a prime number\n\n";
				else
					cout << num << " is not a prime number \n\n";
				break;
			case 2: cout << "\tPrimes less than 'n'\n";
				cout << "input a positive number\n";
				cin >> num;
				PrimeLessthan(num);
				break;
			case 3: cout << "\tPrime number 'n'\n";
				cout << "Input a positive number\n";
				cin >> num;
				cout << "prime number " << num << " is: " << PrimeNumN(num) << endl << endl;
				break;
			default: cout << "invalid input\n\n";
			}
		}
	} while (options != 4);

	cout << "End of program\n" << "Goodbye\n";
	char end;
	cin >> end;
}
