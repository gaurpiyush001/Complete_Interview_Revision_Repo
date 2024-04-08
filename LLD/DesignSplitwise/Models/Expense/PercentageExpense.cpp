// #include "./../User/User.cpp"
//  #include "./Expense.cpp"
 #include <bits/stdc++.h>
using namespace std;
 
 class PercentageExpense: public Expense{
     
     public:
     PercentageExpense() {}
     PercentageExpense(User *user, vector<User*> userList, double amount, vector<double> splitRatio): Expense(user, userList, amount, splitRatio){}
 
     void splitAmount(){
         User *user = this->getUser();
         vector<User*> userList = this->getUserList();
         double amount = this->getAmount();
         //equal split
         int n = userList.size();
         vector<double> splitRatio = this->getSplitFactorList();

        //  for(int i = 0 ; i < n ; i++){
        //      userList[i].setBalanceOwe(user.getId(), round(splitRatio[i]*amount*100)/100);
        //  }

        for (int i = 0; i < n; i++)
        {
            double currentOwe = round(splitRatio[i]*amount*100)/100;
            unordered_map<int,double> mp = user->getBalanceOwe();
            auto amountOwed = mp.find(userList[i]->getId());


            if(amountOwed == mp.end())
                userList[i]->setBalanceOwe(user->getId(), currentOwe);
            else{
                int oldBalance = amountOwed->second;
                if(oldBalance >= currentOwe){
                    //current splitRatio will be let off, and subtract it from oldOwed
                    user->setBalanceOwe(userList[i]->getId(), oldBalance-currentOwe);
                }
                else if(oldBalance < currentOwe){
                    userList[i]->setBalanceOwe(user->getId(), currentOwe-oldBalance);
                }
            }
        }
 
     }
     //list of user, amount total paid, splitFactor
 };