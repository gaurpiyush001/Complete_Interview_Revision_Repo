#include <bits/stdc++.h>
// #include "./../Models/User/User.cpp"
using namespace std;

class UserService{
    public:
    User* createUser(int id, string name, string email, string phone, double expense){
        User *user = new User(id, name, email, phone, expense);
        // cout << "User created!!" << endl;
        return user;
    }
};