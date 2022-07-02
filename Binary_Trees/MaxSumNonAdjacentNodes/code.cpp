// https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1/

// Pehle read the problem statement, 

pair<int, int> solve(Node *root)
{

    if (root == NULL)
    {
        return {0, 0};
    }

    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    pair<int, int> ans;

    int inclusionLeft = left.first;
    int inclusionRight = right.first;
    int exclusionLeft = left.second;
    int exclusionRight = right.second;

    // Now If I EXCLUDE the current node,
    // then I make use of SUM of (max of both left values) and (max of both right values)
    ans.second = max(exclusionLeft, inclusionLeft) + max(exclusionRight, inclusionRight);

    // Now If I include the current node then I have to INCLUDE the current node,
    // then I make use of exclusion values
    ans.first = exclusionLeft + exclusionRight + root->data;

    return ans;
}
int getMaxSum(Node *root)
{
    // Add your code here
    pair<int, int> ans = solve(root);

    return max(ans.first, ans.second);
}