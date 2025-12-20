#ifndef LOGGER_H
#define LOGGER_H

#include<iostream>
#include<fstream>
#include <ctime> 
using namespace std;

class Logger{
    ofstream logFile;
public:
    void init();
    void log(string level, string module, string message);
    void close();
    string timestamp(){
        time_t currentTime = time(0); 
        string currentTimeStamp = ctime(&currentTime);
        currentTimeStamp.pop_back(); // removes the '\n'
        return currentTimeStamp;
    }
};
#endif