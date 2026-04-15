int knapsack(<vector<int>& wieght, vector<int>& value, int index, int W){
    
    //base case
    //If there is only one item to steal, then just compare its weight with the knapsack capacity
    if(index == 0){

        if(wieght[index] <= W){
            return value[index];
        }
        else 
        return 0;

    }

    int include = 0;
    if(wieght[index] <= W)
        include = value[index] + solve(wieght, value, index, W-wieght[index]);
    
    int exclude = solve(wieght, value, index-1, W); 

    int ans = max(exclude, include)
    return ans;

}