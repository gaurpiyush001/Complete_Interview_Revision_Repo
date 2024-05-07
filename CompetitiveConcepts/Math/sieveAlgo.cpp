#include <bits/stdc++.h>
using namespace std;

//let there Q queries, 1 < Q < 10^7
// for each Q there is a number N, 1 < N < 10^7
//For each query, tell the given number is prime or not 

// So agar mein traditionaly tareeke se krunga sqrt(N)
//then it will give TLE -> 10^7 * sqrt(10^7)
//ye pass nhi hoga 1 second mein

//-------So what is the solution, yaha queries ke loop ke bahar hi saarey compute krney pdengey numbers Upto 10^7 ki prime hai ya nhi?

//Sieve Algo lets us check which are prime numbers and which are not, in  a list of numbers

const int N = 1e7+10;
//10^7 tk ke saarey prime number generate krney hai mujhe

vector<bool> is_prime(n, true);

int main()
{
    isPrime[0] = isPrime[1] = true;


    //iss below construct ki 
    for(int i = 2; i < N; i++){
        
        if(is_prime[i] == true){

            //i ek prime number hai, toh iske saarey multiples ko not prime mark krdena hai

            //ye below multiples ka loop
            //2 ke multiple ke liye(when i is 2) n/2 times chalega

            //3 ke multiple ke liye(when i is 3) n/3 times chalega...so on

            //below will be TC for line 27, if we discard if check
            // n/2 + n/3 + n/4... = nlog(n)

            //but there is if check
            //n/2 + n/3 + n/5 + n/7... = n*log(log(n))

            //we can also start j from i*i...but ye krney ki zyada zarurat nhi
            for(int j = 2*i; j < N; j+=i){
                is_prime[j] = false;
            }

        }

    }

    int q;
    cin >> q;

    // Q*O(1) = 10^7
    while(q--){
        int num;
        cin>>num;


        if(is_prime[num]){
            cout << ' Prime ' <<endl;
        }
        else{
            cout << 'Not Prime ' <<endl;
        }
    }

    

    // is_prime[1] = false;

    // for(int i = 2; i < n ; i++){
    //     int j = i;
    //     if(!is_prime[i]){
    //         continue;
    //     }
    //     int start = 2;
    //     while( j*start <= n ){
    //         is_prime[j*start] = false;
    //         start++;
    //     }
    // }

    // for(int i = 2; i <= n; i++){
    //     cout << i << " " << is_prime[i] << endl;
    // }


    return 0;
}