#include "marks.h"
#include <iostream>

using namespace std;

Marks::Marks() : studentID(""), examID(""), marksObtained(0.0) {}

Marks::Marks(string sid, string eid, float marks)
    : studentID(sid), examID(eid), marksObtained(marks) {}

void Marks::display() {
    cout << "\nStudent ID: " << studentID
         << "\nExam ID: " << examID
         << "\nMarks Obtained: " << marksObtained
         << endl;
}

bool Marks::operator<(Marks& other) {
    return marksObtained < other.marksObtained;
}