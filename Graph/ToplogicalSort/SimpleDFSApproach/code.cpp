#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void sortedOrder(int node, unordered_map<int,bool> &visited, vector<int> Adj[], stack<int>& sortOrder){

        visited[node] = true;//mark the node visited

        for(auto neighbour:Adj[node]){
            if(!visited[neighbour]){
                sortedOrder(neighbour, visited, Adj, sortOrder);//callling recursive calls for further neighbours 
            }
        }
        
        sortOrder.push(node);//Push the node in stack as no neighbours are left
    
    }
	
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int> sortOrder;//stack LIFO Approach will be used to place all nodes with incoming edges at after the nodes which posses outgoing edges
	    unordered_map<int,bool> visited;
	    
	    for(int i = 0; i < V; i++){
            
            if(visited[i]==false){
                sortedOrder(i, visited, adj, sortOrder);
            }   
	        
	    }
	    
	    vector<int> v;
	    while(!sortOrder.empty()){
	        v.push_back(sortOrder.top());
	        sortOrder.pop();
	    }
	    
	    return v;
	    
	}
};

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends