#include <iostream>
using namespace std;

class Bank {
    int accNo;
    double balance;

public:
    Bank() {
        accNo = 1;
        balance = 0.0;
    }

    Bank(int a, double b) {
        accNo = a;
        balance = b;
    }

    void deposit(double amt) {
        if (amt > 0) {
            balance += amt;
            cout << "Deposited " << amt << " to account " << accNo << endl;
        } else {
            cout << "Invalid deposit amount" << endl;
        }
    }

    void withdraw(double amt) {
        if (amt > 0 && balance >= amt) {
            balance -= amt;
            cout << "Withdrew " << amt << " from account " << accNo << endl;
        } else {
            cout << "Insufficient balance or invalid amount" << endl;
        }
    }

    void checkBalance() {
        cout << "Account " << accNo << " balance: " << balance << endl;
    }

    void addInterest() {
        double interest = balance * 0.05;
        balance += interest;
        cout << "Added interest " << interest << " to account " << accNo << endl;
    }

    void transfer(Bank& to, double amt) {
        if (amt > 0 && balance >= amt) {
            balance -= amt;
            to.balance += amt;
            cout << "Transferred " << amt << " from account " << accNo << " to account " << to.accNo << endl;
        } else {
            cout << "Transfer failed: Insufficient balance or invalid amount" << endl;
        }
    }
};

int main() {
    Bank users[10];

    for (int i = 0; i < 10; i++) {
        users[i] = Bank(i + 1, 0.0);
    }

    cout << "Initial balances:" << endl;
    for (int i = 0; i < 10; i++) {
        users[i].checkBalance();
    }

    users[0].deposit(1000); 
    users[0].withdraw(200);
    users[0].checkBalance();
    users[0].addInterest();
    users[0].transfer(users[1], 100);

    users[0].checkBalance();
    users[1].checkBalance();

    return 0;
}
