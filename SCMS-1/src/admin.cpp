#include <iostream>
#include "admin.h"
using namespace std;

void Admin :: printProfile()
{
    cout << "Admin Profile:\n";
    cout << "Name: " << name << "\nID: " << id << "\nAge: " << age << endl;
}
Admin::Admin(string n, int i, int a) : Person(n, i, a)
{
    logger.log("INFO", "USER", "Admin object created");
}

Admin::~Admin()
{
    logger.log("INFO", "USER", "Admin object destroyed");
}