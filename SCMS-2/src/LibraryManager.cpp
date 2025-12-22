#include "libraryManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <iomanip>

using namespace std;

extern Logger logger;

LibraryManager::LibraryManager() {
    loadBooks();
}

LibraryManager::~LibraryManager() {
    saveBooks();
}

void LibraryManager::loadBooks() {
    ifstream file(booksFile);
    if (!file) {
        logger.log("INFO", "LIBRARY", "No books file found, starting fresh");
        return;
    }
    
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string bid, title, author, isbn;
        int total, available;
        
        if (ss >> bid >> title >> author >> isbn >> total >> available) {
            Book book(bid, title, author, isbn, total);
            book.setAvailableCopies(available);
            books.push_back(book);
        }
    }
    
    file.close();
    logger.log("INFO", "LIBRARY", "Loaded " + to_string(books.size()) + " books");
}

void LibraryManager::saveBooks() {
    ofstream file(booksFile);
    if (!file) {
        logger.log("ERROR", "LIBRARY", "Cannot open books file for writing");
        return;
    }
    
    for (Book& book : books) {
        file << book.getBookID() << " "
             << book.getTitle() << " "
             << book.getAuthor() << " "
             << book.getISBN() << " "
             << book.getTotalCopies() << " "
             << book.getAvailableCopies() << endl;
    }
    
    file.close();
}

void LibraryManager::logTransaction(string action, string bookID, string userID) {
    ofstream file(transactionFile, ios::app);
    if (!file) {
        logger.log("ERROR", "LIBRARY", "Cannot open transaction log file");
        return;
    }
    
    time_t now = time(0);
    string dt = ctime(&now);
    dt.pop_back(); // Remove newline
    
    file << "[" << dt << "] " 
         << action << " - Book: " << bookID 
         << " - User: " << userID << endl;
    
    file.close();
    
    logger.log("INFO", "LIBRARY", action + " transaction logged for book: " + bookID);
}

void LibraryManager::addBook() {
    try {
        string bid, title, author, isbn;
        int copies;
        
        cout << "\n=== ADD NEW BOOK ===" << endl;
        cout << "Enter Book ID: ";
        cin >> bid;
        cout << "Enter Title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter Author: ";
        getline(cin, author);
        cout << "Enter ISBN: ";
        cin >> isbn;
        cout << "Enter Number of Copies: ";
        cin >> copies;
        
        if (copies <= 0) {
            throw runtime_error("Number of copies must be positive");
        }
        
        Book newBook(bid, title, author, isbn, copies);
        books.push_back(newBook);
        saveBooks();
        
        logger.log("INFO", "LIBRARY", "Book added: " + bid + " - " + title);
        cout << "\n✓ Book added successfully!" << endl;
        
    } catch (exception& e) {
        logger.log("ERROR", "LIBRARY", "Add book failed: " + string(e.what()));
        cout << "\n✗ Error: " << e.what() << endl;
    }
}

void LibraryManager::issueBook() {
    try {
        string bookID, userID;
        
        cout << "\n=== ISSUE BOOK ===" << endl;
        cout << "Enter Book ID: ";
        cin >> bookID;
        cout << "Enter User ID: ";
        cin >> userID;
        
        Book* book = findBook(bookID);
        if (!book) {
            throw LibraryException("Book not found");
        }
        
        if (book->issueBook()) {
            saveBooks();
            logTransaction("ISSUE", bookID, userID);
            
            cout << "\n✓ Book issued successfully!" << endl;
            cout << "Available copies: " << book->getAvailableCopies() << endl;
        } else {
            throw LibraryException("No copies available for issuing");
        }
        
    } catch (LibraryException& e) {
        logger.log("ERROR", "LIBRARY", "Issue book failed: " + string(e.what()));
        cout << "\n✗ Error: " << e.what() << endl;
    } catch (exception& e) {
        logger.log("ERROR", "LIBRARY", "Issue book exception: " + string(e.what()));
        cout << "\n✗ Error: " << e.what() << endl;
    }
}

void LibraryManager::returnBook() {
    try {
        string bookID, userID;
        
        cout << "\n=== RETURN BOOK ===" << endl;
        cout << "Enter Book ID: ";
        cin >> bookID;
        cout << "Enter User ID: ";
        cin >> userID;
        
        Book* book = findBook(bookID);
        if (!book) {
            throw LibraryException("Book not found");
        }
        
        if (book->returnBook()) {
            saveBooks();
            logTransaction("RETURN", bookID, userID);
            
            cout << "\n✓ Book returned successfully!" << endl;
            cout << "Available copies: " << book->getAvailableCopies() << endl;
        } else {
            throw LibraryException("All copies already available");
        }
        
    } catch (LibraryException& e) {
        logger.log("ERROR", "LIBRARY", "Return book failed: " + string(e.what()));
        cout << "\n✗ Error: " << e.what() << endl;
    } catch (exception& e) {
        logger.log("ERROR", "LIBRARY", "Return book exception: " + string(e.what()));
        cout << "\n✗ Error: " << e.what() << endl;
    }
}

Book* LibraryManager::findBook(string bookID) {
    for (Book& book : books) {
        if (book.getBookID() == bookID) {
            return &book;
        }
    }
    return nullptr;
}

void LibraryManager::viewBooks() {
    if (books.empty()) {
        cout << "\nNo books available in library." << endl;
        return;
    }
    
    cout << "\n=== LIBRARY BOOKS ===" << endl;
    cout << "Total books: " << books.size() << endl;
    
    for (Book& book : books) {
        book.display();
        cout << "-------------------" << endl;
    }
}

void LibraryManager::viewAvailableBooks() {
    cout << "\n=== AVAILABLE BOOKS ===" << endl;
    
    bool found = false;
    for (Book& book : books) {
        if (book.isAvailable()) {
            book.display();
            found = true;
        }
    }
    
    if (!found) {
        cout << "No books currently available." << endl;
    }
}