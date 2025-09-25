#include <iostream>
using namespace std;

class Report {
    string name;
    int rollNo;
    float marks[5];

    public:

    Report(){
        cout << "\nEnter name: ";
        cin >> name; 
        cout << "\nEnter Roll no.: ";
        cin >> rollNo; 
        cout << "\nEnter marks for 5 subjects: ";
        for(int i = 0; i < 5; i++){
            cin >> marks[i];
        }

    }
    float calculatePercentage(){
        float total = 0;
        for (int i = 0; i < 5; i++) {
            total += marks[i];
        }
        return (total / 5.0);  
    }

    char calculateGrade(){
        float per;
        per = calculatePercentage();
        if(per<=100 && per>=90){
            return 'A';
        } else if (per>=80 && per<90){
            return 'B';
        } else if(per>=65 && per<80){
            return 'C';
        } else {
            return 'D';
        }
    }
    void display(){
        char grade = calculateGrade();
        float per;
        per = calculatePercentage();
        cout << "\nYour Name and Roll No. is: " << name << " " << rollNo << endl;
        cout << "Percentage is: " << per << "\nGrade is: " << grade << endl;
    } 
};
int main() {
    Report r1,r2,r3;
    r1.calculateGrade();
    r2.calculateGrade();
    r3.calculateGrade();
    
    r1.display();
    r2.display();
    r3.display();
    return 0;
}