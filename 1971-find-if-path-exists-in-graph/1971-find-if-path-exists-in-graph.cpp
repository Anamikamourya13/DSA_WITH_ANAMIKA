class Solution {
public:
       
       bool dfs(int node, int destination, vector<vector<int>>& adj,vector<bool>& visited) {
        
        //destination mil gya h ''
        if (node == destination)
        return true;

        //current node visited
        visited[node]= true;

        //sare neighbours check karo
        for(int neighbour :  adj[node]){

            if(!visited[neighbour]){

                if(dfs(neighbour, destination, adj, visited))

                return true;
            }
        }


      return false;

  }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //adj.list
    vector<vector<int>> adj(n);
    //graph banana
    for(int i =0; i<edges.size();i++){
    
        int u = edges[i][0];
        int v= edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //visited array
    vector<bool> visited(n, false);
    //DFS start
    return dfs(source, destination, adj, visited);
    }
};