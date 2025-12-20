#ifndef COURSEMANAGER_H
#define COURSEMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include "course.h"
#include "logger.h"

using namespace std;

extern Logger logger;

class CourseManager {
private:
    vector<Course> courses;
    string dataFile = "../data/courses.txt";
    
    void loadCourses();
    void saveCourses();
    
public:
    CourseManager();
    ~CourseManager();
    
    void addCourse();
    void updateCourse();
    void deleteCourse();
    bool enrollStudent(string courseID, int studentID);
    bool dropStudent(string courseID, int studentID);
    void viewAllCourses();
    Course* findCourse(string courseID);
    
    // For admin operations
    vector<Course>& getCourses() { return courses; }
};

#endif