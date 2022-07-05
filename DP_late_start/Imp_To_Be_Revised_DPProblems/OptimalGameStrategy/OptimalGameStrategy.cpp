#include <bits/stdc++.h>
using namespace std;
///VERY VERY IMPORTANT

//https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1#

/*ye mera solution hai pure recursion, only test case in which it is failing -> 
n = 10
vector = 8 10 20 7 15 15 5 10 9 18
int solveRec(vector<int> v, int i, int j){

    //Base Case
    if(i>j)
        return 0;

    if(((j-i+1) & 1) == 1 ){
        //agar ye length odd hai tb player 2 ki baari hai
        int start = i;
        int end = j;
        // v[i]>v[j]?--start:--end;
        if(v[i]>v[j]){
            start++;
        }else
        end--;
        int ans = solveRec(v, start, end)+0;
        return ans;
    }
    //mujhe corner indices ko hi select krna hai, usme hi choices hongi
    // int add = (arr[i]>arr[j]) ? arr[i]:
    int start = i;
    int end = j;
    if(v[i] > v[j]){
        start++;
    }else
    end--;

    int ans = solveRec(v, start, end) + max(v[i], v[j]);
    if(start==i){
        start++;
        end++;
    }else{
        start--;
        end--;
    }
    int ans2 = solveRec(v, start, end) + min(v[i], v[j]);

    return max(ans, ans2);

}
*/


int solveRec(vector<int> v, int i, int j){

    if(i>j)
    return 0;

    // player1 ke liye bhi 2 choices hai ya toh i uthayega ya j uthayega

    //if player1 picks ith element, then remaining range for player2 turn --> i+1 to j
    int choice1 = v[i] + min(solveRec(v, i+2, j), SolveRec(v, i+1, j-1));//ye recursive calls isliye kyunki 2nd layer aise uthayega ki humare paas minimum bachey

    //if player1 picks jth element, then remaining range for player2 turn --> i to j-1
    int choice2 = v[j] + min(solveRec(v, i, j-2), solveRec(v, i+1, j-1)); 

    int ans = max(choice1, choice2);
    return ans;
}



int main()
{
    int n;
    cin>>n;

    vector<int> v(n);
    for(int i = 0 ; i < n; i++)	{
        cin>>v[i];
    }

    cout<<solveRec(v, 0, n-1)<<endl;
    return 0;
}