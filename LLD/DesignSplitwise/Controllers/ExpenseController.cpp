#include "./../Models/Expense/Expense.cpp"
#include "./../Services/ExpenseService.cpp"
class ExpenseController{
    private:
    ExpenseService expenseService;
    
    public: 
    int getExpense(User user){
        return expenseService.getExpense(user);
    } 

    void addExpense(User user, int amount, Expense expenseType){
        expenseService.addExpense(user, amount, expenseType);
    }


}