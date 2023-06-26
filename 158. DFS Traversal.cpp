void DFS(int node,vector<int> adj[],vector<bool> &visited,vector<int> &dfs){
    visited[node]=1;
    dfs.push_back(node);
    for(auto it: adj[node]){
        if(!visited[it]){
            visited[it]=1;
            DFS(it,adj,visited,dfs);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{   vector<int> adj[V];
    vector<bool> visited(V,0);
   for(int i=0;i<E;i++){
       int u=edges[i][0];
       int v=edges[i][1];
       adj[u].push_back(v);
       adj[v].push_back(u);
   }
   vector<vector<int>> ans;
   for(int i=0;i<V;i++){
       if (!visited[i]) {
        vector<int> dfs;
        DFS(i, adj, visited, dfs);
        ans.push_back(dfs);
       }
       
   }
   return ans;
}