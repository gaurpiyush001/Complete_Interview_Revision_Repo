// https://practice.geeksforgeeks.org/problems/sum-of-middle-elements-of-two-sorted-arrays2305/1?page=1&difficulty[]=1&status[]=unsolved&category[]=Arrays&sortBy=submissions

class Solution {
public:
    /* Function to get middle sum of a sorted array */
    int getMidSum(int *arr, int n) {
        if (n % 2 == 0)
            return (arr[n / 2] + arr[n / 2 - 1]);
        else
            return 2 * arr[n / 2];
    }


    //Starting function call
    int findMidSum(int ar1[], int ar2[], int n) {
        /* return -1 for
        invalid input */
        if (n <= 0) return -1;
        if (n == 1) return (ar1[0] + ar2[0]);
        if (n == 2) return (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]));

        /* get the middle sum of
        the first array */
        int m1 = getMidSum(ar1, n);

        /* get the middle sum of
        the second array */
        int m2 = getMidSum(ar2, n);

        /* If middle sums are equal then
        return either m1 or m2 */
        if (m1 == m2) return m1;

        /* if m1 < m2 then mid sum must
        exist in ar1[m1....] and ar2[....m2] */
        if (m1 < m2) {
            if (n % 2 == 0) return findMidSum(ar1 + n / 2 - 1, ar2, n - n / 2 + 1);
            return findMidSum(ar1 + n / 2, ar2, n - n / 2);
        }

        /* if m1 > m2 then mid sum must
        exist in ar1[....m1] and ar2[m2...] */
        if (n % 2 == 0) return findMidSum(ar2 + n / 2 - 1, ar1, n - n / 2 + 1);
        return findMidSum(ar2 + n / 2, ar1, n - n / 2);
    }
};