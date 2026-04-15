#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <memory>
#include "Account.hpp"
using namespace std;

// Interface
class Transaction {
protected:
    string txnId;
    shared_ptr<Account> account;
    double amount;

public:
    // Interface
    Transaction(const std::string& id, shared_ptr<Account> account, double amt)
    : txnId(id), account(account), amount(amt) {}

    

    virtual ~Transaction() {}
    virtual void execute() = 0;
};

#endif