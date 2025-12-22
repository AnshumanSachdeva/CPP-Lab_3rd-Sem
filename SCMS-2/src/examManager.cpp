#include "examManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

extern Logger logger;

// Constructor
ExamManager::ExamManager() {
    loadExams();
    loadMarks();
}

// Destructor
ExamManager::~ExamManager() {
    saveExams();
    saveMarks();
}

// Load exams from file
void ExamManager::loadExams() {
    ifstream file(examFile);
    if (!file) {
        logger.log("INFO", "EXAM", "No exam file found, starting fresh");
        return;
    }
    
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string eid, cid, date;
        int maxMarks;
        
        if (ss >> eid >> cid >> date >> maxMarks) {
            Exam exam(eid, cid, date, maxMarks);
            exams.push_back(exam);
        }
    }
    
    file.close();
    logger.log("INFO", "EXAM", "Loaded " + to_string(exams.size()) + " exams");
}

// Save exams to file
void ExamManager::saveExams() {
    ofstream file(examFile);
    if (!file) {
        logger.log("ERROR", "EXAM", "Cannot open exam file for writing");
        return;
    }
    
    for (Exam& exam : exams) {
        file << exam.getExamID() << " "
             << exam.getCourseID() << " "
             << exam.getDate() << " "
             << exam.getMaxMarks() << endl;
    }
    
    file.close();
}

// Load marks from file
void ExamManager::loadMarks() {
    ifstream file(marksFile);
    if (!file) {
        logger.log("INFO", "EXAM", "No marks file found, starting fresh");
        return;
    }
    
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string sid, eid;
        float marks;
        
        if (ss >> sid >> eid >> marks) {
            Marks mark(sid, eid, marks);
            marksList.push_back(mark);
        }
    }
    
    file.close();
    logger.log("INFO", "EXAM", "Loaded " + to_string(marksList.size()) + " marks records");
}

// Save marks to file
void ExamManager::saveMarks() {
    ofstream file(marksFile);
    if (!file) {
        logger.log("ERROR", "EXAM", "Cannot open marks file for writing");
        return;
    }
    
    for (Marks& mark : marksList) {
        file << mark.getStudentID() << " "
             << mark.getExamID() << " "
             << mark.getMarksObtained() << endl;
    }
    
    file.close();
}

// Add a new exam
void ExamManager::addExam() {
    try {
        string examID, courseID, date;
        int maxMarks;
        
        cout << "\n=== ADD NEW EXAM ===" << endl;
        cout << "Enter Exam ID: ";
        cin >> examID;
        cout << "Enter Course ID: ";
        cin >> courseID;
        cout << "Enter Date (YYYY-MM-DD): ";
        cin >> date;
        cout << "Enter Maximum Marks: ";
        cin >> maxMarks;
        
        if (maxMarks <= 0) {
            throw runtime_error("Maximum marks must be positive");
        }
        
        // Check if exam already exists
        for (Exam& exam : exams) {
            if (exam.getExamID() == examID) {
                throw runtime_error("Exam ID already exists");
            }
        }
        
        Exam newExam(examID, courseID, date, maxMarks);
        exams.push_back(newExam);
        saveExams();
        
        logger.log("INFO", "EXAM", "Exam added: " + examID);
        cout << "\n✓ Exam added successfully!" << endl;
        
    } catch (exception& e) {
        logger.log("ERROR", "EXAM", "Add exam failed: " + string(e.what()));
        cout << "\n✗ Error: " << e.what() << endl;
    }
}

// View all exams
void ExamManager::viewExams() {
    if (exams.empty()) {
        cout << "\nNo exams available." << endl;
        return;
    }
    
    cout << "\n=== ALL EXAMS ===" << endl;
    for (int i = 0; i < exams.size(); i++) {
        exams[i].display();
        cout << "-------------------" << endl;
    }
    cout << "Total exams: " << exams.size() << endl;
}

// Enter marks for a student
void ExamManager::enterMarks() {
    try {
        string studentID, examID;
        float marks;
        
        cout << "\n=== ENTER MARKS ===" << endl;
        cout << "Enter Student ID: ";
        cin >> studentID;
        cout << "Enter Exam ID: ";
        cin >> examID;
        cout << "Enter Marks Obtained: ";
        cin >> marks;
        
        if (marks < 0) {
            throw runtime_error("Marks cannot be negative");
        }
        
        // Check if marks already exist for this student and exam
        for (int i = 0; i < marksList.size(); i++) {
            if (marksList[i].getStudentID() == studentID &&
                marksList[i].getExamID() == examID) {
                
                marksList[i].setMarksObtained(marks);
                saveMarks();
                
                logger.log("INFO", "EXAM", "Updated marks for student: " + studentID);
                cout << "\n✓ Marks updated successfully!" << endl;
                return;
            }
        }
        
        // Add new marks
        Marks newMarks(studentID, examID, marks);
        marksList.push_back(newMarks);
        saveMarks();
        
        logger.log("INFO", "EXAM", "Entered marks for student: " + studentID);
        cout << "\n✓ Marks entered successfully!" << endl;
        
    } catch (exception& e) {
        logger.log("ERROR", "EXAM", "Enter marks failed: " + string(e.what()));
        cout << "\n✗ Error: " << e.what() << endl;
    }
}

// View all marks
void ExamManager::viewMarks() {
    if (marksList.empty()) {
        cout << "\nNo marks records available." << endl;
        return;
    }
    
    cout << "\n=== ALL MARKS RECORDS ===" << endl;
    for (int i = 0; i < marksList.size(); i++) {
        marksList[i].display();
        cout << "-------------------" << endl;
    }
    cout << "Total records: " << marksList.size() << endl;
}

// View marks for a specific student
void ExamManager::viewStudentMarks(string studentID) {
    cout << "\n=== MARKS FOR STUDENT: " << studentID << " ===" << endl;
    
    bool found = false;
    float total = 0;
    int count = 0;
    
    for (int i = 0; i < marksList.size(); i++) {
        if (marksList[i].getStudentID() == studentID) {
            found = true;
            marksList[i].display();
            total += marksList[i].getMarksObtained();
            count++;
        }
    }
    
    if (!found) {
        cout << "No marks found for this student." << endl;
    } else {
        cout << "\nTotal Exams: " << count << endl;
        cout << "Average Marks: " << (count > 0 ? total / count : 0) << endl;
    }
}

// View marks for a specific exam
void ExamManager::viewExamMarks(string examID) {
    cout << "\n=== MARKS FOR EXAM: " << examID << " ===" << endl;
    
    bool found = false;
    float total = 0;
    int count = 0;
    
    for (int i = 0; i < marksList.size(); i++) {
        if (marksList[i].getExamID() == examID) {
            found = true;
            marksList[i].display();
            total += marksList[i].getMarksObtained();
            count++;
        }
    }
    
    if (!found) {
        cout << "No marks found for this exam." << endl;
    } else {
        cout << "\nTotal Students: " << count << endl;
        cout << "Average Marks: " << (count > 0 ? total / count : 0) << endl;
    }
}

// Calculate average marks for a student
float ExamManager::calculateStudentAverage(string studentID) {
    float total = 0;
    int count = 0;
    
    for (int i = 0; i < marksList.size(); i++) {
        if (marksList[i].getStudentID() == studentID) {
            total += marksList[i].getMarksObtained();
            count++;
        }
    }
    
    return count > 0 ? total / count : 0;
}

// Calculate average marks for an exam
float ExamManager::calculateExamAverage(string examID) {
    float total = 0;
    int count = 0;
    
    for (int i = 0; i < marksList.size(); i++) {
        if (marksList[i].getExamID() == examID) {
            total += marksList[i].getMarksObtained();
            count++;
        }
    }
    
    return count > 0 ? total / count : 0;
}

// Sort students by marks using operator overloading
void ExamManager::sortStudentsByMarks() {
    if (marksList.empty()) {
        cout << "\nNo marks records to sort." << endl;
        return;
    }
    
    // Create a copy for sorting
    vector<Marks> sortedMarks = marksList;
    
    // Sort using operator overloading (Marks::operator<)
    for (int i = 0; i < sortedMarks.size() - 1; i++) {
        for (int j = 0; j < sortedMarks.size() - i - 1; j++) {
            if (sortedMarks[j + 1] < sortedMarks[j]) {
                // Swap
                Marks temp = sortedMarks[j];
                sortedMarks[j] = sortedMarks[j + 1];
                sortedMarks[j + 1] = temp;
            }
        }
    }
    
    cout << "\n=== STUDENTS SORTED BY MARKS (Ascending) ===" << endl;
    for (int i = 0; i < sortedMarks.size(); i++) {
        sortedMarks[i].display();
        cout << "-------------------" << endl;
    }
    
    logger.log("INFO", "EXAM", "Sorted students by marks using operator overloading");
}

// Generate marks report using template
void ExamManager::generateMarksReport() {
    if (marksList.empty()) {
        cout << "\nNo marks data for report." << endl;
        return;
    }
    
    ReportGenerator<Marks> report;
    
    for (int i = 0; i < marksList.size(); i++) {
        report.addData(marksList[i]);
    }
    
    cout << "\n=== MARKS REPORT ===" << endl;
    report.generateReport();
}

// Generate exam report using template
void ExamManager::generateExamReport() {
    if (exams.empty()) {
        cout << "\nNo exam data for report." << endl;
        return;
    }
    
    ReportGenerator<Exam> report;
    
    for (int i = 0; i < exams.size(); i++) {
        report.addData(exams[i]);
    }
    
    cout << "\n=== EXAM REPORT ===" << endl;
    report.generateReport();
}