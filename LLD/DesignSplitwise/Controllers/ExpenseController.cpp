#include <bits/stdc++.h>
// #include "./../Models/Expense/Expense.cpp"
#include "./../Services/ExpenseService.cpp"
using namespace std;
class ExpenseController{
    private:
    ExpenseService expenseService;
    
    public: 
    double getExpense(User *user){
        return expenseService.getExpense(user);
    } 

    void addExpense(User *user, double amount, vector<User*> userList, string expenseType, vector<double> splitFactorList){
        expenseService.addExpense(user, amount, userList, expenseType, splitFactorList);
    }


};