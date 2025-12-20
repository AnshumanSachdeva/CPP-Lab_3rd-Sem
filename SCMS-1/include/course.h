#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
using namespace std;

class Course {
private:
    string courseID;
    string title;
    int credits;
    int capacity;
    int enrolledCount;
    
public:
    // Constructors
    Course();
    Course(string id, string t, int c, int cap);
    
    // Getters
    string getCourseID() { return courseID; }
    string getTitle() { return title; }
    int getCredits() { return credits; }
    int getCapacity() { return capacity; }
    int getEnrolledCount() { return enrolledCount; }
    
    // Setters
    void setTitle(string t) { title = t; }
    void setCredits(int c) { credits = c; }
    void setCapacity(int cap) { capacity = cap; }
    
    // Functions
    bool enrollStudent();
    bool dropStudent();
    bool isFull() { return enrolledCount >= capacity; }
    void printCourse();
    
    // File operations
    void saveToFile(ofstream& file);
    void loadFromFile(ifstream& file);
};

#endif