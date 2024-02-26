#include <iostream>
#include <string>

using namespace std;

void menu()
{
	cout << "Choose between the given options:\n"
		<< "1: convert from decimal to binary\n"
		<< "2: convert from binary to decimal\n"
		<< "3: quit program\n";
}

void decBin();

void binDec();

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
			case'2': binDec();
				break;
			default: cout << "invalid input\n";
			}
		}
	} while (options != '3');

	cout << "Good bye\n";
	system("pause");
	return 0;
}

void decBin()
{
	int decimal;
	int binary[10];
	cout << "input a decimal number: ";
	cin >> decimal;
	cout << endl;
	int n = decimal;
	int i;
	for (i = 0; n > 0; i++)
	{
		binary[i] = n % 2;
		n = n / 2;	
	}

	cout << decimal << " in binary is: ";
	for (i = i - 1; i >= 0; i--)
	{
		cout << binary[i];
	}
	cout << endl << endl << endl;
}

void binDec()
{
	string binary;
	int decimal;
	cout << "input a binary number: ";
	cin >> binary;
	cout << endl;

	int n = binary.length() - 1;
	int sum = 0;

	for (int i = 0; i < binary.length(); i++)
	{
		int d = binary[i] - '0';
		if (binary[i] == '1')
		{
			sum += d * pow(2, n);
		}
		n--;
	}
	decimal = sum;
	cout << binary << " in decimal is: " << decimal << endl << endl << endl;
}