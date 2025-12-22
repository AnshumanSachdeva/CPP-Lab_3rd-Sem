#ifndef ATTENDENCE_H
#define ATTENDENCE_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class AttendanceRecord {
private:
    string studentID;
    string courseID;
    string date;
    char status;  // 'P' for Present, 'A' for Absent
    
public:
    // Constructors
    AttendanceRecord();
    AttendanceRecord(string sid, string cid, string d, char s);
    
    // Getters
    string getStudentID() { return studentID; }
    string getCourseID() { return courseID; }
    string getDate() { return date; }
    char getStatus() { return status; }
    
    // Setters
    void setStudentID(string sid) { studentID = sid; }
    void setCourseID(string cid) { courseID = cid; }
    void setDate(string d) { date = d; }
    void setStatus(char s) { status = s; }
    
    // Operator overloading for stream I/O
    friend ostream& operator<<(ostream& os, AttendanceRecord& record);
    friend istream& operator>>(istream& is, AttendanceRecord& record);
    
    // Operator overloading for comparison
    bool operator==(AttendanceRecord& other);
    bool operator<(AttendanceRecord& other);
    
    // Display function
    void display();
};

#endif