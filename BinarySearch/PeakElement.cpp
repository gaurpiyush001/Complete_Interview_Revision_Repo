#include <bits/stdc++.h>
using namespace std;

int peakIndex(int arr[], int n)
{

    int l = 0, h = n - 1;
    int mid;

    while (l <= h)
    {
        mid = (l + h) >> 1;
        if ((mid == 0 && arr[mid + 1] < arr[mid]) || (mid == n - 1 && arr[mid - 1] < arr[mid]) || (arr[mid + 1] < arr[mid] && arr[mid - 1] < arr[mid]))
        {
            return mid;
        }
        else if (arr[mid] < arr[mid + 1])
        {
            l = mid + 1;
        }
        else
            h = mid - 1;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << peakIndex(arr, n) << endl;

    return 0;
}