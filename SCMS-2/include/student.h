#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "logger.h"
#include "person.h"
extern Logger logger; // main.cpp mein Logger class ka already object bnaya hua hai usi ko use kr rhe hai new nhi bna rhe
using namespace std;

class Student : public Person
{

public:
    void printProfile();
    Student(string n, int i, int a);
    ~Student();
};


#endif