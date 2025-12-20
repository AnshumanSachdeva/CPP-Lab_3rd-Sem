#include <iostream>
#include "teacher.h"
using namespace std;

void Teacher ::printProfile()
{
    cout << "Teacher Profile:\n";
    cout << "Name: " << name << "\nID: " << id << "\nAge: " << age << endl;
}
Teacher::Teacher(string n, int i, int a) : Person(n, i, a)
{
    logger.log("INFO", "USER", "Teacher object created");
}

Teacher::~Teacher()
{
    logger.log("INFO", "USER", "Teacher object destroyed");
}
