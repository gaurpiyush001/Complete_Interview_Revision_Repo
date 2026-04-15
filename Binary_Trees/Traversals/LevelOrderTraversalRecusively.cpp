#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

//Here we will write Level Order Code Recursively

//Time Complexoit ---> O(N^2)
//space complexity --> O(N)-->for Call Stack

//acha toh intuition kya hoga???
//mein hrr baari root node se start kru(parent node se) aur fir uss given level pr jaakey recusively saarey nodes tk pahucho (recursive calls mein level decrement krtyey huye)

//heighht function
int getHeight(Node* node){

    if(node==NULL)
    return 0;

    int lheight = getHeight(node->left);
    int rheight = getHeight(node->right);

    if(lheight > rheight)
    return lheight+1;

    else return rheight + 1;


}


void currentLevel(Node* node, int level){
    if(node==NULL)
    return;
    
    if(level==1)
    cout << node->data << endl;

    currentLevel(node->left, level-1);
    currentLevel(node->right, level-1);

}

//Taversing the Tree level wise traverse through level 0 ...to level(getHeight());
void levelWise(Node* node){
    int n = getHeight(node);

    for(int level = 1; level <= n; level++ ){
        currentLevel(node, level);
    } 

}



int main()
{
    
    return 0;
}