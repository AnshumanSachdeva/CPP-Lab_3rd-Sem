#ifndef EXAM_H
#define EXAM_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Exam {
private:
    string examID;
    string courseID;
    string date;
    int maxMarks;
    
public:
    Exam();
    Exam(string eid, string cid, string d, int mm);
    
    // Getters
    string getExamID() { return examID; }
    string getCourseID() { return courseID; }
    string getDate() { return date; }
    int getMaxMarks() { return maxMarks; }
    
    // Setters
    void setExamID(string eid) { examID = eid; }
    void setCourseID(string cid) { courseID = cid; }
    void setDate(string d) { date = d; }
    void setMaxMarks(int mm) { maxMarks = mm; }
    
    void display();
};

#endif