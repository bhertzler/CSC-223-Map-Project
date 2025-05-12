// Schedule.h: Header file for Schedule class
//

// Benjamin Hertzler
// CSC 223
// Map Project
//

#pragma once

#include "ScheduleItem.h"
#include <string>
#include <fstream>
#include <utility>
#include <map>

// Manages a collection of ScheduleItem objects using a std::map with keys in the form Subject_Catalog_Section.
class Schedule
{
public:
	// Default Constructor
	// Precondition: size is the total number of lines in the file.
	// Postcondition: initializes the scheduleMap.
	//
	Schedule(size_t size) /*: scheduleMap(size)*/ {}

	// Reads data from a CSV file and populates the map with ScheduleItem objects.
	// Precondition: inFile must be open and valid.
	//		File must follow the expected format.
	// Postcondition: Header line is skipped.
	//		All valid rows are read and added to the map via addEntry().
	//
	void initSchedule(std::ifstream& inFile);

	// Inserts a ScheduleItem into the map using its key.
	// Precondition: The ScheduleItem must have valid data.
	// Postcondition: A new entry is added to the scheduleMap or replaces an existing one with the same key.
	//
	void addEntry(const ScheduleItem& item);

	// Prints all entries in the map in order.
	// Precondition: initSchedule must have been called (or entries manually added).
	// Postcondition: All entries are displayed using the ScheduleItem::print() function.
	//
	void print();

	// Prints the column headers for the report.
	// Precondition: None.
	// Postcondition: Displays the column headers on the screen.
	//
	void printHeader();

	// Prints all schedule items matching the given subject.
	// Precondition: The subject string must not be empty.
	// Postcondition: All matching items are displayed.
	//
	void findBySubject(std::string subject);

	// Prints all schedule items matching both subject and catalog number.
	// Precondition: Subject and catalog strings must not be empty.
	// Postcondition: All matching items are displayed.
	//
	void findBySubjectCatalog(std::string subject, std::string catalog);

	// Prints all schedule items where the instructor's last name matches the given string.
	// Precondition: Last name string must not be empty.
	// Postcondition: All matching items are displayed.
	//
	void findByInstructorLastName(std::string lastName);

private:
	std::map<std::string, ScheduleItem> scheduleMap;	// Map of schedule items with keys in the form Subject_Catalog_Section.
};

