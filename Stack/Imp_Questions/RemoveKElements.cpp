// https://practice.geeksforgeeks.org/problems/remove-k-digits/1/?page=1&difficulty[]=1&status[]=unsolved&category[]=Stack&sortBy=submissions

#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string S, int k)
{

    // If number of deletions given is larger than the length of the string, then return zero
    if (k >= S.length() || S.empty())
    {
        return "0";
    }

    long long int n = S.length();

    stack<char> st;
    // Push first element in the stack
    long long int i = 0;
    st.push(S[i]);

    // increment string index
    i++;

    // Now what is the logic???
    // Core logic is this when i am at particular index for processing that digit, then First I should compare
    // it with the last inserted and processed digit in the container(STACK signifying LIFO).

    // Condition for removing previous proccessed Digit, if st.top() > S[i], then keep popping elemets/digit
    //  from the stack until we false this condition and after that add your new digit

    while (i < n)
    {

        while (!st.empty() && (st.top() > S[i]) && k > 0)
        {
            st.pop();
            k--;
        }

        st.push(S[i]);
        i++;
    }

    while (k > 0)
    {
        st.pop();
        k--;
    }

    string temp = "";
    while (!st.empty())
    {
        char ch = st.top();
        temp.push_back(ch);
        st.pop();
    }

    long long int tempLen = temp.length() - 1;
    while (temp[tempLen] == '0')
    {
        temp.pop_back();
        tempLen--;
    }

    reverse(temp.begin(), temp.end());

    return temp == "" ? "0" : temp;
}

int main()
{

    string S;
    cin >> S;
    int K;
    cin >> K;

    cout << removeKdigits(S, K) << endl;

    return 0;
}
