#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <memory>
#include "User.h"

class Transaction {
private:
    std::string id;
    std::shared_ptr<User> sender;
    std::shared_ptr<User> receiver;
    double amount;

public:
    Transaction(const std::string& id, std::shared_ptr<User> sender, std::shared_ptr<User> receiver, double amount)
        : id(id), sender(std::move(sender)), receiver(std::move(receiver)), amount(amount) {}

    const std::string& getId() const {
        return id;
    }

    std::shared_ptr<User> getSender() const {
        return sender;
    }

    std::shared_ptr<User> getReceiver() const {
        return receiver;
    }

    double getAmount() const {
        return amount;
    }
};

#endif // TRANSACTION_H
