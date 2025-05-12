// ScheduleItem.cpp: Implementation file for ScheduleItem class
//

// Benjamin Hertzler
// CSC 223
// Map Project
//

#include "ScheduleItem.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;


void ScheduleItem::print()
{
	cout << setw(3) << course.subject << setw(9) << course.catalog << setw(10) << course.section;
	cout << setw(10) << course.component << setw(11) << course.session;
	cout << setw(8) << course.units << setw(8) << course.totEnrl << setw(9) << course.capEnrl;
	cout << "     " << course.instructor;
}

bool ScheduleItem::operator==(const SchedType& q) const
{
	string p_str = course.subject + '_' + course.section + '_' + course.session;
	string q_str = q.subject + '_' + q.section + '_' + q.session;
	return (p_str == q_str);
}

bool ScheduleItem::operator!=(const SchedType& q) const
{
	string p_str = course.subject + '_' + course.section + '_' + course.session;
	string q_str = q.subject + '_' + q.section + '_' + q.session;
	return (p_str != q_str);
}

bool ScheduleItem::operator>=(const SchedType& q) const
{
	string p_str = course.subject + '_' + course.section + '_' + course.session;
	string q_str = q.subject + '_' + q.section + '_' + q.session;
	return (p_str >= q_str);
}