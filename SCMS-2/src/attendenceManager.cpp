#include "attendenceManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

extern Logger logger;

AttendanceManager::AttendanceManager() {
    loadAttendance();
}

AttendanceManager::~AttendanceManager() {
    saveAttendance();
}

void AttendanceManager::loadAttendance() {
    ifstream file(dataFile);
    if (!file) {
        logger.log("INFO", "ATTENDANCE", "No attendance file found, starting fresh");
        return;
    }
    
    AttendanceRecord record;
    while (file >> record) {
        records.push_back(record);
    }
    
    file.close();
    logger.log("INFO", "ATTENDANCE", "Loaded " + to_string(records.size()) + " attendance records");
}

void AttendanceManager::saveAttendance() {
    ofstream file(dataFile);
    if (!file) {
        logger.log("ERROR", "ATTENDANCE", "Cannot open attendance file for writing");
        return;
    }
    
    for (AttendanceRecord& record : records) {
        file << record << endl;
    }
    
    file.close();
}

void AttendanceManager::markAttendance() {
    try {
        string studentID, courseID, date;
        char status;
        
        cout << "\n=== MARK ATTENDANCE ===" << endl;
        cout << "Enter Student ID: ";
        cin >> studentID;
        cout << "Enter Course ID: ";
        cin >> courseID;
        cout << "Enter Date (YYYY-MM-DD): ";
        cin >> date;
        cout << "Enter Status (P for Present/A for Absent): ";
        cin >> status;
        
        status = toupper(status);
        if (status != 'P' && status != 'A') {
            throw runtime_error("Invalid status. Use P or A only");
        }
        
        // Check if record already exists
        for (int i = 0; i < records.size(); i++) {
            if (records[i].getStudentID() == studentID &&
                records[i].getCourseID() == courseID &&
                records[i].getDate() == date) {
                
                // Update existing record
                records[i].setStatus(status);
                saveAttendance();
                
                logger.log("INFO", "ATTENDANCE", "Updated attendance for student: " + studentID);
                cout << "\n✓ Attendance updated successfully!" << endl;
                return;
            }
        }
        
        // Add new record
        AttendanceRecord newRecord(studentID, courseID, date, status);
        records.push_back(newRecord);
        saveAttendance();
        
        logger.log("INFO", "ATTENDANCE", "Marked attendance for student: " + studentID);
        cout << "\n✓ Attendance marked successfully!" << endl;
        
    } catch (exception& e) {
        logger.log("ERROR", "ATTENDANCE", "Mark attendance failed: " + string(e.what()));
        cout << "\n✗ Error: " << e.what() << endl;
    }
}

void AttendanceManager::viewAttendance() {
    if (records.empty()) {
        cout << "\nNo attendance records available." << endl;
        return;
    }
    
    cout << "\n=== ALL ATTENDANCE RECORDS ===" << endl;
    cout << "Total records: " << records.size() << endl;
    
    for (AttendanceRecord& record : records) {
        record.display();
        cout << "------------------------" << endl;
    }
}

void AttendanceManager::viewStudentAttendance(string studentID) {
    cout << "\n=== ATTENDANCE FOR STUDENT: " << studentID << " ===" << endl;
    
    bool found = false;
    int presentCount = 0, totalCount = 0;
    
    for (AttendanceRecord& record : records) {
        if (record.getStudentID() == studentID) {
            found = true;
            totalCount++;
            if (record.getStatus() == 'P') presentCount++;
            record.display();
        }
    }
    
    if (!found) {
        cout << "No attendance records found for this student." << endl;
    } else {
        cout << "\nAttendance Summary:" << endl;
        cout << "Total Classes: " << totalCount << endl;
        cout << "Present: " << presentCount << endl;
        cout << "Absent: " << (totalCount - presentCount) << endl;
        cout << "Attendance Percentage: " 
             << (totalCount > 0 ? (presentCount * 100.0 / totalCount) : 0) 
             << "%" << endl;
    }
}

bool AttendanceManager::findRecord(string studentID, string courseID, string date) {
    // Using file seeking operations
    ifstream file(dataFile);
    if (!file) return false;
    
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string sid, cid, d;
        char status;
        
        ss >> sid >> cid >> d >> status;
        
        if (sid == studentID && cid == courseID && d == date) {
            file.close();
            return true;
        }
    }
    
    file.close();
    return false;
}

void AttendanceManager::updateRecord(string studentID, string courseID, string date, char status) {
    // Demonstration of seek operations
    fstream file(dataFile, ios::in | ios::out);
    if (!file) {
        logger.log("ERROR", "ATTENDANCE", "Cannot open file for update");
        return;
    }
    
    string line;
    long pos = 0;
    bool found = false;
    
    while (getline(file, line)) {
        stringstream ss(line);
        string sid, cid, d;
        char s;
        
        ss >> sid >> cid >> d >> s;
        
        if (sid == studentID && cid == courseID && d == date) {
            found = true;
            break;
        }
        pos = file.tellg();
    }
    
    if (found) {
        // Go back to the beginning of the line
        file.seekp(pos);
        
        // Write updated record
        AttendanceRecord updatedRecord(studentID, courseID, date, status);
        file << updatedRecord << endl;
        
        logger.log("INFO", "ATTENDANCE", "Updated record using seek operations");
        cout << "\n✓ Record updated using file seek operations!" << endl;
    }
    
    file.close();
}