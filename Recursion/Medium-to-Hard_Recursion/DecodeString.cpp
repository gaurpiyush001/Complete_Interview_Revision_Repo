#include <bits/stdc++.h>
using namespace std;

int index = 0;
string solve(string s){

    //to store curr digit
    int curr = 0;
    string temp = "";

    while(index < s.length()){

        char ch = s[index++];

        if(ch>='0' && ch<='9'){
            curr = curr*10+(ch-'0');
        }
        else if(ch == '['){
            string st = solve(s);
            
            while(curr > 0){
                temp += st;
                curr--; 
            }

            curr = 0;

        }

        else if(ch==']'){
            return temp;
        }

        else{
            temp.push_back(ch);
        }

    }


    return temp;
}


int main()
{
    string s;
    cin>>s;

    cout<< solve(s) << endl;

    return 0;
}