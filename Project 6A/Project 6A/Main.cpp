//main function is within this file

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void MenuDisplay()
{
	std::cout << "Select one of the given options\n"
		<< "K: open a new file\n"
		<< "W: write and save information of the current file\n"
		<< "R: read the information on the file\n"
		<< "D: display statistics of the file\n"
		<< "M: edit the file\n"
		<< "Q: quit the program\n";
}
int main()
{
	//variables
	int NumStudents;
	double scores[100];
	
	//file access
	ofstream foutput; //write data into file
	ifstream finput; //read data from file
	string FileName;

	
	char options;
	do
	{
		//variables
		float average, sum = 0;//option R

		MenuDisplay();
		std::cin >> options;
		if (options != 'q' && options != 'Q')
		{
			switch (options)
			{
			case 'K': //create new file
			case 'k': bool Valid; //variable that checks a number's validity
				std::cout << "What are the total number of students?\n";
				std::cin >> NumStudents;
				for (int i = 0; i < NumStudents; i++)
				{
					do
					{
						std::cout << "Input one score value\n";
						std::cin >> scores[i];
						if (scores[i] >= 0 && scores[i] <= 100)
							Valid = true;
						else
						{
							Valid = false;
							cout << "Invalid score.\n" << "Input a value from 0 to 100.\n";
						}
					} while (Valid == false);
				}
				break;
			case 'W': //store information on the file
			case 'w': std::cout << "Which file do you want to access?\n";
				std::cin >> FileName;
				foutput.open(FileName);
				foutput << NumStudents << endl;
				for (int i = 0; i < NumStudents; i++)
					foutput << scores[i] << endl;
				foutput.close();
				cout << "Information saved\n\n";
				break;
			case 'R': //read information on the file
			case 'r': std::cout << "Which file do you want to access?\n";
				std::cin >> FileName;
				finput.open(FileName);
				finput >> NumStudents;
				cout << "List of scores:\n";
				for (int i = 0; i < NumStudents; i++)
				{
					finput >> scores[i];
					cout << "Score " << (i+1) << ": " << scores[i] << endl;
				}
				finput.close();
				cout << "\n";
				break;
			case 'D': //display file statistics
			case 'd':
			{
				float average, sum = 0;//variables for average
				std::cout << "Which file do you want to access?\n";
				std::cin >> FileName;//read data on file
				finput.open(FileName);
				finput >> NumStudents;
				for (int i = 0; i < NumStudents; i++)
				{
					finput >> scores[i];
				}

				//average calculations
				for (int i = 0; i < NumStudents; i++)
				{
					sum = sum + scores[i];
				}
				average = sum / NumStudents;

				//highest and lowest calculations
				int x = 0; //stores score that is highest/lowest
				int highest, lowest;

				for (int i = 0; i < NumStudents; i++) //highest calculations
				{
					if (scores[x] > scores[i])
						highest = scores[x];
					else
					{
						highest = scores[i];
						x = i;
					}
				}
				//reset x
				x = 0;
				for (int i = 0; i < NumStudents; i++) //lowest calculations
				{
					if (scores[x] < scores[i])
					{
						lowest = scores[x];
					}
					else
					{
						lowest = scores[i];
						x = i;
					}
				}

				//display of data
				cout << "The average of the scores is: " << average << endl;
				cout << "The highest score is: " << highest << endl;
				cout << "The lowest score is: " << lowest << endl << endl;
			}
				break;
			case 'M': //edit on specific score
			case 'm': int i;
				cout << "Which element do you want to edit?\n" << "Input an element from 0 to " << NumStudents - 1 << endl;
				cin >> i;
				cout << "Input new score value.\n";
				cin >> scores[i];
				cout << "\n" << "Changes complete\n" << "Remember to use option 'W' to save these changes.\n";				
				break;
			default: cout << "invalid input\n\n";
			}
		}
	} while (options != 'Q' && options != 'q');

	char end;
	cout << "\nEnd of program\n" << "Goodbye\n";
	cin >> end;
}
