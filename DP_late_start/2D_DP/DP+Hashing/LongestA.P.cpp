// Iss function mein backward check krunga longest A.P find krne ke liye
int solve(int startIndex, int diff, int A[])
{

    /*  Iterative solution
        int last = A[startIndex];
        int len = 0;
        for (startIndex = startIndex - 1; startIndex >= 0; startIndex--)
        {

            if (last - A[startIndex] == diff)
            {
                last = A[startIndex];
                len++;
            }
        }

        return len;
    */

    // Recursive Solution
    if (startIndex < 0)
    {
        return 0;
    }

    int ans = 0;
    for (int j = startIndex - 1; j >= 0; j--)
    {

        if (A[startIndex] - A[j] == diff)
        { // yaHA RECURSIVE CALL LGEGI
            ans = max(ans, 1 + solve(j, diff, A));
        }
    }

    return ans;
}

//--------------1D-DP ya 2D-DP ?? Two values are changing, one index and other is Difference --> So it is 2D DP

//Top Down Will GIVE TLE
int solveMem(int startIndex, int diff, int A[], unordered_map<int,int> dp[]){

    if (startIndex < 0)
    {
        return 0;
    }
    //count function just if that key is present in unordered_map or not
    if(dp[startIndex].count(diff)){//iss Index pr aur iss difference ke saath koi length pdi h toh dede

        return dp[startIndex][diff];
    }


    int ans = 0;
    for (int j = startIndex - 1; j >= 0; j--)
    {

        if (A[startIndex] - A[j] == diff)
        { // yaHA RECURSIVE CALL LGEGI
            ans = max(ans, 1 + solveMem(j, diff, A, dp));
        }
    }

    return dp[startIndex][diff] = ans;  

}

//Bottom - Up



int lengthOfLongestAP(int A[], int n)
{
    // code here
    // agar 2 ya 2 se kam numbeer hai array mein ---> then return that only bcz
    /*
    if (n <= 2)
        return n;

    int ans = 0;


    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {

            ans = max(ans, solve(i, A[j] - A[i], A) + 2); // +2 isliye add kra because to inlcude last two selected elements also
        }
    }

    return ans;
    */

   //memoized Code
   /*
    if (n <= 2)
        return n;

    int ans = 0;

    unordered_map<int,int> dp[n+1];//Iska jawaab kha hai tumharey paas?? --> Register dekh

    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {

            ans = max(ans, solve(i, A[j] - A[i], A) + 2); // +2 isliye add kra because to inlcude last two selected elements also
        }

    }

    return ans;
    */


   //Bottom Up

   if(n <= 2){
    return n;
   }
   int ans = 0;

   unordered_map<int,int> dp[n+1];

    // 11 se start krna pdega bcz j 0 se start hoga hamesha
   for(int i = 1; i < n; i++ ){

    for(int j = 0; j < i; j++){

        int diff = A[i] - A[j];

        int cnt = 1;//--> ye kya cheez hai --> abhi tk AP mein kitne element only i

        if( dp[j].count(diff) )
            cnt = dp[j][diff];


        dp[i][diff] = 1 + cnt;
        ans = max(ans, dp[i][diff]);

    }

    return ans;

   }


}