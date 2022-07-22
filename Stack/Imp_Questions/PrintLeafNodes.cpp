//Print Leaf Nodes By given Preorder, without constructing the tree --> https://practice.geeksforgeeks.org/problems/print-leaf-nodes-from-preorder-traversal-of-bst2657/1/?page=1&difficulty[]=1&status[]=unsolved&category[]=Stack&sortBy=submissions#

//Intution aana thoda mishkil tha

//Ek common concept ka use kra ki, when I will be adding nodes in stack, the time when (st.top() < arr[i]) --> this means we had just Traversed the leaf Node..Ishiu point pr processing krni hai

vector<int> leafNodes(int arr[],int N) {
        // code here
        stack<int> s;
        vector<int> ans;

        int leaf=0;
        int prev=0;
        for(int i=0;i<N;i++){
            while(!s.empty() && s.top()<arr[i]){
                leaf++;
                if(leaf==2){ // Why this condition?? because, jb iss loop mein second time iterate krengey then hamesha, leaf==2 pr jo prev ki value hogi that will be a leaf Node 
                    ans.push_back(prev);
                }
                prev = s.top();//Isme meri Leaf Node store hogi
                s.pop();
            }
            leaf=0;
            s.push(arr[i]);
        }
        ans.push_back(s.top());//ye last Leaf Node ko Print krraney ke liye likkha
        return ans;
    }