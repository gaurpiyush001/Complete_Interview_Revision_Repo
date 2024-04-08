#include "./../Services/UserService.cpp"
class UserController {
    private:
    UserService userService;
    public: 
    void createUser(int id, string name, string email, string phone){
        userService.createUser(id, name, email, phone);
    } 
}