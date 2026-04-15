#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    int checkCycle(int node, unordered_map<int,bool>& visited, vector<int>& dfsVis, vector<int> adj[]){
        
        //firstly mark this Node Visited
        visited[node] = true;
        dfsVis[node] = 1;//marking true in dfsVisited
        
        //loop through all its Neighbours, with the help of Adjacency List
        for(auto neighbour : adj[node]){
            
            if(!visited[neighbour]){
                bool isCycle = checkCycle(neighbour, visited, dfsVis, adj);
                if(isCycle)//checking if cycle ifs their then return TRUE
                    return true;
            } else if(dfsVis[neighbour]==1){//CONDITION for Cycle --> If (dfsVis[vertex]==1 && visited[vertex]==true)
                return true;
            }
            
        }
        
        dfsVis[node] = 0;//Unmarking the dfsVisited array for the particular node, when there are no neighbours left for a Vertex
        return false;
            
    }
    
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        unordered_map<int, bool> visited;
        vector<int> dfsVisited(V,0);
        
        for(int i = 0 ; i < V; i++){
            
            if(!visited[i]){
                
                bool cycle = checkCycle(i, visited, dfsVisited, adj);
                
                if(cycle){
                    return true;
                }
                
            }
        }
        
        return false;
        
    }
};


int main() {

    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    Solution obj;
    cout << obj.isCyclic(V, adj) <<"\n";

    return 0;
}
