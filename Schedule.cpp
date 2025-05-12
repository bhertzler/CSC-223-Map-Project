// Schedule.cpp: Implementation file for Schedule class
//

// Benjamin Hertzler
// CSC 223
// Map Project
//


#include "Schedule.h"
#include "ScheduleItem.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <map>
using namespace std;

#define HEADER "Subject  Catalog  Section  Component  Session  Units  TotEnrl  CapEnrl  Instructor"

void Schedule::initSchedule(ifstream& inFile)
{
	string line;
	vector<string> headers;
	bool inQuotes = false;
	
	if (inFile.is_open())
	{
		getline(inFile, line);

		while (getline(inFile, line))
		{
			stringstream ss(line);
			string token;
			vector<string> fields;
			char ch;

			while (ss.get(ch))
			{
				if (ch == '"')
					inQuotes = !inQuotes;
				else if (ch == ',' && !inQuotes)
				{
					fields.push_back(token);
					token.clear();
				}
				else
					token += ch;
			}

			if (!token.empty())
				fields.push_back(token);

			ScheduleItem new_entry(fields[0], fields[1], fields[2], fields[3], fields[4], stoi(fields[5]), stoi(fields[6]), stoi(fields[7]), fields[8]);
			addEntry(new_entry);
		}
	}
}

void Schedule::addEntry(const ScheduleItem& item)
{
	string key = item.getKey();
	pair<string, ScheduleItem> entry(key, item);
	scheduleMap.insert(entry);
}

void Schedule::print()
{
	map<string, ScheduleItem>::const_iterator it;
	for (auto it = scheduleMap.begin(); it != scheduleMap.end(); ++it)
	{
		it->second.print();
		cout << endl;
	}
}

void Schedule::printHeader()
{
	cout << HEADER << endl;
}


void Schedule::findBySubject(string subject)
{
	map<string, ScheduleItem>::const_iterator it;
	for (auto it = scheduleMap.begin(); it != scheduleMap.end(); ++it)
	{
		SchedType item = it->second.getScheduleItem();
		if (item.subject == subject)
		{
			it->second.print();
			cout << endl;
		}
	}
}

void Schedule::findBySubjectCatalog(string subject, string catalog)
{
	map<string, ScheduleItem>::const_iterator it;
	for (auto it = scheduleMap.begin(); it != scheduleMap.end(); ++it)
	{
		SchedType item = it->second.getScheduleItem();
		if (item.subject == subject && item.catalog == catalog)
		{
			it->second.print();
			cout << endl;
		}
	}
}

void Schedule::findByInstructorLastName(string lastName)
{
	map<string, ScheduleItem>::const_iterator it;
	for (auto it = scheduleMap.begin(); it != scheduleMap.end(); ++it)
	{
		SchedType item = it->second.getScheduleItem();
		string prof;
		int pos = item.instructor.find(",", 0);
		prof = item.instructor.substr(0, pos);
		if (prof == lastName)
		{
			it->second.print();
			cout << endl;
		}
	}
}
