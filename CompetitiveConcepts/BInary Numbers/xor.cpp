#include <bits/stdc++.h>
using namespace std;

int main()
{

    // 2 same number ka XOR zero hota hai
    //x^x = 0

    // kisi bhi number ka xor zero ke saath same number return krta hai
    //x^0 = x

    int a = 4, b = 6;

    a = a ^ b;
    b = b ^ a;
    //means b ^ (a ^ b) is equal to a

    // XOR operator is associative
    //x ^ y ^ z == x ^ z ^ y == y ^ x ^ z

    a = a ^ b;
    //means (a ^ b) ^ a which is equal to b


    
    return 0;
}