#include "attendence.h"
#include <iostream>
#include <sstream>

using namespace std;

AttendanceRecord::AttendanceRecord() 
    : studentID(""), courseID(""), date(""), status('A') {}

AttendanceRecord::AttendanceRecord(string sid, string cid, string d, char s)
    : studentID(sid), courseID(cid), date(d), status(s) {}

void AttendanceRecord::display() {
    cout << "\nStudent ID: " << studentID
         << "\nCourse ID: " << courseID
         << "\nDate: " << date
         << "\nStatus: " << (status == 'P' ? "Present" : "Absent")
         << endl;
}

// Operator overloading for output stream
ostream& operator<<(ostream& os, AttendanceRecord& record) {
    os << record.studentID << " "
       << record.courseID << " "
       << record.date << " "
       << record.status;
    return os;
}

// Operator overloading for input stream
istream& operator>>(istream& is, AttendanceRecord& record) {
    is >> record.studentID >> record.courseID >> record.date >> record.status;
    return is;
}

// Operator overloading for equality comparison
bool AttendanceRecord::operator==(AttendanceRecord& other) {
    return (studentID == other.studentID && 
            courseID == other.courseID && 
            date == other.date);
}

// Operator overloading for less than comparison (for sorting by date)
bool AttendanceRecord::operator<(AttendanceRecord& other) {
    return date < other.date;
}