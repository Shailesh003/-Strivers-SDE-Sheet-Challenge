#include <bits/stdc++.h> 
void bfs(int i,vector<bool> &visited,vector<int> adj[],vector<int> &ans){
   queue<int> q;
   q.push(i);
   visited[i]=true;
   while(!q.empty()){
       int node=q.front();
       q.pop();
       ans.push_back(node);
       for(int it:adj[node]){
           if(!visited[it]){
               q.push(it);
               visited[it]=true;
           }
       }
   }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
   vector<int> adj[vertex];
   for(int i=0;i<edges.size();i++){
       int u=edges[i].first;
       int v=edges[i].second;
       adj[u].push_back(v);
       adj[v].push_back(u);
   }
   for(int i=0;i<vertex;i++){
       sort(adj[i].begin(),adj[i].end());
   }
    vector<int> ans;
    vector<bool> visited(vertex,0);
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(i,visited,adj,ans);
        }
    }
   return ans;
}