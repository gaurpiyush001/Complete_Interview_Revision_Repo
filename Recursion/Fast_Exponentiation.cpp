#include <bits/stdc++.h>
using namespace std;

// Brute force ---> O(power);
// Below Optimized Approach  ->>> O(log(power))

//------------------Logic-: Power should be breaking according to even or odd-----------------------

// if power is even -> power/2 * power/2
// if power is odd --> power * power/2 * power/2
/*
    if ((power & 1) == 0)
    {
        int halfSolution = Solution(base, power / 2);

        return halfSolution * halfSolution;
    }
    else
    {
        power -= 1;
        int halfSolution = Solution(base, power / 2);

        return halfSolution * halfSolution * base;
    }
*/

int Solution(int base, int power)
{

    if (power <= 0)
    {
        return 1;
    }

    int halfSolution = Solution(base, power / 2);

    if (power & 1)
    {
        return halfSolution * halfSolution * base;
    }
    else
    {
        return halfSolution * halfSolution;
    }
}

int main()
{
    int power;
    cin >> power;

    int base;
    cin >> base;

    cout << Solution(base, power) << endl;
    return 0;
}