#include <bits/stdc++.h>
using namespace std;

int solveRec(int arr[], int index, int sum)
{

    // Base Case
    if (sum == 0)
    {
        return 1;
    }

    // base case
    if (index == 0)
    {

        if (arr[index] == sum)
        {
            return 1;
        }
        else
            return 0;
    }

    int ans1 = 0;
    if (arr[index] <= sum)
    {
        ans1 = solveRec(arr, index - 1, sum - arr[index]);
    }
    int ans2 = solveRec(arr, index - 1, sum);

    return (1+ans1 + ans2) % 1000000007;
}


int perfectSum(int arr[], int n, int sum)
{
    // Your code goes here

    // chll na dhanda hogya kya??itti hi jaan bachi h bs???

    // Solution1-->Recursive_Solution
    return solveRec(arr, n - 1, sum);
}


int main()
{

    int n, sum;

    cin >> n >> sum;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << perfectSum(a, n, sum) << "\n";

    return 0;
}
