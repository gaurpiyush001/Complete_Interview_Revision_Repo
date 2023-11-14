#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int main()
{

    //n bit ka maximum number --> 2ⁿ - 1
    //2 raise to power n --> 1 << n



    // int datatype is able to store 32 bit number 
    cout << INT_MAX << endl;

    //abhi bhi error dega, because 1<<32 ye 33 bit mein pahuch jaye
    // int a = (1<<32) - 1;

    int a = (1LL<<32) - 1;
    //agar int 32 bit ka capable hota hai storage toh vo 31 hi kyu kr paata hai ?
    //still ye upper wala overflow hojayega, because ye signed integer store krta hai
    cout << a << endl;
    a = (1LL<<31) - 1;
    cout << a << endl;

    unsigned b = (1LL<<32) - 1;
    cout << b << endl;


    //fir setting ith bit
    printBinary( a | (1<<i) );

    //ith bit unset
    printBinary( a & (~(1<<i)) );

    //toggle
    printBinary( a ^ (1 << 2) );


    int countBits = 0;
    for(int i = 31; i >= 0 ; i--){
        if( (a & (1<<i)) != 0)
            countBits++;
    }

    //inbuilt function
    cout << __builtin_popcount(a) << endl;//only works for integers

    //sirf 5th bit ko set aur unset krna hota hai lower to upper vica versa khelne mein 

    //uppercase to lowercase
    char B = 'B';
    char b = B | ' ';

    cout << b << endl;


    //lowercase to uppercase
    char d = 'd';
    char D = (d&'_');

    cout << D << endl;

    return 0;
}

void printBinary(int num){

    for(int i = 10; i >= 0; i--){
        cout << ( (num >> i) & 1 );
    }

    cout << endl;

}