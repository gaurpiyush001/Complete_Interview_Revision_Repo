#ifndef GROUP_H
#define GROUP_H

#include <string>
#include <vector>
#include <mutex>
#include "User.h"
#include "Expense.h"

class Group {
private:
    std::string id;
    std::string name;

    std::vector<User> members;
    std::vector<Expense> expenses;

    mutable std::mutex memberMutex;
    mutable std::mutex expenseMutex;

public:
    Group(const std::string& id, const std::string& name)
        : id(id), name(name) {}

    void addMember(const User& user) {
        std::lock_guard<std::mutex> lock(memberMutex);
        members.push_back(user);
    }

    void addExpense(const Expense& expense) {
        std::lock_guard<std::mutex> lock(expenseMutex);
        expenses.push_back(expense);
    }

    std::string getId() const {
        return id;
    }

    std::string getName() const {
        return name;
    }

    std::vector<User> getMembers() const {
        std::lock_guard<std::mutex> lock(memberMutex);
        return members;
    }

    std::vector<Expense> getExpenses() const {
        std::lock_guard<std::mutex> lock(expenseMutex);
        return expenses;
    }
};

#endif // GROUP_H
