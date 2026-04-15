#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>
#include <vector>
#include <memory>
#include "User.h"
#include "splittype/Split.h"

class Expense {
private:
    std::string id;
    double amount;
    std::string description;
    std::shared_ptr<User> paidBy;// replaceent of User*
    std::vector<std::shared_ptr<Split>> splits;

public:
    Expense(const std::string& id, double amount, const std::string& description, std::shared_ptr<User> paidBy)
        : id(id), amount(amount), description(description), paidBy(std::move(paidBy)) {}

    void addSplit(const std::shared_ptr<Split>& split) {
        splits.push_back(split);
    }

    const std::string& getId() const {
        return id;
    }

    double getAmount() const {
        return amount;
    }

    const std::string& getDescription() const {
        return description;
    }

    std::shared_ptr<User> getPaidBy() const {
        return paidBy;
    }

    std::vector<std::shared_ptr<Split>>& getSplits() {
        return splits;
    }

};

#endif // EXPENSE_H
