//https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1#


// Approach --: here we are processing each and every node until we get a node with data equal to any one of the given node,


Node *findLCA(Node *root, int n1, int n2)
{
//step1.)  keep processing each node till the depth of tree until we found either value n1 or n2 
    if (root == NULL)
        return NULL;
    if (root->data == n1)
    {
        return root;
    }
    if (root->data == n2)
        return root;

    Node *left = findLCA(root->left, n1, n2);
    Node *right = findLCA(root->right, n1, n2);

    if (left == NULL && right == NULL)
    {
        return NULL;
    }
    else if (left != NULL && right != NULL)
    //step3.)  If we found both the nodes matched in the left and right variables then we return the current node on which we are sitting
    {
        return root;
    }

    //step2.)  if we found any node with matching values either n1 or n2, we simple return that Node
    else if (left != NULL)
    {
        return left;
    }
    else
        return right;
}