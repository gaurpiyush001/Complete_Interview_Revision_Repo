#include "./Models/User.cpp"
class UserService{
    public:
    void createUser(int id, string name, string email, string phone){
        User* user = new User(id, name, email, phone);
        cout << "User created!!" <<< endl;
    }
}