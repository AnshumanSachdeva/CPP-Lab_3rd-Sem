#ifndef EXAMMANAGER_H
#define EXAMMANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "exam.h"
#include "marks.h"
#include "logger.h"

using namespace std;

extern Logger logger;

// Template class for report generation
template <typename T>
class ReportGenerator {
private:
    vector<T> data;
    
public:
    void addData(T item) {
        data.push_back(item);
    }
    
    void generateReport() {
        cout << "\n=== REPORT ===" << endl;
        for (int i = 0; i < data.size(); i++) {
            data[i].display();
        }
        cout << "Total records: " << data.size() << endl;
    }
    
    void clear() {
        data.clear();
    }
};

class ExamManager {
private:
    vector<Exam> exams;
    vector<Marks> marksList;
    string examFile = "../data/exams.txt";
    string marksFile = "../data/marks.txt";
    
    void loadExams();
    void saveExams();
    void loadMarks();
    void saveMarks();
    
public:
    ExamManager();
    ~ExamManager();
    
    // Exam operations
    void addExam();
    void viewExams();
    
    // Marks operations
    void enterMarks();
    void viewMarks();
    void viewStudentMarks(string studentID);
    void viewExamMarks(string examID);
    
    // Result computation
    float calculateStudentAverage(string studentID);
    float calculateExamAverage(string examID);
    
    // Report generation using template
    void generateMarksReport();
    void generateExamReport();
    
    // Sorting using operator overloading
    void sortStudentsByMarks();
};

#endif