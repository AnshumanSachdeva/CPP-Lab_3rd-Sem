#include <iostream>
#include "person.h"
using namespace std;

Person::Person(string n, int i, int a)
{
    name = n;
    id = i;
    age = a;
    logger.log("INFO", "USER", "Person object created");
}

Person::~Person()
{
    logger.log("INFO", "USER", "Person object destroyed");
}

