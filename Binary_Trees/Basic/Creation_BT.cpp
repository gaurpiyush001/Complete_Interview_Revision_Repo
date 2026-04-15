#include <bits/stdc++.h>
using namespace std;

//Bhadiya Mja aagya

class node {
    public:
    int data;
    node* left;
    node* right;

//new Node kuch iss prakaar bnegi
    node(int data){
        this->data = data;
        this->left = NULL;//left child NULL hoga 
        this->right = NULL;//right chils NULL hoga
    }
};

node* buildTree(node* root){//Creating tree from PreOrder Traversal

    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    // root->data = data;
    root = new node(data);

    if(data==-1)
    return NULL;

    cout<<"Enter data for inserting in Left of " << data <<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in Right of " << data <<endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);//using this separator, we will print in LevelOrder Traversal
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    while(!q.empty()){
        node* temp  = q.front();

        if(temp==NULL){
            cout<<endl;
            q.pop();
            if(q.empty()==true){//If queue is empty after removing last NULL, then mere dost mtlb sarey levels traverse ho chukey hai
                break;//break from the loop
            }
            q.push(NULL);//because of this line we come to know that, whenever we come to NULL that means all the child of below level have been inserted in queue hence add another NULL for separation

            continue;
        }


        cout<<temp->data<<" ";
        q.pop();

        if(temp->left!=NULL){
            q.push(temp->left);
        } if(temp->right!=NULL)
            q.push(temp->right);
    
    }


}


/////////////////////////////////////////---->NODE_LEFTSUBTREE_RIGHTSUBTREE<----////////////////////////////////////////////////////
void iterativePreorderTraversal(node* root){ 

    //Why stack???
    //kyunki jb mein in depth traverse krunga toh mujhe nodes ke traversing ka record chahiye hoga kyunki right bhi toh jana (jo node last insert huyi uska right subtree process kro ab)--->This will be maintained by LIFO principle    
    stack<node*> st;

    //Why 1??
    //Beacuase dry run mein aisa bhi time aayega jb mera stack khaali hojayega But abhi node saarey processed nhi huye hongey
    while(1){

        while(root){//Kyunki PreOrder mein pehle node print hoti jayegi , aur fir left node mein jata rhega
            cout<<root->data<<" ";
            st.push(root);
            root = root->left;//left 
        }

        //this would be an ideal time toh check whether my stack is EMPTY OR NOT
        //If it is empty then all the nodes have been processed, as just before this we have stack push command on line 86, for a valid node
        if(st.empty()){
            break;
        }

        node* temp = st.top();
        //Ab jb left mein poora proicess hogya toh right mein process krle
        root = temp->right;
        st.pop();//ek baar left subtree nodes process krne ke baad, right node pe aajao tb pop() top node ko

    }

}



//////////////////////////////////------>LEFT_NODE_RIGHT<--------//////////////////////////////////////////
void iterativeInorderTraversal(node* root){

    stack<node*> st;//stack use kr raheyt hai kyunki as we go in depth of tree, so while returning we have to proccess their right SUBTREE also

    while(1){//Why 1???? same reason as above

        //By below while loop we are traversing the entire LEFT subtree of current of particular node 
        while(root){
            st.push(root);
            root = root->left;
        }

        if(st.empty())
        break;

        node* temp = st.top();
        //why below statement?? AT THIS POINT I have traversed the whole left subtree so now I NEED TO PRINT THIS last inserted node in stack
        cout<<temp->data<<" ";
        root = temp->right;
        st.pop();//jab ek baar ek node khud process(print) ho gayi hai aur uska left subtree bhi print hogya hai toh mein usko POP() kr skta hun

    }

}


//////////////////////////////SABSE TRICKY YEHI HAI//////////////////////////////

///////////////////////////////////////------>LEFTSUBTREE_RIGHTSUBTREE_NODE<---------///////////////////////////////////////////
//NOTE---: ISKE AUR BHI APPROACH hai --: https://www.geeksforgeeks.org/iterative-postorder-traversal/
// and  https://www.geeksforgeeks.org/iterative-postorder-traversal-using-stack/
void iterativePostorderTraversal(node* root){

    stack<node*> st;
    node* previous = NULL;

    do{

        while(root){
            st.push(root);
            root = root->left;
        }

        while(!st.empty() && root==NULL){
            root = st.top();
            //WHY below condition??? two consitions --:
            //Condition1.) ek node tb print ho skti jb, mein uska left aur right subtree process kr chuka, toh left subtree toh hum, process krke aagye upper, BUT TO check if RIGHT SUBTREE IS PROCESSED or NOT ---> usme hume previous ka use krna pdega
            //Consition2.) left tree mein process krke aa chuka toh ab agar node ko process krna hai toh uska RIGHT SUBTREEE NULL hona chahiye    
            if(root->right == previous || root->right == NULL){
                cout<<root->data<<" ";
                st.pop();
                previous = root;
                root = NULL;
            }
            else{
                root = root->right;
            }
        }

    }while(!st.empty());

}



int main()
{
    node* root = NULL;
    // node* temp = new node(-1);
    //Build Tree
    root = buildTree(root);//Creation by PreOrderTrversal
    levelOrderTraversal(root);

    cout<< "PREORDER TRAVERSAL -: ";
    iterativePreorderTraversal(root);
    cout<<endl;
    cout<< "INORDER TRAVERSAL -: ";
    iterativeInorderTraversal(root);
    cout<<endl<<"POSTORDER TRAVERSAL -: ";
    iterativePostorderTraversal(root);
    // reverseLevelOrderTraversal(root);

    return 0;
}