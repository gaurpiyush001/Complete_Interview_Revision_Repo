


#ifndef BANKING_SERVICE_H
#define BANKING_SERVICE_H

#include <unordered_map>
#include <memory>
#include <mutex>
#include <string>
#include "Account.hpp"
#include "Transaction.hpp"
using namespae std;

class BankingService {
private:
    unordered_map<string, shared_ptr<Account>> accounts;
    mutex mtx;

public:
    void createAccount(const string& accNum, double balance) {
        lock_guard<mutex> lock(mtx);
        accounts[accNum] = make_shared<Account>(accNum, balance);
    }

    shared_ptr<Account> getAccount(const std::string& accNum) {
        lock_guard<mutex> lock(mtx);
        auto it = accounts.find(accNum);
        return (it != accounts.end()) ? it->second : nullptr;
    }

    void processTransaction(Transaction* txn) {
        txn->execute();
    }
};

#endif
