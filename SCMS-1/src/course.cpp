#include "course.h"
#include <iostream>
#include<fstream>
#include <sstream>

using namespace std;

Course::Course() : courseID(""), title(""), credits(0), capacity(0), enrolledCount(0) {}

Course::Course(string id, string t, int c, int cap) 
    : courseID(id), title(t), credits(c), capacity(cap), enrolledCount(0) {}

bool Course::enrollStudent() {
    if (isFull()) {
        return false;
    }
    enrolledCount++;
    return true;
}

bool Course::dropStudent() {
    if (enrolledCount > 0) {
        enrolledCount--;
        return true;
    }
    return false;
}

void Course::printCourse() {
    cout << "\nCourse ID: " << courseID
         << "\nTitle: " << title
         << "\nCredits: " << credits
         << "\nCapacity: " << capacity
         << "\nEnrolled: " << enrolledCount
         << "\nAvailable: " << (capacity - enrolledCount)
         << endl;
}

void Course::saveToFile(ofstream& file) {
    file << courseID << " "
         << title << " "
         << credits << " "
         << capacity << " "
         << enrolledCount << endl;
}

void Course::loadFromFile(ifstream& file) {
    file >> courseID;
    
    // Read title (may contain spaces)
    file.ignore();
    getline(file, title);
    
    file >> credits >> capacity >> enrolledCount;
}