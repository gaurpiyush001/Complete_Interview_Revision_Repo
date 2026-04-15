//Note isme brute force mein toh height wala function baar baar caal hota rhega ---> T.C will become O(N^2)

//oPTIMIZED APPROACH MEIN HEIGHT with the recursice call maintain krle toh ---> T.C O(N)


pair<int,bool> solve(TreeNode* root){
    if(root==NULL)
    return {0,true};

    pair<int,bool> leftAns = solve(root->left);
    pair<int,bool> rightAns = solve(root->right);

    int leftHeight = leftAns.first; 
    int rightHeight = rightAns.first;

    //diff
    bool diff = abs( leftAns - rightAns );

    if(leftAns.second && rightAns.second && diff <= 1){
        return { 1 + max(leftHeight, rightHeight), true };
    }
    else{
        return { 1 + max(leftHeight, rightHeight), true };
    }

}