#include <bits/stdc++.h>
using namespace std;

//T.C---> O(N), N is no. of nodes/vertices


class Solution {
  public:

    // Function to detect cycle in an undirected graph.  
    bool isCyclicBFS(int node, map<int,bool> &visited, vector<int> adj[], unordered_map<int,int> &parent){
        
        queue<int> q;
        parent[node] = -1;
        visited[node] = 1;
        q.push(node);
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            for(auto neighbour: adj[front]){

                //IMP..-: SIMPLE LOGIC
                //If neighbour of the "front" node is already visited and that neighbour IS NOT EVEN PARENT of that "front" Node ---> CYCLE IS PRESENT, return true 
                if(visited[neighbour]==true && neighbour!=parent[front]){
                    return true;
                }else if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = 1;
                    parent[neighbour] = front;
                }

                //IMP** -> We have to Neglect those nodes, which are visited and their parent is the neighbour Node                
            }
            
        }
        
        return false;
        
    }
    
    
    bool isCycle(int V, vector<int> adj[]) {
        
        //for maintainence check of visited and Non-Visited
        map<int,bool> visited;
        unordered_map<int,int> parent;//for maintaining parent of specific node
        
        //to handle Disconnected component, we need to go through all the vertex Or NODES
        for(int i = 0 ; i < V; i++){
            
            if(visited[i]==false){//If this vertex is Unvisited
                
                bool ans = isCyclicBFS(i, visited, adj, parent);
                
                if(ans==1){//If cycle is found then return true
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
    vector<int> adj[V];//Preparing_Adjacency_List
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution obj;
    bool ans = obj.isCycle(V, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}  // } Driver Code Ends