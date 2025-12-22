#include "exam.h"
#include <iostream>

using namespace std;

// Default constructor
Exam::Exam() : examID(""), courseID(""), date(""), maxMarks(0) {}

// Parameterized constructor
Exam::Exam(string eid, string cid, string d, int mm)
    : examID(eid), courseID(cid), date(d), maxMarks(mm) {}

// Display exam details
void Exam::display() {
    cout << "\nExam ID: " << examID
         << "\nCourse ID: " << courseID
         << "\nDate: " << date
         << "\nMaximum Marks: " << maxMarks
         << endl;
}