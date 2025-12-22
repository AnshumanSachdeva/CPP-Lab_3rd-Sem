#include "book.h"
#include <iostream>

using namespace std;

Book::Book() 
    : bookID(""), title(""), author(""), ISBN(""), totalCopies(0), availableCopies(0) {}

Book::Book(string bid, string t, string a, string isbn, int copies)
    : bookID(bid), title(t), author(a), ISBN(isbn), 
      totalCopies(copies), availableCopies(copies) {}

bool Book::issueBook() {
    if (availableCopies > 0) {
        availableCopies--;
        return true;
    }
    return false;
}

bool Book::returnBook() {
    if (availableCopies < totalCopies) {
        availableCopies++;
        return true;
    }
    return false;
}

bool Book::isAvailable() {
    return availableCopies > 0;
}

void Book::display() {
    cout << "\nBook ID: " << bookID
         << "\nTitle: " << title
         << "\nAuthor: " << author
         << "\nISBN: " << ISBN
         << "\nTotal Copies: " << totalCopies
         << "\nAvailable Copies: " << availableCopies
         << endl;
}