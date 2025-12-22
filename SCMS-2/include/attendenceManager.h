#ifndef ATTENDENCEMANAGER_H
#define ATTENDENCEMANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "attendence.h"
#include "logger.h"

using namespace std;

extern Logger logger;

class AttendanceManager {
private:
    vector<AttendanceRecord> records;
    string dataFile = "../data/attendance.txt";
    
    void loadAttendance();
    void saveAttendance();
    
public:
    AttendanceManager();
    ~AttendanceManager();
    
    void markAttendance();
    void viewAttendance();
    void viewStudentAttendance(string studentID);
    void viewCourseAttendance(string courseID, string date);
    void getAttendanceByDateRange(string startDate, string endDate);
    
    // File handling with seek operations
    bool findRecord(string studentID, string courseID, string date);
    void updateRecord(string studentID, string courseID, string date, char status);
};

#endif