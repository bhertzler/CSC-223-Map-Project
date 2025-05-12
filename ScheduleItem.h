// ScheduleItem.h: Header file for ScheduleItem class
//

// Benjamin Hertzler
// CSC 223
// Map Project
//

#pragma once

#include <string>

struct SchedType
{
	std::string subject;
    std::string catalog;
    std::string section;
    std::string component;
    std::string session;
    int units;
    int totEnrl;
    int capEnrl;
    std::string instructor;

    SchedType(std::string sub = "", std::string cat = "", std::string sec = "", std::string com = "", std::string ses = "", int uni = 0, int totE = 0, int capE = 0, std::string ins = "")
        : subject(sub), catalog(cat), section(sec), component(com), session(ses), units(uni), totEnrl(totE), capEnrl(capE), instructor(ins) {}
};

class ScheduleItem
{
public:
    ScheduleItem() { course = SchedType(); }

    ScheduleItem(std::string sub, std::string cat, std::string sec, std::string com, std::string ses, int uni, int totE, int capE, std::string ins)
    {
        course = SchedType(sub, cat, sec, com, ses, uni, totE, capE, ins);
    }

    SchedType& getScheduleItem() { return course; }

    std::string getKey() const { return course.subject + '_' + course.catalog + '_' + course.section; }
    
    void print();

    bool operator==(const SchedType& q) const;
    bool operator!=(const SchedType& q) const;
    bool operator>=(const SchedType& q) const;

private:
    SchedType course;
};

