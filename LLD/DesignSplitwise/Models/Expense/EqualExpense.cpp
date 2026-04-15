#include <bits/stdc++.h>
// #include "./Expense.cpp"
using namespace std;

class EqualExpense : public Expense
{
public:
    EqualExpense() {}
    EqualExpense(User *user, vector<User*> userList, double amount, vector<double> splitRatio) : Expense(user, userList, amount, splitRatio) {}
    void splitAmount()
    {
        // equal split
        User *user = this->getUser();
        vector<User*> userList = this->getUserList();
        double amount = this->getAmount();
        // equal split
        int n = userList.size();
        vector<double> splitRatio = this->getSplitFactorList();

        double splittedAmount = amount/n;// / 100;
        cout << splittedAmount << endl;
//std::fixed << std::setprecision(2) << (amount / n);
        for (int i = 0; i < n; i++)
        {
            if(userList[i]->getId() == user->getId())
                continue;
            unordered_map<int,double> mp = user->getBalanceOwe();
            auto amountOwed = mp.find(userList[i]->getId());

            if(amountOwed == mp.end()){
                userList[i]->setBalanceOwe(user->getId(), splittedAmount);
            }
            else{
                double oldBalance = amountOwed->second;
                if(oldBalance >= splittedAmount){
                    user->setBalanceOwe(userList[i]->getId(), oldBalance-splittedAmount);
                }
                else if(oldBalance < splittedAmount){
                    userList[i]->setBalanceOwe(user->getId(), splittedAmount-oldBalance);
                }
                
            }
        }
    }
};