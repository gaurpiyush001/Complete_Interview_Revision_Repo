#include "./../Models/User/User.cpp"

class Expense{
    private:
    vector<User> userList;
    double amount;
    vector<double> splitRatio;
    
    public:
    Expense() {}
    Expense(vector<User> userList, double amount, vector<double> splitRatio): userList{userList}, amount{amount}, splitRatio{splitRatio}{}

    void splitAmount(int id, vector<User> userList, double amount, vector<double> splitRatio){
        //equal split
        int n = userList.size();
        double splittedAmount = round(float((amount/n))*100) / 100;

        for(int i = 0 ; i < n ; i++){
            userList[i].setBalanceOwe(id, splittedAmount);
        }

    }
    //list of user, amount total paid, splitFactor
};