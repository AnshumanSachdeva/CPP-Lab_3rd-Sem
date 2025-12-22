#include <iostream>
#include <vector>
#include "logger.h"
#include "authManager.h"
#include "courseManager.h"
#include "attendenceManager.h"
#include "examManager.h"
#include "libraryManager.h"
#include "person.h"
#include "student.h"
#include "teacher.h"
#include "admin.h"

using namespace std;

// Global objects
Logger logger;
AuthManager authManager;
CourseManager courseManager;
AttendanceManager attendanceManager;
ExamManager examManager;
LibraryManager libraryManager;

// Function prototypes
void displayMainMenu();
void displayAdminMenu();
void displayStudentMenu();
void displayTeacherMenu();
void handleAdminOperations();
void handleStudentOperations();
void handleTeacherOperations();
void testPolymorphism();
void testAssignment2Features();

int main() {
    logger.init();
    logger.log("INFO", "SYSTEM", "SCMS System Started - Assignment 2");
    
    cout << "\n=========================================";
    cout << "\n  SMART CAMPUS MANAGEMENT SYSTEM (SCMS)";
    cout << "\n           ASSIGNMENT 2";
    cout << "\n=========================================";
    
    int choice;
    
    while (true) {
        displayMainMenu();
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: // Login
                logger.log("INFO", "SYSTEM", "Login option selected");
                if (authManager.login()) {
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
                
            case 4: // Test Assignment 2 Features
                logger.log("INFO", "SYSTEM", "Testing Assignment 2 features");
                testAssignment2Features();
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
    cout << "\n\n=== MAIN MENU (ASSIGNMENT 2) ===";
    cout << "\n1. Login";
    cout << "\n2. Register";
    cout << "\n3. Test Polymorphism (Demo)";
    cout << "\n4. Test Assignment 2 Features";
    cout << "\n5. Exit";
    cout << "\n===============================";
}

void displayAdminMenu() {
    cout << "\n\n=== ADMIN MENU ===";
    cout << "\n1. Course Management";
    cout << "\n2. User Management";
    cout << "\n3. Attendance Management";
    cout << "\n4. Exam Management";
    cout << "\n5. Library Management";
    cout << "\n6. View All Data";
    cout << "\n7. Change Password";
    cout << "\n8. Logout";
    cout << "\n==================";
}

void displayStudentMenu() {
    cout << "\n\n=== STUDENT MENU ===";
    cout << "\n1. View Courses";
    cout << "\n2. Enroll/Drop Courses";
    cout << "\n3. View Attendance";
    cout << "\n4. View Exam Marks";
    cout << "\n5. Library Services";
    cout << "\n6. Change Password";
    cout << "\n7. Logout";
    cout << "\n====================";
}

void displayTeacherMenu() {
    cout << "\n\n=== TEACHER MENU ===";
    cout << "\n1. View Courses";
    cout << "\n2. Mark Attendance";
    cout << "\n3. Enter Exam Marks";
    cout << "\n4. View Library";
    cout << "\n5. Change Password";
    cout << "\n6. Logout";
    cout << "\n===================";
}

void handleAdminOperations() {
    int choice;
    
    while (authManager.isLoggedIn() && authManager.getCurrentRole() == "admin") {
        displayAdminMenu();
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: // Course Management
                {
                    int courseChoice;
                    cout << "\n=== COURSE MANAGEMENT ===";
                    cout << "\n1. Add Course";
                    cout << "\n2. Update Course";
                    cout << "\n3. Delete Course";
                    cout << "\n4. View All Courses";
                    cout << "\n5. Back";
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
                            courseManager.viewAllCourses();
                            break;
                        case 5:
                            break;
                        default:
                            cout << "\nInvalid choice.\n";
                    }
                }
                break;
                
            case 2: // User Management
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
                
            case 3: // Attendance Management
                {
                    int attChoice;
                    cout << "\n=== ATTENDANCE MANAGEMENT ===";
                    cout << "\n1. Mark Attendance";
                    cout << "\n2. View All Attendance";
                    cout << "\n3. Back";
                    cout << "\nEnter choice: ";
                    cin >> attChoice;
                    
                    switch (attChoice) {
                        case 1:
                            attendanceManager.markAttendance();
                            break;
                        case 2:
                            attendanceManager.viewAttendance();
                            break;
                        case 3:
                            break;
                        default:
                            cout << "\nInvalid choice.\n";
                    }
                }
                break;
                
            case 4: // Exam Management
                {
                    int examChoice;
                    cout << "\n=== EXAM MANAGEMENT ===";
                    cout << "\n1. Add Exam";
                    cout << "\n2. Enter Marks";
                    cout << "\n3. View All Exams";
                    cout << "\n4. View All Marks";
                    cout << "\n5. Sort Students by Marks";
                    cout << "\n6. Generate Reports";
                    cout << "\n7. Back";
                    cout << "\nEnter choice: ";
                    cin >> examChoice;
                    
                    switch (examChoice) {
                        case 1:
                            examManager.addExam();
                            break;
                        case 2:
                            examManager.enterMarks();
                            break;
                        case 3:
                            examManager.viewExams();
                            break;
                        case 4:
                            examManager.viewMarks();
                            break;
                        case 5:
                            examManager.sortStudentsByMarks();
                            break;
                        case 6:
                            {
                                int reportChoice;
                                cout << "\n=== REPORT GENERATION ===";
                                cout << "\n1. Marks Report";
                                cout << "\n2. Exam Report";
                                cout << "\nEnter choice: ";
                                cin >> reportChoice;
                                
                                if (reportChoice == 1) {
                                    examManager.generateMarksReport();
                                } else if (reportChoice == 2) {
                                    examManager.generateExamReport();
                                } else {
                                    cout << "\nInvalid choice.\n";
                                }
                            }
                            break;
                        case 7:
                            break;
                        default:
                            cout << "\nInvalid choice.\n";
                    }
                }
                break;
                
            case 5: // Library Management
                {
                    int libChoice;
                    cout << "\n=== LIBRARY MANAGEMENT ===";
                    cout << "\n1. Add Book";
                    cout << "\n2. Issue Book";
                    cout << "\n3. Return Book";
                    cout << "\n4. View All Books";
                    cout << "\n5. View Available Books";
                    cout << "\n6. Back";
                    cout << "\nEnter choice: ";
                    cin >> libChoice;
                    
                    switch (libChoice) {
                        case 1:
                            libraryManager.addBook();
                            break;
                        case 2:
                            libraryManager.issueBook();
                            break;
                        case 3:
                            libraryManager.returnBook();
                            break;
                        case 4:
                            libraryManager.viewBooks();
                            break;
                        case 5:
                            libraryManager.viewAvailableBooks();
                            break;
                        case 6:
                            break;
                        default:
                            cout << "\nInvalid choice.\n";
                    }
                }
                break;
                
            case 6: // View All Data
                {
                    cout << "\n=== VIEW ALL DATA ===" << endl;
                    courseManager.viewAllCourses();
                    attendanceManager.viewAttendance();
                    examManager.viewExams();
                    examManager.viewMarks();
                    libraryManager.viewBooks();
                }
                break;
                
            case 7: // Change Password
                authManager.changePassword();
                break;
                
            case 8: // Logout
                authManager.logout();
                return;
                
            default:
                cout << "\nInvalid choice.\n";
        }
    }
}

void handleStudentOperations() {
    int choice;
    string currentUser = authManager.getCurrentUser();
    
    while (authManager.isLoggedIn() && authManager.getCurrentRole() == "student") {
        displayStudentMenu();
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: // View Courses
                courseManager.viewAllCourses();
                break;
                
            case 2: // Enroll/Drop Courses
                {
                    int enrollChoice;
                    cout << "\n=== ENROLLMENT MANAGEMENT ===";
                    cout << "\n1. Enroll in Course";
                    cout << "\n2. Drop Course";
                    cout << "\n3. Back";
                    cout << "\nEnter choice: ";
                    cin >> enrollChoice;
                    
                    if (enrollChoice == 1) {
                        string courseID;
                        cout << "\nEnter Course ID to enroll: ";
                        cin >> courseID;
                        
                        // Using dummy student ID - in real system, get from current user
                        int studentID = 1001;
                        if (courseManager.enrollStudent(courseID, studentID)) {
                            cout << "\n✓ Successfully enrolled in course!\n";
                        } else {
                            cout << "\n✗ Enrollment failed.\n";
                        }
                    } else if (enrollChoice == 2) {
                        string courseID;
                        cout << "\nEnter Course ID to drop: ";
                        cin >> courseID;
                        
                        int studentID = 1001;
                        if (courseManager.dropStudent(courseID, studentID)) {
                            cout << "\n✓ Successfully dropped from course!\n";
                        } else {
                            cout << "\n✗ Failed to drop from course.\n";
                        }
                    }
                }
                break;
                
            case 3: // View Attendance
                attendanceManager.viewStudentAttendance(currentUser);
                break;
                
            case 4: // View Exam Marks
                {
                    cout << "\n=== YOUR MARKS ===" << endl;
                    // In real system, filter by current user
                    examManager.viewMarks();
                }
                break;
                
            case 5: // Library Services
                {
                    int libChoice;
                    cout << "\n=== LIBRARY SERVICES ===";
                    cout << "\n1. View Available Books";
                    cout << "\n2. Issue Book";
                    cout << "\n3. Return Book";
                    cout << "\n4. Back";
                    cout << "\nEnter choice: ";
                    cin >> libChoice;
                    
                    if (libChoice == 1) {
                        libraryManager.viewAvailableBooks();
                    } else if (libChoice == 2) {
                        libraryManager.issueBook();
                    } else if (libChoice == 3) {
                        libraryManager.returnBook();
                    }
                }
                break;
                
            case 6: // Change Password
                authManager.changePassword();
                break;
                
            case 7: // Logout
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
                
            case 2: // Mark Attendance
                attendanceManager.markAttendance();
                break;
                
            case 3: // Enter Exam Marks
                examManager.enterMarks();
                break;
                
            case 4: // View Library
                libraryManager.viewBooks();
                break;
                
            case 5: // Change Password
                authManager.changePassword();
                break;
                
            case 6: // Logout
                authManager.logout();
                return;
                
            default:
                cout << "\nInvalid choice.\n";
        }
    }
}

void testPolymorphism() {
    cout << "\n=== POLYMORPHISM DEMONSTRATION ===\n";
    
    vector<Person*> people;
    
    people.push_back(new Student("Alice Johnson", 1001, 20));
    people.push_back(new Teacher("Dr. Smith", 2001, 45));
    people.push_back(new Admin("Mr. Wilson", 3001, 50));
    people.push_back(new Student("Bob Brown", 1002, 21));
    
    cout << "\nDisplaying profiles using polymorphism:\n";
    for (int i = 0; i < people.size(); i++) {
        people[i]->printProfile();
        cout << "-------------------\n";
    }
    
    for (int i = 0; i < people.size(); i++) {
        delete people[i];
    }
    
    cout << "\n✓ Polymorphism test completed successfully!\n";
}

void testAssignment2Features() {
    cout << "\n=== ASSIGNMENT 2 FEATURES DEMONSTRATION ===\n";
    
    cout << "\n1. Testing Attendance System:" << endl;
    cout << "==============================" << endl;
    attendanceManager.markAttendance();
    
    cout << "\n2. Testing Exam System:" << endl;
    cout << "========================" << endl;
    examManager.addExam();
    examManager.enterMarks();
    
    cout << "\n3. Testing Library System:" << endl;
    cout << "===========================" << endl;
    libraryManager.addBook();
    
    cout << "\n4. Testing Operator Overloading:" << endl;
    cout << "=================================" << endl;
    examManager.sortStudentsByMarks();
    
    cout << "\n5. Testing Template Class:" << endl;
    cout << "===========================" << endl;
    examManager.generateMarksReport();
    
    cout << "\n✓ Assignment 2 features tested successfully!\n";
}