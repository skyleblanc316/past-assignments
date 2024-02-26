#include <iostream>
#include <string>


using namespace std;

string decBin(double num)
{
    string binary;
    if (num < 0)
    {
        num = num * -1;
    }
    // Fetch the integral part of decimal number 
    int Integral = num;

    // Fetch the fractional part decimal number 
    double fractional = num - Integral;

    // Conversion of integral part to 
    // binary equivalent 
    while (Integral)
    {
        int rem = Integral % 2;

        // Append 0 in binary 
        binary.push_back(rem + '0');

        Integral /= 2;
    }

    // Reverse string to get proper binary form
    reverse(binary.begin(), binary.end());

    // Append point before conversion of 
    // fractional part 
    binary.push_back('.');

    // Conversion of fractional part to binary 
    int k = 8;
    while (k-- && fractional != 0)
    {
        fractional *= 2;
        int fractBin = fractional;

        if (fractBin == 1)
        {
            fractional -= fractBin;
            binary.push_back(1 + '0');
        }
        else
            binary.push_back(0 + '0');
    }

    return binary;
}
string decBinexponent(int num)
{
    string binary;

    for (int i = 4; i >= 0; i--)
    {
        int element = num % 2;

        binary.push_back(element + '0');

        num /= 2;
    }
    
    //reverses the order of the string to put it in proper binary form
    reverse(binary.begin(), binary.end());

    return binary;
}

string floating(double A, double binary, string bin)
{
    string floating;
    //if number is negative
    if (A < 0)
    {
        floating.push_back(1 + '0');
    }
    else
        floating.push_back(0 + '0');
    int n = 0;
    int i = 0;
    double significand = binary;
    if (binary > 2)
    {
        while (significand > 2)
        {
            significand = binary * pow(10, i);
            i--;
        }
        i = i + 1;
        i = i * -1;
    }
    else if (binary > 1 && binary < 2)
    {
        significand = binary;
    }
    else if (binary < 1 || binary > -1)
    {
        while (significand < 1)
        {
            significand = binary * pow(10, i);
            i++;
        }
        i = i - 1;
        i = i * -1;
    }
    n = i + 15;
    int x;
    if (i < 0)//stores the element the decimal point is stored on
        x = i * -1;
    else
        x = i;
    
    string exponent = decBinexponent(n);

    for (int i = 0; i < 5; i++)
    {
        floating.push_back(exponent[i]);
    }
    if (A < 1 && A > -1)
    {
        bin.erase(bin.begin()+0);
        bin.erase(bin.begin()+(x - 1));
    }
    else
    {
        bin.erase(bin.begin()+0);//deletes the first element
        bin.erase(bin.begin()+x);//deletes the decimal point
    }

    if (bin.length() < 8)
    {
        for (int i = 0; i < bin.length(); i++)
        {
            floating.push_back(bin[i]);
        }
    }
    else
    {
        for (int i = 0; i < 8; i++)
        {
            floating.push_back(bin[i]);
        }
    }
    
    int fL = 14 - floating.length();
    while(fL < 14 && fL > 0)
    {
        floating.push_back(0 + '0');
        fL--;
    }
    return floating;
}

int main()
{
	double A;
	cout << "Floating point form\n";
	cout << "Input a number: ";
	cin >> A;
	cout << endl;
	
    //convert to binary
	double binary = stod(decBin(A));//converts the string to a double
    string bin = decBin(A);

    cout << A << " in floating point binary: " << floating(A, binary, bin) << endl;

    system("pause");
    return 0;
	
}