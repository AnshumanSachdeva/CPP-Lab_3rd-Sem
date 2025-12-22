#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string bookID;
    string title;
    string author;
    string ISBN;
    int totalCopies;
    int availableCopies;
    
public:
    Book();
    Book(string bid, string t, string a, string isbn, int copies);
    
    // Getters
    string getBookID() { return bookID; }
    string getTitle() { return title; }
    string getAuthor() { return author; }
    string getISBN() { return ISBN; }
    int getTotalCopies() { return totalCopies; }
    int getAvailableCopies() { return availableCopies; }
    
    // Setters
    void setBookID(string bid) { bookID = bid; }
    void setTitle(string t) { title = t; }
    void setAuthor(string a) { author = a; }
    void setISBN(string isbn) { ISBN = isbn; }
    void setTotalCopies(int copies) { totalCopies = copies; }
    void setAvailableCopies(int copies) { availableCopies = copies; }
    
    // Book operations
    bool issueBook();
    bool returnBook();
    bool isAvailable();
    
    void display();
};

#endif