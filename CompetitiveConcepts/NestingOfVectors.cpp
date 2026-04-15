#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N = 3;   
    //ARRAY OF VECTORS
    vector<int> v[N];


    for(int i=0; i < N; i++) {

        int n;
        cin>>n;

        for(int j = 0 ; j < n; j++){
            int x;
            cin>>x;
            v[i].push_back(x);
        }

    }

    return 0;
}