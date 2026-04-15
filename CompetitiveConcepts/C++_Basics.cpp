#include<bits/stdc++.h>
using namespace std;

int main() {

    //ranges to keep in mind during Overflow

    //  ***ROUGH RANGES***
    //-10^9 < int < 10^9
    //-10^12 < long int < 10^12
    //-10^18 < long long int < 10^18

    int a = 100000;
    int b = 100000;
    int c = a*b;
    // int maxii = INT_MAX+1; ---> this will give compilation error with INTEGER OVERFLOW
    int maxii = INT_MAX;
    cout  << c << " || " << maxii+1/*CYCLE BACK KRJAYEGA OVERFLOW mein*/ << endl; 

    int x = 100000;
    int y = 100000;
    // long int c = x * y; --> this will not give correct result as 10^10 as x and y are both doing calculation as int so will get overflow upto 10^9

    //1LL refers to long long integer,---> this will give correct answer, ye poori calculation ko long long int mein leke jaara hai
    long int ans = x * 1LL * y;

    cout << ans << endl;


    //WHY WE CAN'T USE DOUBLE Datatype to do safe calculations as its range very very high???
    double q = 100000;
    double r = 100000;
    double t = q*r;
    cout << "Double " << fixed/*keyword to get rid of scientific result->10e+7*/ << setprecision(0)/*decimal ke baad ka precision*/ << t <<endl; 

    //But why we should restrict ourself to work within 10^18 long long int range and NOT IN DOUBLE ???
    //**note** Although, We can store very very large numbers in double but WE CANNOT STORE IT ACCURATELY that large number.(never use these decimal datatypes because they have such precision errors, as they store large numbers in cost of accuracy)
    //example
    double test = 10e24;
    cout << fixed << test << endl;//ye correct answer nhi store krega test variable mein


}