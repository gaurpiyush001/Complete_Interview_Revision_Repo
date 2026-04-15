#ifndef SPLITWISE_DEMO_H
#define SPLITWISE_DEMO_H

#include "SplitwiseService.h"
#include "EqualSplit.h"
#include "PercentSplit.h"

#include <iostream>
#include <vector>
#include <memory>

class SplitwiseDemo {
public:
    static void run() {
        auto& splitwiseService = SplitwiseService::getInstance();

        // Create users
        auto user1 = std::make_shared<User>("1", "Alice", "alice@example.com");
        auto user2 = std::make_shared<User>("2", "Bob", "bob@example.com");
        auto user3 = std::make_shared<User>("3", "Charlie", "charlie@example.com");

        splitwiseService.addUser(user1);
        splitwiseService.addUser(user2);
        splitwiseService.addUser(user3);

        // Create a group
        auto group = std::make_shared<Group>("1", "Apartment");
        group->addMember(user1);
        group->addMember(user2);
        group->addMember(user3);

        splitwiseService.addGroup(group);

        // Add an expense
        auto expense = std::make_shared<Expense>("1", 300.0, "Rent", user1);

        auto equalSplit1 = std::make_shared<EqualSplit>(user1);
        auto equalSplit2 = std::make_shared<EqualSplit>(user2);
        auto percentSplit = std::make_shared<PercentSplit>(user3, 20.0);

        expense->addSplit(equalSplit1);
        expense->addSplit(equalSplit2);
        expense->addSplit(percentSplit);

        splitwiseService.addExpense(group->getId(), expense);

        // Settle balances
        splitwiseService.settleBalance(user1->getId(), user2->getId());
        splitwiseService.settleBalance(user1->getId(), user3->getId());

        // Print user balances
        for (const auto& user : std::vector<std::shared_ptr<User>>{user1, user2, user3}) {
            std::cout << "User: " << user->getName() << std::endl;
            for (const auto& [key, value] : user->getBalances()) {
                std::cout << "  Balance with " << key << ": " << value << std::endl;
            }
        }
    }
};

#endif // SPLITWISE_DEMO_H
