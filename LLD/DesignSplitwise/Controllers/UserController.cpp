#include <bits/stdc++.h>
#include "./../Services/UserService.cpp"
// #include "./../Models/User/User.cpp"
using namespace std;
class UserController {
    private:
    UserService userService;
    public: 
    User* createUser(int id, string name, string email, string phone, double expense){
        return userService.createUser(id, name, email, phone, expense);
    } 
};