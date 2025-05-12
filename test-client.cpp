// test-client.cpp: This file contains the 'main' function.
//

// Benjamin Hertzler
// CSC 223
// Map Project
//


#include "Schedule.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

#define FILE_NAME "STEM - Summer 2022 Schedule of Classes as of 05-02-22.csv"

// Function to display an interactable menu.
// Precondition: User must enter an option by entering an int between 1 and 5.
// Postcondition: Option 1 - Search by subject code.
//		Option 2 - Search by subject code and catalog id.
//		Option 3 - Search by last name of instructor.
//		Option 4 - Display all entries
//		Option 5 - Quit
//
void showMenu();

int main()
{
	Schedule semester(179);
	int choice;
	string targ_1, targ_2;

	ifstream inFile;
	inFile.open(FILE_NAME);
	if (!inFile)
	{
		cerr << "Invalid File" << endl;
		return -1;
	}

	semester.initSchedule(inFile);
	inFile.close();

	do
	{
		showMenu();
		cin >> choice;
		switch (choice)
		{
        case 1:
            cout << "Enter the 3 character subject code to find: ";
            cin >> targ_1;
			semester.printHeader();
            semester.findBySubject(targ_1);
            break;
        case 2:
            cout << "Enter the 3 character subject code and catalog number to find: ";
            cin >> targ_1 >> targ_2;
			semester.printHeader();
            semester.findBySubjectCatalog(targ_1, targ_2);
            break;
        case 3:
            cout << "Enter the last name of the instructor to find: ";
            cin >> targ_1;
			semester.printHeader();
            semester.findByInstructorLastName(targ_1);
            break;
        case 4:
			semester.printHeader();
			semester.print();
			break;
		case 5:
			break;
        default:
            cout << "Invalid choice, try again." << endl;
		}
	} while (choice != 5);
	
	return 0;
}

void showMenu()
{
	cout << endl;
	cout << "Select one of the following actions: " << endl;
	cout << "1 - Search by subject" << endl;
	cout << "2 - Search by subject and catalog id" << endl;
	cout << "3 - Search by instructor" << endl;
	cout << "4 - Print all entries." << endl;
	cout << "5 - Quit." << endl;
	cout << endl;
}