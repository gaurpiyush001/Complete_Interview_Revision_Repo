#include <bits/stdc++.h>
using namespace std;
//-----------SEARCH SPACE REDUCTION IN BINARY SEARCH----->

// brute force --> O(l*p)
// where l is number of cooks and p is no. of parathas

// Optimized solution--> Pehle toh yeh mujhe trigger nhi huya ki BINARY SEARCH lgakey OPTITMIZE HO SKTA HAI ye --->sort the rank of cooks
// TOh minimum time nikalna hai toh -> range space km krni hai!!
// mimum time -> 0
// maximum time -> jb highest(first) rank ka cheff hi sarrey parathey bnadey i.e rank_Of_HighestCook*((n*n+1)/2)

bool isPossibleSolution(int arr[], int p, int l, int ans){
     int t = 0;
    int parathaCount = 0;
    int cnt = 0;
    for(int i=0;i<l;i++){
        //for each cook count the pratas
        int c = 0;
        int time = ans;
        int perpratas = arr[i]; // time taken to cook each pratas by ith cook
        while(time > 0){
            time = time - perpratas;
            if( time >= 0){
                c += 1;
                perpratas  += arr[i];
            }
        }
        cnt += c;
        if(cnt >= p)
            return true;
    }

    return false;
}

int Solution(int p, int l, int arr[])
{
    int answer = 0;
    sort(arr, arr + l);
    int low = 0;
    int end = arr[0] * ((p * (p + 1)) / 2);

    while (low <= end)
    {
        int mid = low + (end - low) / 2;

        if (isPossibleSolution(arr, p, l, mid))
        {
            answer = mid;
            end = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int p;
        cin >> p;
        int l;
        cin >> l;
        int arr[l];
        for (int i = 0; i < l; i++)
        {
            cin >> arr[i];
        }
        cout << Solution(p, l, arr) << endl;
    }

    return 0;
}