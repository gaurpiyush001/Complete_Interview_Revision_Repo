#include <bits/stdc++.h>
using namespace std;
// #include "./../User/User.cpp"
 
 // Abstract class , which will derive many class from it implementing our splitting strategy
 class Expense{
     private:
     User *user;
     vector<User*> userList;
     double amount;
     vector<double> splitRatio;
     
     public:
     Expense() {}
     Expense(User *user,vector<User*> userList, double amount, vector<double> splitRatio): user{user}, userList{userList}, amount{amount}, splitRatio{splitRatio}{}
 
     virtual void splitAmount() = 0;
 
     //list of user, amount total paid, splitFactor
     vector<User*> getUserList(){
         return this->userList;
     }

    User* getUser(){
         return this->user;
     }
 
     double getAmount(){
         return this->amount;
     }
 
     vector<double> getSplitFactorList(){
         return this->splitRatio;
     }
 };