#ifndef SPLIT_H
#define SPLIT_H

#include "../User.h"
#include <memory>

class Split {
protected:
    std::shared_ptr<User> user;
    double amount;

public:
    Split(std::shared_ptr<User> user) : user(std::move(user)), amount(0.0) {}

    virtual ~Split() = default;

    virtual double getAmount() const = 0; // Pure virtual function

    void setAmount(double amt) {
        amount = amt;
    }

    std::shared_ptr<User> getUser() const {
        return user;
    }
};

#endif // SPLIT_H
