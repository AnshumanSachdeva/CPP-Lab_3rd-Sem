#include <iostream>
#include "student.h"
using namespace std;

void Student ::printProfile()
{
    cout << "Student Profile:\n";
    cout << "Name: " << name << "\nID: " << id << "\nAge: " << age << endl;
}
Student::Student(string n, int i, int a) : Person(n, i, a)
{
    logger.log("INFO", "USER", "Student object created");
}

Student::~Student()
{
    logger.log("INFO", "USER", "Student object destroyed");
}