#ifndef DepositTransaction_H
#define DepositTransaction_H 

#include <mutex>
#include <memory>
#include <bits/stdc++.h>
#include "Account.h"
using namespace std;

class DepositTransaction : public Transaction {
    public:
    DepositTransaction(string& id, std::shared_ptr<Account> acc, double amt)
            : Transaction(id, acc, amt) {}
    
    void execute() override {
        account->credit(amount);
    }
};
    

#endif