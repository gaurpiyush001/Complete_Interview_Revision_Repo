// Design Spliwise Application

//requirements
/*
User: Each user should have a userId, name, email, mobile number.
Expense: Could either be EQUAL, EXACT or PERCENT
Users can add any amount, select any type of expense and split with any of the available users.
The percent and amount provided could have decimals upto two decimal places.
In case of percent, you need to verify if the total sum of percentage shares is 100 or not.
In case of exact, you need to verify if the total sum of shares is equal to the total amount or not.
The application should have a capability to show expenses for a single user as well as balances for everyone.
When asked to show balances, the application should show balances of a user with all the users where there is a non-zero balance.
The amount should be rounded off to two decimal places. Say if User1 paid 100 and amount is split equally among 3 people. Assign 33.34 to first person and 33.33 to others.
*/

//u1 1000 4 u1 u2 u3 u4 EQUAL
#include <bits/stdc++.h>
#include "./Models/User/User.cpp"
#include "./Controllers/UserController.cpp"
#include "./Controllers/ExpenseController.cpp"
using namespace std;


class Driver{
    public:
    static int main(){
        //so stuff
        UserController *userController = new UserController();

        User *user1 = userController->createUser(1, "Piyush", "gaurpiyush001@gmail.com", "8750672312", double(0));
        User *user2 = userController->createUser(2, "Piyush2", "gaurpiyush001@gmail.com", "8750672312", 0);
        User *user3 = userController->createUser(3, "Piyush3", "gaurpiyush001@gmail.com", "8750672312", 0);
        User *user4 = userController->createUser(4, "Piyush4", "gaurpiyush001@gmail.com", "8750672312", 0);

        cout << "first user ID-> " << user2->getId() << endl;
        cout << "first user ID-> " << user3->getId() << endl;
        cout << "first user ID-> " << user1->getId() << endl;

        ExpenseController *expenseController = new ExpenseController();

        // cout << " user1 expene - "expenseController->getExpense(user1) << endl;

        //User *user, int amount, vector<User*> userList, string expenseType, vector<double> splitFactorList
        expenseController->addExpense(user1, 400.40, {user2, user1, user3, user4}, "EQUAL", {});
        cout << " AFTER EXPENSE of user 1 paid " << expenseController->getExpense(user1) << endl;

        user1->printBalanceOwe();
        user2->printBalanceOwe();
        user3->printBalanceOwe();
        user4->printBalanceOwe();

        cout <<" another expense " <<endl;
        expenseController->addExpense(user2, 400.40, {user1, user2, user3, user4}, "EQUAL", {});
        cout << " AFTER EXPENSE of user 2 paid " << expenseController->getExpense(user2) << endl;

        user1->printBalanceOwe();
        user2->printBalanceOwe();
        user3->printBalanceOwe();
        user4->printBalanceOwe();



        return 0;
    }
};

int main(){
    Driver::main();
    return 0;
}
