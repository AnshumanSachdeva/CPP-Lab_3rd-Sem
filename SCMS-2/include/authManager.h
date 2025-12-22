#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include "logger.h"

using namespace std;

extern Logger logger;

class AuthException : public exception {
private:
    string message;
public:
    AuthException(string msg) : message(msg) {}
    char* what() {
        return &message[0];
    }
};

class AuthManager {
private:
    string currentUser;
    string currentRole;
    
    // Simple hash function (basic implementation)
    string hashPassword(string password);
    
    // Helper functions
    bool userExists(string username);
    void saveUser(string username, string password, string role);
    
public:
    AuthManager() : currentUser(""), currentRole("") {}
    
    void registerUser();
    bool login();
    void logout();
    void changePassword();
    void removeUser();
    
    bool isLoggedIn() { return !currentUser.empty(); }
    string getCurrentUser() { return currentUser; }
    string getCurrentRole() { return currentRole; }
};

#endif