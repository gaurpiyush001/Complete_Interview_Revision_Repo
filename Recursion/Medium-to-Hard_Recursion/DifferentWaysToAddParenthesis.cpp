#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/different-ways-to-add-parentheses/submissions/

//Toh logic ye hai mere dost --> ki jab bhi Operator encouter krengey tb operator ka left Part expression hota hai aur Right Part Expression hota hai, toh bhai vo expressions recursive call mein bhejo for different ways to find the answer of that specific expression

// note ye kaam recursion krega mujhe tension lene ki need nhi hai

vector<int> diffWaysToCompute(string str){

    vector<int> v;
    for(int i = 0; i < str.length(); i++){

        if(str[i]>'0' && str[i]<'9'){
            continue;
        }
        else{//yaha operator hai toh break the string here in left part and right part 
            string a = str.substr(0,i);
            string b = str.substr(i+1);

            vector<int> leftPossibleSolution = diffWaysToCompute(a);
            vector<int> rightPossibleSolution = diffWaysToCompute(b);

            //Ab expression ka combined answer nikalna pdega jiss operator se expression ko toda tha
            for(auto x : leftPossibleSolution){
                for(auto y : rightPossibleSolution){
                    if(str[i]=='+')
                    v.push_back(x+y);//just like this vector mein push krtey jaao uss expression ke possible solutions, by adding parenthesis at different places
                    else if(str[i]=='-')
                    v.push_back(x-y);
                    else if('*')
                    v.push_back(x*y);
                }
            }

        }

    }

    //below staement is added to handle the case when there is just a digit in left or right part
    if(v.size()==0)
    v.push_back(stoi(str));

    //return the recursive subSolution of problem
    return v;

}

int main()
{
    string str;
    cin>>str;
    vector<int> answer = diffWaysToCompute(str);
    for(int i = 0 ; i < answer.size(); i++)	{
        cout<<answer[i];
    }
    return 0;
}