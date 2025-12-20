#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "authManager.h"
#include "logger.h"

using namespace std;

extern Logger logger;

// Simple hash function
string AuthManager::hashPassword(string password) {
    // Simple hash for demonstration
    unsigned int hash = 5381;
    for (char c : password) {
        hash = ((hash << 5) + hash) + c;
    }
    
    stringstream ss;
    ss << hex << setw(8) << setfill('0') << hash;
    return ss.str();
}

bool AuthManager::userExists(string username) {
    ifstream file("../data/users.txt");
    string line;
    
    while (getline(file, line)) {
        stringstream ss(line);
        string storedUser;
        ss >> storedUser;
        
        if (storedUser == username) {
            file.close();
            return true;
        }
    }
    
    file.close();
    return false;
}

void AuthManager::saveUser(string username, string password, string role) {
    ofstream file("../data/users.txt", ios::app);
    if (!file) {
        throw AuthException("Cannot open users file for writing");
    }
    
    file << username << " " << hashPassword(password) << " " << role << endl;
    file.close();
}

void AuthManager::registerUser() {
    try {
        string username, password, role;
        
        cout << "\n=== USER REGISTRATION ===\n";
        cout << "Enter username: ";
        cin >> username;
        
        if (userExists(username)) {
            throw AuthException("Username already exists");
        }
        
        cout << "Enter password: ";
        cin >> password;
        
        if (password.length() < 4) {
            throw AuthException("Password must be at least 4 characters");
        }
        
        cout << "Select role (student/teacher/admin): ";
        cin >> role;
        
        if (role != "student" && role != "teacher" && role != "admin") {
            throw AuthException("Invalid role. Must be student, teacher, or admin");
        }
        
        saveUser(username, password, role);
        
        logger.log("INFO", "AUTH", "New user registered: " + username + " (Role: " + role + ")");
        cout << "\n✓ Registration successful! You can now login.\n";
        
    } catch (AuthException& e) {
        logger.log("ERROR", "AUTH", "Registration failed: " + string(e.what()));
        cout << "\n✗ Error: " << e.what() << endl;
    } catch (exception& e) {
        logger.log("ERROR", "AUTH", "Registration exception: " + string(e.what()));
        cout << "\n✗ An error occurred: " << e.what() << endl;
    }
}

bool AuthManager::login() {
    try {
        string username, password;
        
        cout << "\n=== LOGIN ===\n";
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
        
        string hashedPassword = hashPassword(password);
        
        ifstream file("../data/users.txt");
        if (!file) {
            throw AuthException("Cannot open users file");
        }
        
        string line;
        bool found = false;
        
        while (getline(file, line)) {
            stringstream ss(line);
            string storedUser, storedPass, storedRole;
            
            if (ss >> storedUser >> storedPass >> storedRole) {
                if (storedUser == username && storedPass == hashedPassword) {
                    currentUser = username;
                    currentRole = storedRole;
                    found = true;
                    break;
                }
            }
        }
        
        file.close();
        
        if (found) {
            logger.log("INFO", "AUTH", "Login successful: " + username + " (Role: " + currentRole + ")");
            cout << "\n✓ Login successful! Welcome, " << username << " (" << currentRole << ")\n";
            return true;
        } else {
            logger.log("WARNING", "AUTH", "Failed login attempt: " + username);
            cout << "\n✗ Invalid username or password\n";
            return false;
        }
        
    } catch (exception& e) {
        logger.log("ERROR", "AUTH", "Login exception: " + string(e.what()));
        cout << "\n✗ Login error: " << e.what() << endl;
        return false;
    }
}

void AuthManager::logout() {
    if (isLoggedIn()) {
        logger.log("INFO", "AUTH", "User logged out: " + currentUser);
        cout << "\n✓ Logged out successfully. Goodbye, " + currentUser << "!\n";
    } else {
        cout << "\nNo user is currently logged in.\n";
    }
    
    currentUser = "";
    currentRole = "";
}

void AuthManager::changePassword() {
    if (!isLoggedIn()) {
        cout << "\nYou must be logged in to change password.\n";
        return;
    }
    
    try {
        string oldPass, newPass;
        
        cout << "\n=== CHANGE PASSWORD ===\n";
        cout << "Enter current password: ";
        cin >> oldPass;
        cout << "Enter new password: ";
        cin >> newPass;
        
        if (newPass.length() < 4) {
            throw AuthException("New password must be at least 4 characters");
        }
        
        // Read all users
        ifstream file("../data/users.txt");
        if (!file) {
            throw AuthException("Cannot open users file");
        }
        
        vector<string> lines;
        string line;
        bool found = false;
        
        while (getline(file, line)) {
            stringstream ss(line);
            string storedUser, storedPass, storedRole;
            
            if (ss >> storedUser >> storedPass >> storedRole) {
                if (storedUser == currentUser && storedPass == hashPassword(oldPass)) {
                    line = storedUser + " " + hashPassword(newPass) + " " + storedRole;
                    found = true;
                }
            }
            lines.push_back(line);
        }
        
        file.close();
        
        if (!found) {
            throw AuthException("Current password is incorrect");
        }
        
        // Write back to file
        ofstream outFile("../data/users.txt");
        if (!outFile) {
            throw AuthException("Cannot save password change");
        }
        
        for (string& l : lines) {
            outFile << l << endl;
        }
        
        outFile.close();
        
        logger.log("INFO", "AUTH", "Password changed for user: " + currentUser);
        cout << "\n✓ Password changed successfully!\n";
        
    } catch (AuthException& e) {
        logger.log("ERROR", "AUTH", "Password change failed: " + string(e.what()));
        cout << "\n✗ Error: " << e.what() << endl;
    } catch (exception& e) {
        logger.log("ERROR", "AUTH", "Password change exception: " + string(e.what()));
        cout << "\n✗ An error occurred: " << e.what() << endl;
    }
}

void AuthManager::removeUser() {
    if (!isLoggedIn() || currentRole != "admin") {
        cout << "\nOnly admin can remove users.\n";
        return;
    }
    
    try {
        string username;
        cout << "\nEnter username to remove: ";
        cin >> username;
        
        if (username == currentUser) {
            throw AuthException("Cannot remove your own account");
        }
        
        // Read all users
        ifstream file("../data/users.txt");
        if (!file) {
            throw AuthException("Cannot open users file");
        }
        
        vector<string> lines;
        string line;
        bool found = false;
        
        while (getline(file, line)) {
            stringstream ss(line);
            string storedUser, storedPass, storedRole;
            
            if (ss >> storedUser) {
                if (storedUser != username) {
                    lines.push_back(line);
                } else {
                    found = true;
                }
            }
        }
        
        file.close();
        
        if (!found) {
            throw AuthException("User not found");
        }
        
        // Write back to file
        ofstream outFile("../data/users.txt");
        if (!outFile) {
            throw AuthException("Cannot save changes");
        }
        
        for (string& l : lines) {
            outFile << l << endl;
        }
        
        outFile.close();
        
        logger.log("INFO", "AUTH", "User removed by admin: " + currentUser + " removed user: " + username);
        cout << "\n✓ User removed successfully.\n";
        
    } catch (AuthException& e) {
        logger.log("ERROR", "AUTH", "Remove user failed: " + string(e.what()));
        cout << "\n✗ Error: " << e.what() << endl;
    } catch (exception& e) {
        logger.log("ERROR", "AUTH", "Remove user exception: " + string(e.what()));
        cout << "\n✗ An error occurred: " << e.what() << endl;
    }
}