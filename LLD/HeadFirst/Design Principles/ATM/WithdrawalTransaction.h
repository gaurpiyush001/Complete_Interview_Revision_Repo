#ifndef WithdrawalTransaction_H
#define WithdrawalTransaction_H 

#include <mutex>
#include <memory>
#include <bits/stdc++.h>
#include "Account.h"
using namespace std;

class WithdrawalTransaction : public Transaction {
    public:
        WithdrawalTransaction(string& id, std::shared_ptr<Account> acc, double amt)
            : Transaction(id, acc, amt) {}
    
        void execute() override {
            account->debit(amount);
        }
    };
    

#endif