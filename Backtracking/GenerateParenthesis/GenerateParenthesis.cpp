#include <bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1

//NOTE-: iska recursive tree dekhkr lgta hai ansers repeat nhi hongey isme, YES they are not repeating "vector" se kaam chll jayega

void solveRec(int op, int cl, vector<string>& v, string& output, int counter){

    if(counter < 0){//this handles case of wrong parenthesis matching

        //Pelhi fursat mein backtrack krdo valid answer nhi milega iss raastey pr, yaha mt kr recursive call ke baad krliyo
        // output.pop_back();
        return;

    }

    //yaha neechey waali condition mein answer hoga toh store kr leta hun
    if(op == 0 && cl == 0 && counter == 0){//jb saarey opening aur closing brackets are utilized and counter value is also zero 
        v.push_back(output);//store krlo answer
        return;
    }

    
    if(op!=0){
    output.push_back('(');
    solveRec(op-1, cl, v, output, counter+1);
    output.pop_back();
    }

    if(cl!=0){
    output.push_back(')');
    solveRec(op, cl-1, v, output, counter-1);
    output.pop_back();
    }

}


int main()
{
    int n;
    cin>>n;
    vector<string> v;

    string output = "(";

    solveRec(n-1, n, v, output, 1);

    for(int i = 0 ; i < v.size(); i++)	{
        cout<<v[i]<<endl;
    }

    return 0;
}