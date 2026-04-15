#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    int n;
    cin >> n;

    vector<int> prime_factors;

    // i*i <= n, is working because of property ->
    //For every composite number, there is always a prime number less than or equal to its square root.
    
    for(int i = 2; i * i <= n; i++){
        //sbse pehla i jo n ko divide krra hai vo pkka PRIME FACTOR hoga toh usse divide krtey jaao
        while(n%i==0){
            prime_factors.push_back(i);
            n /= i;
        }
    }

    // if left "n" is itself a prime number
    if(n!=1){
        prime_factors.push_back(n);
    }

    cout << " prime factorization ";
    for(auto i : prime_factors){
        cout << i << " ";
    }

    return 0;
}