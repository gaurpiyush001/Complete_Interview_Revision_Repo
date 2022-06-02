#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{
    int low = 0;
    int res = -1;
    auto high = nums.size() - 1;
    // int mid = l + (h - l) / 2;

    while (low <= high)
    {

        int mid = (low + high) >> 1;

        if (nums[mid] == target)
        {
            res = mid;
            break;
        }
        else if (nums[mid] >= nums[low])
        {
            if (nums[low] <= target && nums[mid] >= target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (nums[mid] <= target && nums[high] >= target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return res;
}

int main()
{
    int n, k;
    cin >> k >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << search(nums, k);
    return 0;
}