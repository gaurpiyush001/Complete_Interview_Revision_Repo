bool isCyclicDFS(int node, int parent, unordered_map<int,bool> &visited, unordered_map<int,list<int>> Adj[]){

    visited[node] = true;

    for(auto neighbour:Adj[node]){
        if(!visited[neighbour]){
            bool cycle = isCyclicDFS(neighbour, node, visited, Adj);
            if(cycle)
            return true;
        }
        else if(neigbhour!=parent){
            return true;
        }
    }

    return false;

}