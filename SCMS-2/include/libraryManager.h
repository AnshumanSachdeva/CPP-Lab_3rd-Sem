#ifndef LIBRARYMANAGER_H
#define LIBRARYMANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "book.h"
#include "logger.h"

using namespace std;

extern Logger logger;

class LibraryException : public exception {
private:
    string message;
public:
    LibraryException(string msg) : message(msg) {}
    char* what() {
        return &message[0];
    }
};

class LibraryManager {
private:
    vector<Book> books;
    string booksFile = "../data/books.txt";
    string transactionFile = "../data/transactions.log";
    
    void loadBooks();
    void saveBooks();
    void logTransaction(string action, string bookID, string userID);
    
public:
    LibraryManager();
    ~LibraryManager();
    
    // Book management
    void addBook();
    void removeBook();
    void viewBooks();
    void searchBook();
    
    // Book transactions
    void issueBook();
    void returnBook();
    
    // Reports
    void viewTransactions();
    void viewAvailableBooks();
    
    // Helper functions
    Book* findBook(string bookID);
};

#endif