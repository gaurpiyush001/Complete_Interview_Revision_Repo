//***************Modular Arithmetic************************

/*
1. (a+b)%M = ((a%M)+(b%M))%M
2. (a*b)%M = ((a%M)*(b%M))%M
3. (a-b)%M = ((a%M)-(b%M)+M)%M
4. (a/b)%M = ((a%M)*(b-¹)%M)%M
*/

//Why we need modulo expression in progamming??????

//Problem setter ko pta hai tum large number ki factorial value calculate toh krlogey but STORE NHI KRPAAOGEY, then problem setter gives a number to modulo and give answer corresponding to that modular operation.

//why % 10^9+7??
//1. Now we can store answer in int datatype as  answer will not be beyond 10^7
//2. MMI -> Multiplicative Inverse -> 

//In question where answer is too large, a line is given in question
// PRINT ANSWER MODULO M , where M = 47;


/*Applying Modulo properties --> just to understand how is 5! calculating with modulo operation
(1*2*3*4*5)%M
( ((1*2*3*4)%M) * (5%M) ) % M
( ( ( ((1*2*3)%M) * 4%M)%M) * (5%M) ) % M
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int M =47;
    long long fact = 1;
    for(int i = 2; i <= n; ++i){
        fact = (fact*i) % M;
    }
    cout << fact;
    return 0;
}
