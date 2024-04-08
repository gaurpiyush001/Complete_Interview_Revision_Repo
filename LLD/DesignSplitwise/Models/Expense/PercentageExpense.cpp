#include "./../Models/User/User.cpp"
#include "./../Models/Expense/Expense.cpp"

class ExactExpense{
    
    public:
    ExactExpense() {}
    ExactExpense(vector<User> userList, double amount, vector<double> splitRatio): Expense(userList, amount, splitRatio){}

    void splitAmount(int id, vector<User> userList, double amount, vector<double> splitRatio){
        //equal split
        int n = userList.size();

        for(int i = 0 ; i < n ; i++){
            user.getBalanceOwe()
            userList[i].setBalanceOwe(id, splitRatio[i]);
        }

    }
    //list of user, amount total paid, splitFactor
};