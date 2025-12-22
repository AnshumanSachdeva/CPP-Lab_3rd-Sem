#ifndef MARKS_H
#define MARKS_H

#include <iostream>
#include <string>
using namespace std;

class Marks {
private:
    string studentID;
    string examID;
    float marksObtained;
    
public:
    Marks();
    Marks(string sid, string eid, float marks);
    
    // Getters
    string getStudentID() { return studentID; }
    string getExamID() { return examID; }
    float getMarksObtained() { return marksObtained; }
    
    // Setters
    void setStudentID(string sid) { studentID = sid; }
    void setExamID(string eid) { examID = eid; }
    void setMarksObtained(float m) { marksObtained = m; }
    
    // Operator overloading for sorting
    bool operator<(Marks& other);
    
    void display();
};

#endif