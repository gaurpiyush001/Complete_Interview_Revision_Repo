#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex db_mutex;  // Mutex to simulate row-level lock
int shared_balance = 1000;  //shared resource

void read_balance(int txn_id) {
    std::lock_guard<std::mutex> lock(db_mutex);  // Simulating read lock
    std::cout << "Txn " << txn_id << " reads balance: " << shared_balance << "\n";
}// 🔓 Lock automatically released when function exits

void write_balance(int txn_id, int amount) {
    std::lock_guard<std::mutex> lock(db_mutex);  // Simulating write lock
    std::cout << "Txn " << txn_id << " writing new balance: " << amount << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));  // Simulating processing delay
    shared_balance = amount;
    std::cout << "Txn " << txn_id << " committed new balance: " << shared_balance << "\n";
}// 🔓 Lock automatically released when function exits

int main() {
    std::thread txn1(read_balance, 1);  // Transaction 1 reads balance
    std::thread txn2(write_balance, 2, 1200);  // Transaction 2 modifies balance
    std::thread txn3(read_balance, 3);  // Transaction 3 reads balance (should see committed data)

    txn1.join();
    txn2.join();
    txn3.join();

    return 0;
}
