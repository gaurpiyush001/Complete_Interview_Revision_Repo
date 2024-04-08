#include <bits/stdc++.h>
using namespace std;
class User {

    private:
    int userId;
    string name;
    string email;
    string phone;
    int userExpenses;
    unordered_map<int, int> balanceOwe;//user, balance

    public:
    User() {}
    User(int Id, string name, string email, string phone, int expense): userId{Id}, name{name}, email{email}, phone{phone}, userExpenses{expense}{}

    int getExpense(){
        return this->userExpenses;
    }

    unordered_map<User,int> getBalanceOwe(){
        return this->balanceOwe;
    }

    void setBalanceOwe(int userId, int balance){
        if(this->balanceOwe.find(userId) == this->balanceOwe.end()){
            this->balanceOwe[userId] = balance
        }
        else{
            this->balanceOwe[userId] = this->balanceOwe[userId] + balance;
        }
    }

    void addExpenses(int amount){
        this->userExpenses += amount;
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

    friend ostream &operator<<(ostream &, User &);
};

ostream &
operator<<(ostream &output, User &Obj)
{
    output << "ID: " << Obj.getId() << endl
           << "Name: " << Obj.getName() << endl
           << "Phone: " << Obj.getPhone() << endl
           << "Email: " << Obj.getEmail() << endl
    return output;
}