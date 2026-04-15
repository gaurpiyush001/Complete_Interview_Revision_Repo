#include <bits/stdc++.h>
using namespace std;

class Graph{

    public:
    map<int, list<int>> mp;//This is the Data Structure for Representing Adjacency List

    //methods
    void addEdges(int u, int v, int direction){

        //where edge goes from u to v
        mp[u].push_back(v);

        //if undirected
        if(direction == 0){
            mp[v].push_back(u);
        }
    }

    void print(){

        for(auto i : mp){
            cout << i.first << " -> " ;
            for(auto x : i.second){
                cout << x << " -> ";
            }
            cout<<endl;
        }

    }

};


int main()
{
    //nodes or Vertices
    int n;
    cin>>n;

    int e;
    cin>>e;//edges

    Graph g;

    for(int i = 0 ; i < e ; i++){
        int u, v;
        cin>>u>>v;//giving input of pair of nodes which are having Edges 

        g.addEdges(u,v,0);

    }

    g.print();
    return 0;
}