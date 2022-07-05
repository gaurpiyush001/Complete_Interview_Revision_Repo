#define MOD 1000000007
#define ll long long int
#include <bits/stdc++.h>
using namespace std;

ll add(int a, int b)
{
    return (a % MOD + b % MOD) % MOD;
}

ll mul(int a, int b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}

/*----------RECURSIVE SOLUTIION
ll solve(ll post, ll color)
{

    if (post == 1)
    {
        return color;
    }
    else if (post == 2)
    {
        return add(color,mul(color, color - 1));
    }

    ll ans = add(mul(solve(post - 2, color), color - 1), mul(solve(post - 1, color), color - 1));

    return ans;
}
*/

ll topDown(ll post, ll color, vector<ll>& v){


    if (post == 1)
    {
        return color;
    }
    else if (post == 2)
    {
        return add(color,mul(color, color - 1));
    }

    if(v[post]!=-1)
    return v[post];

    v[post] = add(mul(topDown(post - 2, color, v), color - 1), mul(topDown(post - 1, color, v), color - 1));

    return v[post];


}

/////-------Bottom-Up--------
ll BottomUp(ll post, ll color){
    vector<ll>& v(post+1, 0);

    // v[0] = 0;
    v[1] = color;
    v[2] = add(color,mul(color, color - 1));

    for(int i = 3; i <= post; i++){
        v[i] = add(mul(v[i-2], color-1), mul(v[i-1], color-1));
    }

    return v[n];
}


////------space optimization bhi hojayega , baad m likhunga

int main()
{
    ll post;
    cin >> post;
    ll k;
    cin >> k;
    vector<ll> v(post+1, -1);
    // cout << solve(post, k, v) << endl;
    cout << topDown (post, k, v) << endl;
    return 0;
}