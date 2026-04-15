#ifndef ATM_H
#define ATM_H

#include <atomic>
#include <string>
#include <memory>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <bits/stdc++.h>
#include "BankingService.hpp"
#include "Transaction.hpp"

class ATM {
private:
    shared_ptr<BankingService> bankingService;
    static atomic<long> txnCounter;

    string generateTransactionId() {
        long count = txnCounter.fetch_add(1);
        auto now = time(nullptr);
        auto t = localtime(&now);
        std::ostringstream oss;
        oss << "TXN" << std::put_time(t, "%Y%m%d%H%M%S") << std::setw(10) << std::setfill('0') << count;
        return oss.str();
    }

public:
    // ATM(std::shared_ptr<BankingService> service);
    // double checkBalance(const std::string& accNum);
    // void withdrawCash(const std::string& accNum, double amount);
    // void depositCash(const std::string& accNum, double amount);

    ATM(shared_ptr<BankingService> service)
    : bankingService(service), txnCounter(0) {}


    double checkBalance(const string& accNum) {
        auto acc = bankingService->getAccount(accNum);
        return acc ? acc->getBalance() : 0.0;
    }

    void withdrawCash(const string& accNum, double amount) {
        auto acc = bankingService->getAccount(accNum);
        if (!acc || acc->getBalance() < amount) {
            cout << "Insufficient funds.\n";
            return;
        }
        auto txn = new WithdrawalTransaction(generateTransactionId(), acc, amount);
        bankingService->processTransaction(txn);
        std::cout << "Withdrawal successful.\n";
        delete txn;
    }

    void depositCash(const string& accNum, double amount) {
        auto acc = bankingService->getAccount(accNum);
        if (!acc) return;
        auto txn = new DepositTransaction(generateTransactionId(), acc, amount);
        bankingService->processTransaction(txn);
        std::cout << "Deposit successful.\n";
        delete txn;
    }


};

atomic<long> ATM::counter{0};

#endif
