#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    //---> cin and getline

    //Kya seekha isse??

    //Working of cin --> it ignores the spaces and endline character and starts taking input when a integer or character is typed by user

    //getline kya krta haiu?? --> bhai ye vhi se input lena chaalu krjayega jaha currently cursor present hoga. and its end taking input form user until \n or enter is typed by user.


    //cin.ignore kya krta hai??It just shifts the cursor to next line, to take proper inputs from the user and get rid of the falsy behavious of getline  


    int t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin, s);
        cout << s << endl;
    }


    //local max array size cannot exceed 10^5
    //beyond this size compiler will give segmentation fault


    //global declared array can have maximum size of 10^7 

    return 0;
}