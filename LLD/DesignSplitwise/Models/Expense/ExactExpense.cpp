#include <bits/stdc++.h>
// #include "./Expense.cpp"
using namespace std;

class ExactExpense: public Expense
{

public:
    ExactExpense() {}
    ExactExpense(User *user, vector<User*> userList, double amount, vector<double> splitRatio) : Expense(user, userList, amount, splitRatio) {}

    void splitAmount()
    {
        User *user = this->getUser();
        vector<User*> userList = this->getUserList();
        double amount = this->getAmount();
        // equal split
        int n = userList.size();
        vector<double> splitRatio = this->getSplitFactorList();

        // if user1 ---> owes ---> user2, then chack what user 2 owe to user1

        // if user1 > user2,
        // user2 ke maaf and then go with user1 remaing - maff od user 2

        // if user2 > user1
        // make user 2 ke bs minus krde , user 1 kuch nhi dega
        for (int i = 0; i < n; i++)
        {
            unordered_map<int,double> mp = user->getBalanceOwe();
            auto amountOwed = mp.find(userList[i]->getId());

            if(amountOwed == mp.end())
                userList[i]->setBalanceOwe(user->getId(), splitRatio[i]);
            else{
                int oldBalance = amountOwed->second;
                if(oldBalance >= splitRatio[i]){
                    //current splitRatio will be let off, and subtract it from oldOwed
                    user->setBalanceOwe(userList[i]->getId(), oldBalance-splitRatio[i]);
                }
                else if(oldBalance < splitRatio[i]){
                    userList[i]->setBalanceOwe(user->getId(), splitRatio[i]-oldBalance);
                }
            }
        }
    }

};