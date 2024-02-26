#include <iostream>
#include <string>

using namespace std;

void menu()
{
	cout << "Choose between the given options:\n"
		<< "1: convert from decimal to binary\n"
		<< "2: convert from decimal to sign integer form (2's complement)\n"
		<< "3: quit program\n";
}

void decBin();

void decSignint();


int main()
{
	char options;
	do//where the program goes to based on menu options
	{
		menu();
		cin >> options;
		cout << endl;

		if (options != '3')
		{
			switch (options)
			{
			case '1': decBin();
				break;
			case'2': decSignint();
				break;
			default: cout << "invalid input\n";
			}
		}
	} while (options != '3');

	cout << "Good bye\n";
	system("pause");
	return 0;

}

void decBin()//conver from decimal to binary
{
	int decimal;
	int binary[10];
	
	do
	{
		cout << "input a decimal number: ";
		cin >> decimal;
		cout << endl;
		if (decimal > 255 || decimal < 0)
		{
			cout << "This number cannot be processed\n"
				<< "pick a number between 0 and 255\n";
		}
	} while (decimal > 255 || decimal < 0);

	int n = decimal;
	int i;
	
	for (i = 0; i < 8; i++)//puts the digits of the binary equivalent into an array
	{
		binary[i] = n % 2;
		n = n / 2;
	}

	cout << decimal << " in binary is: ";
	for (i = 7; i >= 0; i--)
	{
		cout << binary[i];
	}


	cout << endl << endl << endl;
}

void decSignint()//decimal to sign interger form
{
	int decimal;
	int signInt[10];
	
	do
	{
		cout << "input a decimal number: ";
		cin >> decimal;
		cout << endl;

		if (decimal > 127 || decimal < -127)
		{
			cout << "This number cannot be processed\n"
				<< "Pick a number between -127 and 127\n";
		}
	} while (decimal > 127 || decimal < -127);
	
	
	int n = decimal;
	int i;
	int compliment;//flips the non sign digits

	if (decimal < 0)
	{
		signInt[7] = 1;
		n = -decimal;//calculates the binary as if there was no sign
	}
	else if (decimal > 0)
	{
		signInt[7] = 0;
	}
	for (i = 0; i < 7; i++)
	{
		signInt[i] = n % 2;
		n = n / 2;
	}

	for (i = 0; i < 7; i++)
	{
		if (signInt[i] == 0)
		{
			signInt[i] = 1;
		}
		else if (signInt[i] == 1)
		{
			signInt[i] = 0;
		}
	}


	cout << decimal << " in signed integer is: ";
	for (i = 7; i >= 0; i--)
	{
		cout << signInt[i];
	}
	
	cout << endl << endl << endl;
}
