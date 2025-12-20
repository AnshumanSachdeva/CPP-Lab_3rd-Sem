#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
#include "logger.h"
#include "person.h"
extern Logger logger; // main.cpp mein Logger class ka already object bnaya hua hai usi ko use kr rhe hai new nhi bna rhe
using namespace std;

class Teacher : public Person
{

public:
    void printProfile();
    Teacher(string n, int i, int a);
    ~Teacher();
};

#endif