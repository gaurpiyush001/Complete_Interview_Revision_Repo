#include <bits/stdc++.h>
using namespace std;

int solution(int n)
{

    if (n == 0)
        return 0;
    long long l = 1, h = n;
    long long mid;
    int res;

    while (l <= h)
    {
        mid = (l + h) >> 1;
        if ((long long)mid * mid == n)
        {
            return mid;
        }
        else if ((long long)mid * mid < n)
        {
            l = mid + 1;
            res = mid;
        }
        else
            h = mid - 1;
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << solution(n) << endl;
    return 0;
}