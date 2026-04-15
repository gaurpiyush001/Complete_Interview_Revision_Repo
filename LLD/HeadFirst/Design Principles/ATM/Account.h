#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <mutex>
using namespace std;

class Account {
private:
    std::string accountNumber;
    double balance;
    mutex mtx;

public:
    Account(const std::string& accNum, double initialBalance)
        : accountNumber(accNum), balance(initialBalance) {}

    string getAccountNumber() {
        return accountNumber;
    }

    double getBalance() {
        lock_guard<mutex> lock(mtx);
        return balance;
    }

    void debit(double amount) {
        lock_guard<mutex> lock(mtx);
        balance -= amount;
    }

    void credit(double amount) {
        lock_guard<mutex> lock(mtx);
        balance += amount;
    }

};

#endif