#ifndef PERSON_H
#define PERSON_H

#include<iostream>
#include"logger.h"
extern Logger logger; // main.cpp mein Logger class ka already object bnaya hua hai usi ko use kr rhe hai new nhi bna rhe
using namespace std;

class Person
{
protected:
    string name;
    int id, age;
public:
    virtual void printProfile() = 0;
    Person(string n, int i, int a);
    virtual ~Person();
};


#endif