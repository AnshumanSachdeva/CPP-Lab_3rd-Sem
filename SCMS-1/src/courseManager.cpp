#include "courseManager.h"
#include <iostream>
#include <sstream>

using namespace std;

extern Logger logger;

CourseManager::CourseManager() {
    loadCourses();
}

CourseManager::~CourseManager() {
    saveCourses();
}

void CourseManager::loadCourses() {
    ifstream file(dataFile);
    if (!file) {
        logger.log("INFO", "COURSE", "No existing course file found, starting fresh");
        return;
    }
    
    Course course;
    while (file.peek() != EOF) {
        course.loadFromFile(file);
        courses.push_back(course);
    }
    
    file.close();
    logger.log("INFO", "COURSE", "Loaded " + to_string(courses.size()) + " courses from file");
}

void CourseManager::saveCourses() {
    ofstream file(dataFile);
    if (!file) {
        logger.log("ERROR", "COURSE", "Cannot open course file for writing");
        return;
    }
    
    for (Course& course : courses) {
        course.saveToFile(file);
    }
    
    file.close();
    logger.log("INFO", "COURSE", "Saved " + to_string(courses.size()) + " courses to file");
}

void CourseManager::addCourse() {
    try {
        string id, title;
        int credits, capacity;
        
        cout << "\n=== ADD NEW COURSE ===\n";
        cout << "Enter Course ID: ";
        cin >> id;
        
        // Check if course already exists
        for (Course& course : courses) {
            if (course.getCourseID() == id) {
                throw runtime_error("Course ID already exists");
            }
        }
        
        cout << "Enter Course Title: ";
        cin.ignore();
        getline(cin, title);
        
        cout << "Enter Credits: ";
        cin >> credits;
        
        if (credits <= 0) {
            throw runtime_error("Credits must be positive");
        }
        
        cout << "Enter Capacity: ";
        cin >> capacity;
        
        if (capacity <= 0) {
            throw runtime_error("Capacity must be positive");
        }
        
        Course newCourse(id, title, credits, capacity);
        courses.push_back(newCourse);
        
        saveCourses();
        
        logger.log("INFO", "COURSE", "Course added: " + id + " - " + title);
        cout << "\n✓ Course added successfully!\n";
        
    } catch (exception& e) {
        logger.log("ERROR", "COURSE", "Add course failed: " + string(e.what()));
        cout << "\n✗ Error: " << e.what() << endl;
    }
}

void CourseManager::updateCourse() {
    string id;
    cout << "\nEnter Course ID to update: ";
    cin >> id;
    
    Course* course = findCourse(id);
    if (!course) {
        cout << "\n✗ Course not found.\n";
        return;
    }
    
    try {
        int choice;
        cout << "\n=== UPDATE COURSE ===\n";
        cout << "What do you want to update?\n";
        cout << "1. Title\n2. Credits\n3. Capacity\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                string newTitle;
                cout << "Enter new title: ";
                cin.ignore();
                getline(cin, newTitle);
                course->setTitle(newTitle);
                break;
            }
            case 2: {
                int newCredits;
                cout << "Enter new credits: ";
                cin >> newCredits;
                if (newCredits <= 0) throw runtime_error("Credits must be positive");
                course->setCredits(newCredits);
                break;
            }
            case 3: {
                int newCapacity;
                cout << "Enter new capacity: ";
                cin >> newCapacity;
                if (newCapacity <= 0) throw runtime_error("Capacity must be positive");
                course->setCapacity(newCapacity);
                break;
            }
            default:
                cout << "\nInvalid choice.\n";
                return;
        }
        
        saveCourses();
        logger.log("INFO", "COURSE", "Course updated: " + id);
        cout << "\n✓ Course updated successfully!\n";
        
    } catch (exception& e) {
        logger.log("ERROR", "COURSE", "Update course failed: " + string(e.what()));
        cout << "\n✗ Error: " << e.what() << endl;
    }
}

void CourseManager::deleteCourse() {
    string id;
    cout << "\nEnter Course ID to delete: ";
    cin >> id;
    
    for (vector<Course>::iterator it = courses.begin(); it != courses.end(); ++it) {
        if (it->getCourseID() == id) {
            courses.erase(it);
            saveCourses();
            logger.log("INFO", "COURSE", "Course deleted: " + id);
            cout << "\n✓ Course deleted successfully.\n";
            return;
        }
    }
    
    logger.log("WARNING", "COURSE", "Delete course failed - not found: " + id);
    cout << "\n✗ Course not found.\n";
}

bool CourseManager::enrollStudent(string courseID, int studentID) {
    Course* course = findCourse(courseID);
    if (!course) {
        logger.log("WARNING", "COURSE", "Enrollment failed - course not found: " + courseID);
        return false;
    }
    
    if (course->enrollStudent()) {
        saveCourses();
        logger.log("INFO", "COURSE", "Student " + to_string(studentID) + " enrolled in " + courseID);
        return true;
    }
    
    logger.log("WARNING", "COURSE", "Enrollment failed - course full: " + courseID);
    return false;
}

bool CourseManager::dropStudent(string courseID, int studentID) {
    Course* course = findCourse(courseID);
    if (!course) {
        return false;
    }
    
    if (course->dropStudent()) {
        saveCourses();
        logger.log("INFO", "COURSE", "Student " + to_string(studentID) + " dropped from " + courseID);
        return true;
    }
    
    return false;
}

void CourseManager::viewAllCourses() {
    if (courses.empty()) {
        cout << "\nNo courses available.\n";
        return;
    }
    
    cout << "\n=== AVAILABLE COURSES ===\n";
    for (Course& course : courses) {
        course.printCourse();
        cout << "------------------------" << endl;
    }
    cout << "Total: " << courses.size() << " courses\n";
}

Course* CourseManager::findCourse(string courseID) {
    for (Course& course : courses) {
        if (course.getCourseID() == courseID) {
            return &course;
        }
    }
    return nullptr;
}