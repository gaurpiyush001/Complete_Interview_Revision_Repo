//In all of the three approaches, a flag variable(leftToRight) will be used 

//Approach 1.) By 2 Stacks

vector<int> zigZagByStacks(Node* root, vector<int> ans){

    //declare two stack, BUT why 2 stacks?? ---> approach ye hai ki ek stack mein starting mein element daaldo aur usse POP OUT krtey jaao, Meanwhile just insert the child nodes onto Other stack(nextLevel) with suitable order by using the help of Flag(leftToRight) and LIFO principle
    stack<Node*> currLevel;
    stack<Node*> nextLevel;

    bool leftToRight = true;

    currLevel.push(root);

    while(!currLevel){

        Node* temp = currLevel.top();
        currLevel.pop();//Mein isshi stack se popOut krta jaaumga and this will help me in knowing when a particular level ends 

        if(temp){//this is because to tackle for NULL nodes at starting
            ans.push_back(temp->data);

            if(leftToRight){//if curreNT TARVERSAL IS LEFT->RIGHT, then push child elements, from left to right --> which we will be suitably proccesed by LIFO principle for correct zigZag way traversal 
                if(temp->left)  nextLevel.push(temp->left);
                if(temp->right) nextLevel.push(temp->right);
            }

            else{
                if(temp->right) nextLevel.push(temp->right);           
                if(temp->left)  nextLevel.push(temp->left);
            }
        
        }

        if(!currLevel.empty()){//When a particular level ends then, just swap the stacks, kyunki mujhe agley level ke liye firse processing krni hai "currLevel" ke liye

            leftToRight = !leftToRight;//just flipping the flag, so as to mark the current order of trversal (left->right or right->left) and depending on this pushing the child elements on nextLevel stack in right order
            swap(currLevel, nextLevel);
        
        }

    }

}




//Approach 2.) Recursively, First we will find the height of tree, and then run a loop through height , which redirect it to a recursive function for finding height
void zigZagTraversalRecursion(Node* root, int height, bool lor, vector<int> &ans){
    // Height = 1 means the tree now has only one node
    if(height <= 1){
        if(root) ans.push_back(root->data);
    }
    // When Height > 1
    else{
        if(lor){
            if(root->left) zigZagTraversalRecursion(root->left, height - 1, lor, ans);
            if(root->right) zigZagTraversalRecursion(root->right, height - 1, lor, ans);
        }
        else{
            if(root->right) zigZagTraversalRecursion(root->right, height - 1, lor, ans);
            if(root->left) zigZagTraversalRecursion(root->left, height - 1, lor, ans);
        }
    }
}

void zidZagStarts(Node* root){
    int height = treeHeight(root);//treeHeight willgive height of tree
    bool lor = true;
    for(int i = 0; i < height; i++){
        zigZagTraversalRecursion(root, height, lor, ans);
        lor = !lor;
    }
    return ans;
}





//Approach 3.) By single queue....ye ek LevelOrder Intutive approach,

void zigZagBySingleQueue(Node* root){

    queue<Node*> q;
    bool lor = true;
    q.push(root);
    vector<int> ans;

    while(!q.empty()){

        //WHY BELOW LINE?? --> intention ye hai ki isse mujhe ek level pe jittey nodes hai usko mein identify kr paao aur unke child nodes ko process kr paao
        int size = q.size();
        vector<int> temp;
        for(int i = 0 ; i <size; i++){
            //queue mein childrens push toh normal tareekey se hi hongey
            Node* poppedEle = q.front();
            q.pop();
            temp.push_back(poppedEle->data);

            if(poppedEle->left){
                q.push(poppedEle->left);
            }
            if(poppedEle->right){
                q.push(poppedEle->right);
            }

        }
        if(lor){//ye game changing step hai zigZagtraversal ke liye, because if LOR flag(LeftToRight) is false, then reverse the temp vector
            reverse(temp.begin(), temp.end());
        }
        lor = !lor;
        for(int i = 0 ; i < temp.size();i++){
            ans.push_back(temp[i]);
        }

    }

    return ans;

}

