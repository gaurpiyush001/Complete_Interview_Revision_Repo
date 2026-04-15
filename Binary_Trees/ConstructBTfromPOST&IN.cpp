//tc -: O(Nlogn) agar mapp use krle postiion find krney k liye
//below solution ki O(N^2) kyunki map nhi liya humney, line 23 
class Solution{
    public:
    int findPosition(int in[], int element, int n){
        int index=-1;
        for(int i = 0;i <= n ;i++){
            if(in[i]==element){
                return i;
            }
        }
        return -1;
    }
    
    Node* solve(int in[], int pre[], int& index, int inorderStart, int inorderEnd, int n){
        
        if(index>=n || inorderStart > inorderEnd){
              return NULL; 
        }
        
        int element = pre[index++];//And also incrementing the pointer
        Node* root = new Node(element);
        int position= findPosition(in, element, n);

        root->left = solve(in, pre, index, inorderStart, position-1, n);
        root->right = solve(in, pre, index, position+1, inorderEnd, n);
        
        return root;
    }
    
    
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        //fixing the root
        int preOrderIndex = 0;//MOst Important step, preorder ke liye alag se index lena hai
        
        Node* ans = solve(in, pre, preOrderIndex, 0 , n-1, n);
        return ans;
        
    }
};