#include <bits/stdc++.h>
using namespace std;

void solveRec(vector<int> &v, map<int, bool> &mp, int n, int &count)
{

    for (int i = 0; i < n; i++)
    {

        if (mp[i] == 0)
        {

            int index = v.size()+1;
            if ((index % (i + 1)) != 0 && ((i + 1) % index) != 0)
            {
                continue;
            }
            v.push_back(i + 1);
            mp[i] = 1;

            solveRec(v, mp, n, count);
            
            if (v.size() == n)
            count++;

            // backtracking
            v.pop_back();
            mp[i] = 0;
        }

    }

}

int main()
{
    int n;
    cin >> n;
    map<int, bool> mp;
    int count = 0;
    vector<int> v;

    solveRec(v, mp, n, count);

    cout << count << endl;

    return 0;
}