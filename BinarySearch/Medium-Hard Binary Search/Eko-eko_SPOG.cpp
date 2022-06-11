// Question link -: https://www.spoj.com/problems/EKO/
#include <bits/stdc++.h>
using namespace std;

//----> BRUTE FORCE harr ek tree ko answer assume krke loop lgakey ke dekhlo, maximum height for which we are getting ast least M units of wood cut that is thye answer ----> 0(N^2)

//----> My Approach in O(NlOGN)
/*
step1-: Sort the array
step2-: Take array sum
step3-: run a loop from starting at each index assume that value as answer and find the wood obtained by subtracteing from TOtal sum, highest hieght for which total wood cut obtained sum is at least M will be the anser
---------------->>>>
int Solution(long long int arr[],long long int n,long long int m)
{

    // My Approach O(NLogN)
    sort(arr, arr + n);

    long long int total = 0;
    total = accumulate(arr, arr + n, total);
    // cout << total << endl;
    long long int answer = INT_MIN;
    long long int i;
    for (i = 0; i < n; i++)
    {

        long long int timesToCut = n - 1 - i + 1;
        long long int temp = arr[i];
        if (total - (arr[i] * timesToCut) >= m)
        {
            answer = max(answer, temp);
        }
        else
        {
            break;
        }

        total -= arr[i];
    }
    if (i == n)
        return answer;
    long long int last = answer;
    long long int low = answer;
    long long int high = arr[i];
    total += arr[i-1];
    long long int timesToCut = n-1-(i-1)+1;

    while (low <= high)
    {
        long long int mid = low + (high - low) / 2;
        // cout<<low<<" "<<high<<" "<<"--mid--"<<mid<<endl;
        if(((total-(mid*timesToCut) >= m) && mid==last) || ((total-(mid*(timesToCut-1))-last >= m) && mid>last)){
            answer = max(answer,mid);
            low = mid+1;
        } else if (total-(mid*timesToCut) < m){
            high = mid-1;
        }
    }

    return answer;
}
*/

// little optimized by BinarySearch -> O(Log(max(arr_element))*n)
bool totalWood(long long int arr[],long long int h,long long int n,long long int m)
{
    long long int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > h)
        {
            ans += (arr[i] - h);
        }
    }
    return ans>=m?true:false;
}


long long int Solution(long long int arr[],long long int n,long long int m)
{
    long long int high = *max_element(arr, arr + n);
    // cout<<high<<endl;
    long long int low = 0;
    long long int answer;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (totalWood(arr, mid, n, m))
        {
            answer = mid;
            low = mid + 1;
        }
        else 
        {
            high = mid - 1;
        }
    }
    return answer;
}

int main()
{
    long long int n, m;
    cin >> n >> m;

    long long int arr[n];
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << Solution(arr, n, m) << endl;
    return 0;
}