#ifndef USER_H
#define USER_H

#include <string>
#include <unordered_map>
#include <mutex>

class User {
private:
    std::string id;
    std::string name;
    std::string email;
    std::unordered_map<std::string, double> balances;
    std::mutex balanceMutex;

public:
    User(const std::string& id, const std::string& name, const std::string& email)
        : id(id), name(name), email(email) {}

    const std::string& getId() const {
        return id;
    }

    const std::string& getName() const {
        return name;
    }

    const std::string& getEmail() const {
        return email;
    }

    // Thread-safe access to balances - As in ( ConcurrentHashMap )
    std::unordered_map<std::string, double> getBalances() {
        std::lock_guard<std::mutex> lock(balanceMutex);
        return balances;
    }

    void updateBalance(const std::string& userId, double amount) {
        std::lock_guard<std::mutex> lock(balanceMutex);
        balances[userId] += amount;
    }

    void setBalance(const std::string& userId, double amount) {
        std::lock_guard<std::mutex> lock(balanceMutex);
        balances[userId] = amount;
    }
};

#endif
