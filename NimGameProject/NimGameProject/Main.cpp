//all functions happen within this file

#include <iostream>
using namespace std;

//variables
int n = 12; //number of coins at start of turn
int m = 3; //max coins per turn
bool lastWin = true; //decides if you win by taking last coin or not

void menuDisplay()//display of menu options
{
	cout << "Menu:\n\n"
		<< "H: How to play\n"
		<< "W: Win by taking the last coin\n"
		<< "L: Lose by taking the last coin\n"
		<< "N: Change the number of coins at the start of the game\n"
		<< "M: Change the maximum number of coins that can be taken in one turn\n"
		<< "P: Play the game\n"
		<< "Q: Quit the program\n\n";
}

void howToPlay()//display instrucitons on how to play
{
	cout << "User and computer players will take turns taking coins from the total until there are none left.\n"
		<< "User and computer have a limited number of coins per turn (set before the game starts)\n"
		<< "and can select any amount from 1 to the set max.\n"
		<< "Win conditions can be changed to either win by taking the last coin\n" 
		<< "or lose by taking the last coin\n"
		<< "User decides who will make the first turn\n\n\n";
}

void nimGame()//function for the game itself
{
	//variables
	char first;//stores who's first
	int userTake;//stores the number of coins user takes
	int comTake = 1;//stores the number of coins computer takes
	int i;//number of coins (used so 'n' does not get altered)
	int t;//max coins taken (used so 'm' does not get altered)
	bool userTurn; //tracks whose turn it is

	i = n;
	t = m;
	cout << "Who will start?\n"
		<< "C: computer\n"
		<< "U: user\n";
	cin >> first;
	cout << endl << endl;

	if (first == 'C' || first == 'c')//computer starts
	{
		do//computer's turn
		{
			if (i > 0)
			{
				userTurn = false;
				std::cout << "------------------------------------------------------------------\n";
				cout << "Computer's turn.\n";
				cout << "Computer took 1 coin from " << i << ": Now " << i - comTake << " are left.\n\n";
				i = i - comTake;
				std::cout << "------------------------------------------------------------------\n";
			}
			
			if (i > 0)//user's turn
			{
				do
				{
					userTurn = true;
					std::cout << "------------------------------------------------------------------\n";
					cout << "User's turn: How many coins will you take: ";
					cin >> userTake;
					if (userTake > t || userTake < 1)
					{
						cout << "Invalid input: Improper move.\n\n";
					}
				} while (userTake > t);
				cout << "User took " << userTake << " coins from " << i << ": Now " << i - userTake << " are left.\n\n";
				i = i - userTake;
				std::cout << "------------------------------------------------------------------\n";
			}
		} while (i > 0);
	}
	else//user starts
	{
		do
		{
			if (i > 0)//user's turn
			{
				do
				{
					userTurn = true;
					std::cout << "------------------------------------------------------------------\n";
					cout << "User's turn: How many coins will you take: ";
					cin >> userTake;
					if (userTake > t || userTake < 1)
					{
						cout << "Invalid input: Improper move.\n\n";
					}
				} while (userTake > t);
			
				cout << "User took " << userTake << " coins from " << i << ": Now " << i - userTake << " are left.\n\n";
				i = i - userTake;
				std::cout << "------------------------------------------------------------------\n";
			}


			if (i > 0)//computer's turn
			{
				userTurn = false;
				std::cout << "------------------------------------------------------------------\n";
				cout << "Computer's turn.\n";
				cout << "Computer took 1 coin from " << i << ": Now " << i - comTake << " are left.\n\n";
				i = i - comTake;
				std::cout << "------------------------------------------------------------------\n";
			}
		} while (i > 0);
	}

	if (lastWin)//decides winner based on who's turn it is and the win condition
	{
		if (userTurn == true)
		{
			cout << "User took that last coin.\n"
				<< "User is the winner." << "Good Job.\n\n\n";
		}
		else
		{
			cout << "Computer took the last coin.\n"
				<< "Computer is the winner.\n" << "Better luck next time.\n\n\n";
		}
	}
	else
	{
		if (userTurn == true)
		{
			cout << "User took that last coin.\n"
				<< "Computer is the winner.\n" << "Better luck next time\n\n\n";
		}
		else
		{
			cout << "Computer took the last coin.\n"
				<< "User is the winner.\n" << "Good job!\n\n\n";
		}
	}
}

int main()
{
	cout << "Dumb Version:\n\n";
	char options;
	do
	{
		cout << "------------------------------------------------------------------\n";
		menuDisplay();
		cout << "------------------------------------------------------------------\n"
			<< "Number of coins: " << n << endl
			<< "Max coins per turn: " << m << endl;
		if (lastWin)
		{
			cout << "Win by taking last coin\n";
		}
		else if (lastWin == false)
		{
			cout << "Lose by taking last coin\n";
		}
		cin >> options;
		cout << endl << endl << endl;
		if (options != 'q' && options != 'Q')
		{
			switch (options)
			{
			case 'N':
			case 'n': cout << "Input new coin total\n";
				cin >> n;
				cout << endl << endl << endl;
				break;
			case 'M':
			case 'm': cout << "Input new max coins per turn\n";
				cin >> m;
				cout << endl << endl << endl;
				break;
			case 'W':
			case 'w':
				lastWin = true;
				break;
			case 'L':
			case 'l':
				lastWin = false;
				break;
			case 'H':
			case 'h': howToPlay();
				break;
			case 'P':
			case 'p': nimGame();
				break;
			default: cout << "Invalid option\n\n";
			}
		}
	} while (options != 'q' && options != 'Q');
}