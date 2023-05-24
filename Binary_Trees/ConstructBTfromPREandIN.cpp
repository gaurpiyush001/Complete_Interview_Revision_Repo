
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& preIndex, int startIn, int endIn){
        
        //Mtlb jb kisi Node ka child hi nhi hai, toh NULL return krdo
        if(startIn>=endIn || preIndex >= preorder.size()){
            return NULL;
        }
        
        //Simultaneously \Update the preorder index, to track which node is next to make ROOT NODE
        preIndex++;
        
        //make root node
        TreeNode* root = new TreeNode(preorder[preIndex]);
        
        //search the taken root node in Inorder Array
        auto findIn = find(inorder.begin(), inorder.begin()+endIn, root->val) - inorder.begin();        
        
        //recurse
        root->left = solve(preorder, inorder, preIndex, startIn, findIn);
        root->right = solve(preorder, inorder, preIndex, findIn+1, endIn);
        
        return root;
        
        
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        //ek preorder se jo root node bnegi uska INDEX track krney k liye 
        int preIndex = -1;

        //This will be the range for searching chosen root node in INORDER, kaha se kaha tk seacrh krna hai(otherwise mujhe toh hrr baari answer miljayega)
        int startIn = 0;
        int endIn = preorder.size();
        
        //return the root
        return solve(preorder, inorder, preIndex, startIn, endIn);
        
    }