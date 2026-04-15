#include <bits/stdc++.h>
using namespace std;

class User {

    private:
    int userId;
    string name;
    string email;
    string phone;
    double userExpenses;
    unordered_map<int, double> balanceOwe;//user, balance

    public:
    User() {}
    User(int Id, string name, string email, string phone, int expense): userId{Id}, name{name}, email{email}, phone{phone}, userExpenses{double(expense)}{}

    double getExpense(){
        return this->userExpenses;
    }

    unordered_map<int,double> getBalanceOwe(){
        return this->balanceOwe;
    }

    void printBalanceOwe(){
        for(auto it = this->balanceOwe.begin(); it!=balanceOwe.end(); it++){
            if( it->second > 0 )
                cout << " USER [" << this->userId << "]" << " PAY TO USER ID " << it->first << " AMOUNT = " << std::fixed << std::setprecision(2) << it->second << endl;
        }
    }

    void setBalanceOwe(int userId, double balance){
        this->balanceOwe[userId] = balance;
    }

    void addExpenses(double amount){
        this->userExpenses = this->userExpenses + amount;
    }

    //getters
    int getId(){
        return this->userId;
    }

    string getName(){
        return this->name;
    }

    string getEmail(){
        return this->email;
    }

    string getPhone(){
        return this->phone;
    }

    // void setOweAmount(int userId, int amount){
    //     if(this->mp.find(userId) != this->mp.end()){
    //         mp[userId] = mp[userId] + amount;
    //     }
    //     else{
    //         mp[userId] = amount;
    //     }
    // }


    // friend ostream &operator<<(ostream &, User &);
};

// ostream &
// operator<<(ostream &output, User &Obj)
// {
//     output << "ID: " << Obj.getId() << endl
//            << "Name: " << Obj.getName() << endl
//            << "Phone: " << Obj.getPhone() << endl
//            << "Email: " << Obj.getEmail() << endl;
//     return output;
// }