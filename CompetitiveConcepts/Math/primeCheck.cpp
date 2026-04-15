#include <bits/stdc++.h>
using namespace std;

//BRUTE FORCE APPROACH --> O(N)
/*
int main()
{
    
    int n;
    cin >> n;

    if(n==1){
        cout << "Not Prime" << endl;
        return 0;
    }

    bool is_prime = true;
    for(int i = 2; i < n; i++){

        if(n % i == 0){
            is_prime = false;
            break;
        }

    }

    cout << is_prime << endl;

    return 0;
}
*/

// Better Aprroach --> Just go till <= Sqrt(n)
//Because sqrt(n) ke baad jitney numbers hai vo pehle waaley divisor ke corresponding hotey hai
