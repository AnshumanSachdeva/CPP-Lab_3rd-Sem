#ifndef PERSON_H
#define PERSON_H

#include<iostream>
#include"logger.h"
extern Logger logger; // main.cpp mein Logger class ka already object bnaya hua hai usi ko use kr rhe hai new nhi bna rhe
using namespace std;

// Person class hai jo system mein sabhi users (students, teachers, admins) ke liye base class ka kaam karti hai.
// Yeh class common properties jaise name, id, aur age ko store karti hai, aur derived classes mein customize ki ja sakti hai.
// Yeh polymorphism ka use karke different types ke users ke liye profile print karne ka facility deti hai.
class Person
{
protected:
    string name; // User ka naam store karta hai, jo system mein identification ke liye use hota hai.
    int id, age; // id unique identifier hai har user ka, aur age user ki umar batati hai.
public:
    virtual void printProfile() = 0; // Yeh pure virtual function hai jo derived classes mein implement ki jaati hai, taki har user apni profile details print kar sake.
    Person(string n, int i, int a); // Constructor jo name, id, aur age ko initialize karta hai jab naya Person object banaya jata hai.
    virtual ~Person(); // Virtual destructor hai jo memory cleanup ke liye use hota hai, especially inheritance mein.
};


#endif
