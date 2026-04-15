//Prime Factors
//https://math.stackexchange.com/questions/63276/is-a-prime-factor-of-a-number-always-less-than-its-square-root

//practice problems
//https://www.geeksforgeeks.org/prime-factor/

// |||| FACTORS AND DIVISORS |||||  
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int countDivisors = 0;
    int sumDivisors = 0;

    //SQRT(N) --> complexity
    for(int i = 1; i*i <= n; i++){
        if(n%i ==0){
            cout << i << " " << n/i << endl;
            countDivisors++;
            sumDivisors++;

            if( n/i != i ){
                sumDivisors += n/i;
                countDivisors ++;
            }

         }
    }
    //--> Ye upper wala method fail hojayega!! Time limit exceded aayega Q queries -> 10^6 * SQRT(N) 

    //Formulae BNANEY ka try krengey, COUNT OF DIVISORS AUR SUM OF DIVISORS KA
    //AUR ISKA jo formulae hai Prime Factorization ke through bnaatey hai
    //Check Register for explanation of formulaes

    cout << countDivisors << " " << sumDivisors << endl;
    return 0;
}


//-----------------> HOW TO FIND PRIME FACTORIZATION of any number

