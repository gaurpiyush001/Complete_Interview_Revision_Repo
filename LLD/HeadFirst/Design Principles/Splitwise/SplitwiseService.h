#ifndef SPLITWISE_SERVICE_H
#define SPLITWISE_SERVICE_H

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <iomanip>
#include <atomic>

#include "User.h"
#include "Group.h"
#include "Expense.h"
#include "Transaction.h"
#include "splittype/EqualSplit.h"
#include "splittype/PercentSplit.h"

class SplitwiseService {
private:
    static std::shared_ptr<SplitwiseService> instance;
    std::unordered_map<std::string, std::shared_ptr<User>> users;
    std::unordered_map<std::string, std::shared_ptr<Group>> groups;

    static constexpr const char* TRANSACTION_ID_PREFIX = "TXN";
    static std::atomic<int> transactionCounter;

    SplitwiseService() = default;

public:
    static std::shared_ptr<SplitwiseService> getInstance() {
        if (!instance) {
            instance = std::shared_ptr<SplitwiseService>(new SplitwiseService());
        }
        return instance;
    }

    void addUser(const std::shared_ptr<User>& user) {
        users[user->getId()] = user;
    }

    void addGroup(const std::shared_ptr<Group>& group) {
        groups[group->getId()] = group;
    }

    void addExpense(const std::string& groupId, const std::shared_ptr<Expense>& expense) {
        auto group = groups[groupId];
        if (group) {
            group->addExpense(expense);
            splitExpense(expense);
            updateBalances(expense);
        }
    }

private:
    void splitExpense(const std::shared_ptr<Expense>& expense) {
        double totalAmount = expense->getAmount();
        const auto& splits = expense->getSplits();
        int totalSplits = splits.size();

        double splitAmount = totalAmount / totalSplits;
        for (const auto& split : splits) {
            if (auto equalSplit = std::dynamic_pointer_cast<EqualSplit>(split)) {
                equalSplit->setAmount(splitAmount);
            } else if (auto percentSplit = std::dynamic_pointer_cast<PercentSplit>(split)) {
                percentSplit->setAmount(totalAmount * percentSplit->getPercent() / 100.0);
            }
        }
    }

    void updateBalances(const std::shared_ptr<Expense>& expense) {
        for (const auto& split : expense->getSplits()) {
            auto paidBy = expense->getPaidBy();
            auto user = split->getUser();
            double amount = split->getAmount();

            if (paidBy->getId() != user->getId()) {
                updateBalance(paidBy, user, amount);
                updateBalance(user, paidBy, -amount);
            }
        }
    }

    void updateBalance(const std::shared_ptr<User>& user1, const std::shared_ptr<User>& user2, double amount) {
        std::string key = getBalanceKey(user1, user2);
        user1->getBalances()[key] += amount;
    }

    std::string getBalanceKey(const std::shared_ptr<User>& user1, const std::shared_ptr<User>& user2) {
        return user1->getId() + ":" + user2->getId();
    }

public:
    void settleBalance(const std::string& userId1, const std::string& userId2) {
        auto user1 = users[userId1];
        auto user2 = users[userId2];

        if (user1 && user2) {
            std::string key = getBalanceKey(user1, user2);
            double balance = user1->getBalances()[key];

            if (balance > 0) {
                createTransaction(user1, user2, balance);
                user1->getBalances()[key] = 0.0;
                user2->getBalances()[getBalanceKey(user2, user1)] = 0.0;
            } else if (balance < 0) {
                createTransaction(user2, user1, -balance);
                user1->getBalances()[key] = 0.0;
                user2->getBalances()[getBalanceKey(user2, user1)] = 0.0;
            }
        }
    }

private:
    void createTransaction(const std::shared_ptr<User>& sender, const std::shared_ptr<User>& receiver, double amount) {
        std::string transactionId = generateTransactionId();
        Transaction transaction(transactionId, sender, receiver, amount);
        // Optional: Log or store transaction
    }

    std::string generateTransactionId() {
        int transactionNumber = transactionCounter++;
        std::ostringstream oss;
        oss << TRANSACTION_ID_PREFIX << std::setw(6) << std::setfill('0') << transactionNumber;
        return oss.str();
    }
};

std::shared_ptr<SplitwiseService> SplitwiseService::instance = nullptr;
std::atomic<int> SplitwiseService::transactionCounter{0};

#endif // SPLITWISE_SERVICE_H