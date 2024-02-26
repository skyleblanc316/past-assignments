//main function is within this file

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//file access
ofstream foutput; //write data into file
ifstream finput; //read data from file
string FileName;

struct stdRecord
{
	string firstName;
	string lastName;
	double score;
};
int NumStudents;
stdRecord stdRecordsArray[100];

void MenuDisplay()//display of menu options
{
	std::cout << "Select one of the given options\n"
		<< "K: open a new file\n"
		<< "W: write and save information of the current file\n"
		<< "R: read the information on the file\n"
		<< "D: display statistics of the file\n"
		<< "S: sort the information by student score\n"
		<< "N: sort the information by student name\n"
		<< "M: edit the file\n"
		<< "Q: quit the program\n";
}

//swap function
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void NameSort()
{
	int maxElement, index;
	for (maxElement = NumStudents - 1; maxElement > 0; maxElement--)
	{
		for (index = 0; index < maxElement; index++)
		{
			if (stdRecordsArray[index].lastName > stdRecordsArray[index + 1].lastName)
			{
				swap(stdRecordsArray[index], stdRecordsArray[index + 1]);
			}
			else if (stdRecordsArray[index].lastName == stdRecordsArray[index + 1].lastName)
			{
				if (stdRecordsArray[index].firstName > stdRecordsArray[index + 1].firstName)
				{
					swap(stdRecordsArray[index], stdRecordsArray[index + 1]);
				}
			}
		}
	}
	cout << "List of students:\n";
	for (int index = 0; index < NumStudents; index++)
	{
		cout << "Student " << (index + 1) << ": "
			<< stdRecordsArray[index].firstName << " "
			<< stdRecordsArray[index].lastName << ": "
			<< stdRecordsArray[index].score << endl;
	}
}

void ScoreSort()//function for sorting student scores
{
	int maxElement, index;
	for (maxElement = NumStudents - 1; maxElement > 0; maxElement--)
	{
		for (index = 0; index < maxElement; index++)
		{
			if (stdRecordsArray[index].score > stdRecordsArray[index + 1].score)
			{
				swap(stdRecordsArray[index], stdRecordsArray[index + 1]);
			}
		}
	}
	cout << "List of students:\n";
	for (int index = 0; index < NumStudents; index++)
	{
		cout << "Student " << (index + 1) << ": "
			<< stdRecordsArray[index].firstName << " "
			<< stdRecordsArray[index].lastName << ": "
			<< stdRecordsArray[index].score << endl;
	}
}

int main()//main function
{



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
					std::cout << "Input the student's first name\n";//first name input
					std::cin >> stdRecordsArray[i].firstName;

					std::cout << "Input the sutdent's last name\n";//last name input
					std::cin >> stdRecordsArray[i].lastName;

					do//score input
					{
						std::cout << "Input one score value\n";
						std::cin >> stdRecordsArray[i].score;
						if (stdRecordsArray[i].score >= 0 && stdRecordsArray[i].score <= 100)
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
			case 'w': std::cout << "Which file do you want to save to?\n";
				std::cin >> FileName;
				foutput.open(FileName);
				foutput << NumStudents << endl;
				for (int i = 0; i < NumStudents; i++)
				{
					foutput << stdRecordsArray[i].firstName << endl;
					foutput << stdRecordsArray[i].lastName << endl;
					foutput << stdRecordsArray[i].score << endl;
				}
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
					finput >> stdRecordsArray[i].firstName;
					finput >> stdRecordsArray[i].lastName;
					finput >> stdRecordsArray[i].score;
					cout << "Student " << (i + 1) << ": " << stdRecordsArray[i].firstName << " " << stdRecordsArray[i].lastName << ": " << stdRecordsArray[i].score << endl;
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
				for (int i = 0; i < NumStudents; i++)//read file data
				{
					finput >> stdRecordsArray[i].firstName;
					finput >> stdRecordsArray[i].lastName;
					finput >> stdRecordsArray[i].score;
				}

				//average calculations
				for (int i = 0; i < NumStudents; i++)
				{
					sum = sum + stdRecordsArray[i].score;
				}
				average = sum / NumStudents;

				//highest and lowest calculations
				int x = 0; //stores score that is highest/lowest
				int highest, lowest;
				for (int i = 0; i < NumStudents; i++) //highest calculations
				{
					if (stdRecordsArray[x].score > stdRecordsArray[i].score)
						highest = stdRecordsArray[x].score;
					else
					{
						highest = stdRecordsArray[i].score;
						x = i;
					}
				}

				for (int i = 0; i < NumStudents; i++)
				{
					if (stdRecordsArray[i].score == highest)
						cout << stdRecordsArray[i].firstName << " " << stdRecordsArray[i].lastName << "\n";
				}
				//reset x
				x = 0;
				for (int i = 0; i < NumStudents; i++) //lowest calculations
				{
					if (stdRecordsArray[x].score < stdRecordsArray[i].score)
					{
						lowest = stdRecordsArray[x].score;
					}
					else
					{
						lowest = stdRecordsArray[i].score;
						x = i;
					}
				}

				//display of data
				cout << "The average of the scores is: " << average << endl;
				cout << "The highest score is: " << highest << endl;
				cout << "The students with the highest score are:\n";
				for (int i = 0; i < NumStudents; i++)//loop that displays students with the highest score
				{
					if (stdRecordsArray[i].score == highest)
						cout << stdRecordsArray[i].firstName << " " << stdRecordsArray[i].lastName << "\n";
				}
				cout << endl;
				cout << "The lowest score is: " << lowest << endl;
				cout << "The students with the lowest score are:\n";
				for (int i = 0; i < NumStudents; i++)//loop that displays students with the lowest score
				{
					if (stdRecordsArray[i].score == lowest)
						cout << stdRecordsArray[i].firstName << " " << stdRecordsArray[i].lastName << "\n";
				}
				cout << endl << endl;
			}
			break;
			case 'S'://sort by score
			case 's':
			{
				ScoreSort();
				std::cout << endl;
			}
				break;
			case 'N'://sort by name
			case 'n':
			{
				NameSort();
				std::cout << endl;
			}
				break;
			case 'M': //edit on specific score
			case 'm': int i;
				cout << "Which element do you want to edit?\n" << "Input an element from 0 to " << NumStudents - 1 << endl;
				cin >> i;
				cout << "Input new score value.\n";
				cin >> stdRecordsArray[i].score;
				cout << "\n" << "Changes complete\n" << "Remember to use option 'W' to save these changes.\n\n";
				break;
			default: cout << "invalid input\n\n";
			}
		}
	} while (options != 'Q' && options != 'q');
	char choice;
	cout << "Do you want to save before ending the program? (Y/N)\n";
	cin >> choice;

	if (choice == 'Y' || choice == 'y')
	{
		std::cout << "Which file do you want to save to?\n";
		std::cin >> FileName;
		foutput.open(FileName);
		foutput << NumStudents << endl;
		for (int i = 0; i < NumStudents; i++)
		{
			foutput << stdRecordsArray[i].firstName << endl;
			foutput << stdRecordsArray[i].lastName << endl;
			foutput << stdRecordsArray[i].score << endl;
		}
		foutput.close();
		cout << "Information saved\n\n";
	}
	else
		cout << "Information not saved\n\n";

	char end;
	cout << "\nEnd of program\n" << "Goodbye\n";
	cin >> end;
}
