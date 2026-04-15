
//Good implementaion of recursion

//Pehle question padh jaake: https://practice.geeksforgeeks.org/problems/k-sum-paths/1/#

//Approach ye hai ki, First I will keep adding the node's data to the vector while going down , No when I backtrack and go upward again, at each node I run a reverse loop summimg the element is vector by comparing the sum with K and increasing my count if i get sum equal to K

void solve(Node *root, vector<int> path, int &count, int k)
{

    if (root == NULL)
    {
        return;
    }

    path.push_back(root->data);

    // leftcall
    solve(root->left, path, count, k);
    solve(root->right, path, count, k);

    // check for kSum == k
    int size = path.size() - 1;
    int sum = 0;

    for (int i = size; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
        {
            count++;
        }
    }
}

int sumK(Node *root, int k)
{
    // code here
    int count = 0;
    vector<int> path;
    solve(root, path, count, k);
    return count;
}