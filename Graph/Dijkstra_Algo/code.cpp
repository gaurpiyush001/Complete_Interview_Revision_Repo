#include<bits/stdc++.h>
using namespace std;

//Undirected Weighted graph ----> dimpley via set
//Directed Acyclic Graph hai toh --> Topological sort

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        
        vector<int>dist(V); // Distace Vector, which will be the result at the end
        
        for(int i=0;i<V;i++){
            dist[i]=INT_MAX;
        }
        
        //Step1.) Make the source node ditance zero 
        dist[S]=0;
        
        // create a set of distance and node
        set<pair<int,int>>st;//we will be using set Data structure, in order to have the smallest distance node at the beginning  
        
        st.insert({0,S});//insert this source node with distance into the set
        
        while(!st.empty()){
            auto top=*(st.begin());
            
            int topDist=top.first;
            int topNode=top.second;
            
            st.erase(st.begin());
            
            for(auto neighbour : adj[topNode]){//looping through all the neighbours of the topNode
                
                if(topDist + neighbour[1] < dist[neighbour[0]]){//comparing the current distance of the node with the calculated distance
                    //If current Node distance is greater than the calculated distance, then update the smaller distance in the set


                    auto record=st.find({dist[neighbour[0]],neighbour[0]});//here check if the updated node distance is already present in the set data strucutre, If YES then remove it from the set and insert it with the new distance
                    
                    if(record != st.end()){
                        st.erase(record);
                    }
                    
                    dist[neighbour[0]]= topDist + neighbour[1];//updating the minimum distance in distance vector
                
                    st.insert({dist[neighbour[0]],neighbour[0]});//insert into the set
                }
            }
        }
        
        return dist;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends