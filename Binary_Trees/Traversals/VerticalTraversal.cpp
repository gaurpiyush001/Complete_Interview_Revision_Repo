//Horizontal distance se mapping krlo nodes ki sb hojayega

void levelOrder(Node *root, map<int, vector<int>> &mp)
{

    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {

        pair<Node *, int> p = q.front();
        mp[p.second].push_back((p.first)->data);
        q.pop();

        if ((p.first)->left)
            q.push({(p.first)->left, p.second - 1});
        if ((p.first)->right)
            q.push({(p.first)->right, p.second + 1});
    }
}

vector<int> verticalOrder(Node *root)
{
    // Your code here
    map<int, vector<int>> mp;
    levelOrder(root, mp);
    vector<int> v;
    for (auto i : mp)
    {
        for (auto x : i.second)
        {
            v.push_back(x);
        }
    }

    return v;
}