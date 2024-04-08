#include <bits/stdc++.h>
#include "./../Models/Expense/Expense.cpp"
#include "./../Models/Expense/PercentageExpense.cpp"
#include "./../Models/Expense/ExactExpense.cpp"
#include "./../Models/Expense/EqualExpense.cpp"
// #include './../Models/User/User.cpp'
using namespace std;

class ExpenseService
{

public:
    double getExpense(User *user)
    {
        return user->getExpense();
    }

    // userList, string expenseType, vector<double> splitFactorListt
    void addExpense(User *user, double amount, vector<User*> userList, string expenseType, vector<double> splitFactorList)
    {
        // write the code here for adding the expense for current user, current expenseType strategy
        user->addExpenses(amount); // settingn user expense till this transaction

        // now splitting with expenseType object
        // Expense *expenseObj = NULL;
        if (expenseType == "PERCENTAGE")
        {
            Expense *expenseObj = new PercentageExpense(user, userList, amount, splitFactorList);
            expenseObj->splitAmount();
        }
        else if (expenseType == "EXACT")
        {
            Expense *expenseObj = new ExactExpense(user, userList, amount, splitFactorList);
            expenseObj->splitAmount();
        }
        else if (expenseType == "EQUAL")
        {
            Expense *expenseObj = new EqualExpense(user, userList, amount, splitFactorList);
            expenseObj->splitAmount();
        }
        
        // if(expenseObj!=NULL)
            // expenseObj->splitAmount();
        return;  
    }
};