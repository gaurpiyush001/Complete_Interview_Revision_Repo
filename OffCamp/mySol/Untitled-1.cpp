#include <bits/stdc++.h>
using namespace std;

struct Block
{

    string blockName;
    Block *parent;
    bool isLocked;
    int parentLocked, descendentLocked, userID;
    vector<Block *> childrens;

    Block(string blockName, Block *parent)
    {
        this->blockName = blockName;
        this->parent = parent;
        isLocked = false;
        parentLocked = userID = descendentLocked = 0;
    }
};

// void printTree(){

// }

void build(Block *root, vector<string> nodes, int totalChild)
{

    int st = 1;

    queue<Block *> q;
    q.push(root);

    int start = 1;



    while (!q.empty())
    {

        Block *block = q.front();
        q.pop();

        for (int i = start; i < start + totalChild; i++)
        {

            block->childrens.push_back(new Block(nodes[i], block));
        }

        start += totalChild;

        if (start >= nodes.size())
        {
            break;
        }

        for (auto i : block->childrens)
        {
            q.push(i);
        }
    }
}

void updateDescendant(Block *block, int val)
{

    if (!block)
        return;

    for (auto child : block->childrens)
    {
        child->parentLocked += val;
        updateDescendant(child, val);
    }
}

bool lock(string name, int ID, unordered_map<string, Block *> &mp)
{

    Block *block = mp[name];

    if (block->isLocked || block->parentLocked != 0 || block->descendentLocked != 0)
        return false;

    Block *par = block->parent;

    // acknowledging ancestors
    while (par)
    {
        par->descendentLocked++;
        par = par->parent;
    }

    // showing repsect for ()
    updateDescendant(block, 1);

    block->isLocked = true;
    block->userID = ID;

    return true;
}

bool unlock(string name, int ID, unordered_map<string, Block *> &mp)
{

    Block *block = mp[name];

    if (!block->isLocked)
        return false;
    if (block->isLocked && block->userID != ID)
        return false;

    Block *par = block->parent;
    while (par)
    {
        par->parentLocked--;
        par = par->parent;
    }

    // now inform descendent
    updateDescendant(block, -1);

    block->isLocked = false;

    return true;
}

bool childUserVerification(Block *block, int ID, vector<Block *> &nodes)
{

    if (block->isLocked)
    {
        if (block->userID != ID)
        {
            return false;
        }
        nodes.push_back(block);
    }

    if (block->descendentLocked == 0)
        return true;

    bool final = true;
    for (auto b : block->childrens)
    {

        final = final & childUserVerification(b, ID, nodes);
        if (!final)
            return false;
    }

    return final;
}

bool update(string name, int ID, unordered_map<string, Block *> &mp)
{

    Block *block = mp[name];

    if (block->isLocked)
        return false;
    if (block->parentLocked != 0 || block->descendentLocked == 0)
        return false;

    vector<Block *> nodes;
    if (childUserVerification(block, ID, nodes))
    {
        for (auto p : nodes)
        {
            unlock(p->blockName, ID, mp);
        }
    }
    else
        return false;

    lock(block->blockName, ID, mp);

    return false;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int totalNodes, totalChild, queries;
        cin >> totalNodes >> totalChild >> queries;

        vector<string> nodes(totalNodes);
        for (int i = 0; i < totalNodes; i++)
        {
            cin >> nodes[i];
        }

        Block *root = new Block(nodes[0], NULL);

        // build the complete N-Arry tree with exact totalChild
        build(root, nodes, totalChild);

        unordered_map<string, Block *> mp;

        stack<Block *> st;
        st.push(root);

        while (!st.empty())
        {

            Block *top = st.top();
            st.pop();

            mp[top->blockName] = top;

            for (auto i : top->childrens)
            {
                st.push(i);
            }
        }

        string nodeName;
        int code, Id;

        for (int i = 0; i < queries; i++)
        {

            cin >> code >> nodeName >> Id;

            switch (code)
            {
            // Lock node with ID
            case 1:
                if (lock(nodeName, Id, mp))
                {
                    cout << "True" << endl;
                }
                else
                    cout << "False" << endl;
                break;

            // UnLock node with ID
            case 2:
                if (unlock(nodeName, Id, mp))
                {
                    cout << "True" << endl;
                }
                else
                    cout << "False" << endl;
                break;

            // upgrade node
            case 3:
                if (update(nodeName, Id, mp))
                {
                    cout << "True" << endl;
                }
                else
                    cout << "False" << endl;
                break;
            }
        }
    }
}