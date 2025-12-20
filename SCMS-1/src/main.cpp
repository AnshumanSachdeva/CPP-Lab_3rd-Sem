#include <iostream>
#include <vector>
#include "logger.h"
#include "authManager.h"
#include "courseManager.h"
#include "person.h"
#include "student.h"
#include "teacher.h"
#include "admin.h"

using namespace std;

// Global objects
Logger logger;
AuthManager authManager;
CourseManager courseManager;

// Function prototypes
void displayMainMenu();
void displayAdminMenu();
void displayStudentMenu();
void displayTeacherMenu();
void handleAdminOperations();
void handleStudentOperations();
void handleTeacherOperations();
void testPolymorphism();

int main() {
    logger.init();
    logger.log("INFO", "SYSTEM", "SCMS System Started");
    
    cout << "\n========================================";
    cout << "\n  SMART CAMPUS MANAGEMENT SYSTEM (SCMS)";
    cout << "\n========================================";
    
    int choice;
    
    while (true) {
        displayMainMenu();
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: // Login
                logger.log("INFO", "SYSTEM", "Login option selected");
                if (authManager.login()) {
                    // Redirect based on role
                    string role = authManager.getCurrentRole();
                    if (role == "admin") {
                        handleAdminOperations();
                    } else if (role == "student") {
                        handleStudentOperations();
                    } else if (role == "teacher") {
                        handleTeacherOperations();
                    }
                }
                break;
                
            case 2: // Register
                logger.log("INFO", "SYSTEM", "Register option selected");
                authManager.registerUser();
                break;
                
            case 3: // Test Polymorphism
                logger.log("INFO", "SYSTEM", "Testing polymorphism");
                testPolymorphism();
                break;
                
            case 4: // View Courses (without login)
                logger.log("INFO", "SYSTEM", "View courses selected");
                courseManager.viewAllCourses();
                break;
                
            case 5: // Exit
                logger.log("INFO", "SYSTEM", "System shutdown requested");
                cout << "\nThank you for using SCMS!\n";
                logger.close();
                return 0;
                
            default:
                cout << "\nInvalid choice. Please try again.\n";
                logger.log("WARNING", "SYSTEM", "Invalid menu choice: " + to_string(choice));
        }
    }
    
    logger.close();
    return 0;
}

void displayMainMenu() {
    cout << "\n\n=== MAIN MENU ===";
    cout << "\n1. Login";
    cout << "\n2. Register";
    cout << "\n3. Test Polymorphism (Demo)";
    cout << "\n4. View Courses";
    cout << "\n5. Exit";
    cout << "\n=================";
}

void displayAdminMenu() {
    cout << "\n\n=== ADMIN MENU ===";
    cout << "\n1. Manage Courses";
    cout << "\n2. Manage Users";
    cout << "\n3. View All Courses";
    cout << "\n4. Change Password";
    cout << "\n5. Logout";
    cout << "\n==================";
}

void displayStudentMenu() {
    cout << "\n\n=== STUDENT MENU ===";
    cout << "\n1. View Available Courses";
    cout << "\n2. Enroll in Course";
    cout << "\n3. Drop Course";
    cout << "\n4. Change Password";
    cout << "\n5. Logout";
    cout << "\n====================";
}

void displayTeacherMenu() {
    cout << "\n\n=== TEACHER MENU ===";
    cout << "\n1. View Courses";
    cout << "\n2. Change Password";
    cout << "\n3. Logout";
    cout << "\n===================";
}

void handleAdminOperations() {
    int choice;
    
    while (authManager.isLoggedIn() && authManager.getCurrentRole() == "admin") {
        displayAdminMenu();
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: // Manage Courses
                {
                    int courseChoice;
                    cout << "\n=== COURSE MANAGEMENT ===";
                    cout << "\n1. Add Course";
                    cout << "\n2. Update Course";
                    cout << "\n3. Delete Course";
                    cout << "\n4. Back";
                    cout << "\nEnter choice: ";
                    cin >> courseChoice;
                    
                    switch (courseChoice) {
                        case 1:
                            courseManager.addCourse();
                            break;
                        case 2:
                            courseManager.updateCourse();
                            break;
                        case 3:
                            courseManager.deleteCourse();
                            break;
                        case 4:
                            break;
                        default:
                            cout << "\nInvalid choice.\n";
                    }
                }
                break;
                
            case 2: // Manage Users
                {
                    int userChoice;
                    cout << "\n=== USER MANAGEMENT ===";
                    cout << "\n1. Remove User";
                    cout << "\n2. Back";
                    cout << "\nEnter choice: ";
                    cin >> userChoice;
                    
                    if (userChoice == 1) {
                        authManager.removeUser();
                    }
                }
                break;
                
            case 3: // View All Courses
                courseManager.viewAllCourses();
                break;
                
            case 4: // Change Password
                authManager.changePassword();
                break;
                
            case 5: // Logout
                authManager.logout();
                return;
                
            default:
                cout << "\nInvalid choice.\n";
        }
    }
}

void handleStudentOperations() {
    int choice;
    
    while (authManager.isLoggedIn() && authManager.getCurrentRole() == "student") {
        displayStudentMenu();
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: // View Courses
                courseManager.viewAllCourses();
                break;
                
            case 2: // Enroll in Course
                {
                    string courseID;
                    cout << "\nEnter Course ID to enroll: ";
                    cin >> courseID;
                    
                    // For demo, using a dummy student ID
                    int studentID = 1001; // In real system, get from logged in user
                    
                    if (courseManager.enrollStudent(courseID, studentID)) {
                        cout << "\n✓ Successfully enrolled in course!\n";
                    } else {
                        cout << "\n✗ Enrollment failed. Course may be full or not found.\n";
                    }
                }
                break;
                
            case 3: // Drop Course
                {
                    string courseID;
                    cout << "\nEnter Course ID to drop: ";
                    cin >> courseID;
                    
                    int studentID = 1001; // In real system, get from logged in user
                    
                    if (courseManager.dropStudent(courseID, studentID)) {
                        cout << "\n✓ Successfully dropped from course!\n";
                    } else {
                        cout << "\n✗ Failed to drop from course.\n";
                    }
                }
                break;
                
            case 4: // Change Password
                authManager.changePassword();
                break;
                
            case 5: // Logout
                authManager.logout();
                return;
                
            default:
                cout << "\nInvalid choice.\n";
        }
    }
}

void handleTeacherOperations() {
    int choice;
    
    while (authManager.isLoggedIn() && authManager.getCurrentRole() == "teacher") {
        displayTeacherMenu();
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: // View Courses
                courseManager.viewAllCourses();
                break;
                
            case 2: // Change Password
                authManager.changePassword();
                break;
                
            case 3: // Logout
                authManager.logout();
                return;
                
            default:
                cout << "\nInvalid choice.\n";
        }
    }
}

void testPolymorphism() {
    cout << "\n=== POLYMORPHISM DEMONSTRATION ===\n";
    
    // Create objects using base class pointers
    vector<Person*> people;
    
    // Create different types of people
    people.push_back(new Student("Alice Johnson", 1001, 20));
    people.push_back(new Teacher("Dr. Smith", 2001, 45));
    people.push_back(new Admin("Mr. Wilson", 3001, 50));
    people.push_back(new Student("Bob Brown", 1002, 21));
    
    // Demonstrate polymorphism
    cout << "\nDisplaying profiles using polymorphism:\n";
    for (int i = 0; i < people.size(); i++) {
        people[i]->printProfile();
        cout << "-------------------\n";
    }
    
    // Cleanup - manually delete objects
    for (int i = 0; i < people.size(); i++) {
        delete people[i];
    }
    people.clear();
    
    cout << "\n✓ Polymorphism test completed successfully!\n";
}