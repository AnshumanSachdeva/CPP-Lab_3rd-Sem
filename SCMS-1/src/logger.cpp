#include<iostream>
#include<ctime>
#include"logger.h"
using namespace std;


void Logger :: init(){
    string currentTimeStamp = timestamp();
    logFile.open("../logs/scms.log", ios::app);
    if (logFile.is_open())
    {
        cout << "System Started\n";
        logFile << "[" << currentTimeStamp << "] [SYSTEM] [SYSTEM] System Started\n";
    } else {
        cerr << "Error: Cannot open log file!\n";
        exit(1);
    }
}

void Logger :: log(string level, string module, string message){
    string currentTimeStamp = timestamp();
    logFile << "[" << currentTimeStamp << "] [" << level << "] [" << module << "] " << message << "\n";

}

void Logger :: close(){
    string currentTimeStamp = timestamp();
    logFile << "[" << currentTimeStamp << "] [SYSTEM] [SYSTEM] System Shutdown\n";
    logFile.close();
}
