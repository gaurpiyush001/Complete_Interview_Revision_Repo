#include <bits/stdc++.h>
using namespace std;

//--Explanation line 23 ki-:
//for ex -: 1 2 3 4 5 6 7 8
//Possible rotation are -:
// 2 3 4 5 6 7 8 | 1 ----> arr[mid] > arr[low] 
// 3 4 5 6 7 8 | 1 2 ----> ...same as above... 
// 4 5 6 7 8 | 1 2 3 ----> ...same as above... 
// 5 6 7 8 | 1 2 3 4 ----> ...same as above... 
// 6 7 8 | 1 2 3 4 5 ----> arr[mid] < arr[low] (IMPORTANT PATTERN FOR APPROACH)
// 7 8 | 1 2 3 4 5 6 ----> ...same as above... 
// 8 | 1 2 3 4 5 6 7 ----> ...same as above... 

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
            if (nums[low] <= target && nums[mid] >= target) //SIMPLE LEFT PART HAI KI NAHI CONDITION HAI
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
            if (nums[mid] <= target && nums[high] >= target) //SIMPLE RIGHT PART HAI KI NAHI CONDITION HAI
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