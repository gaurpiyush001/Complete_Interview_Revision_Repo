#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    //Number of maximum iterations in 1 sec -: 10^7 to 10^8

    //step1. First estimate the T.C of your code
    //step2. Then check no. of iterations in code via Big Omega......num of iteration should be less than 10^7, then only your code will execute in 1sec.

    /*
    Nature of T.C with respect of iteration
    10^7 -> 1 sec
    10^8 -> 10 sec
    10^9 -> 100 sec
    10^10 -> 1000 sec(15 min)
    10^11 -> 10000 sec
    */

    int n;
    cin >> n;
    int cnt = 0;
    while(n>0){
        n /= 2;
        cnt++;
    }
   
    cout << cnt << endl;//these are total iterations

    //Sum of N overall Testcases is < 10^7
    return 0;
}