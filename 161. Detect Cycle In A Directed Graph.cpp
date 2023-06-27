#include<bits/stdc++.h>
// bool DFS(int node,vector<int> adj[],vector<int> &visited,vector<int> &pathVisited){
//   visited[node]=1;
//   pathVisited[node]=1;
//   for(auto it:adj[node]){
//     if(!visited[it]){
//       if(DFS(it,adj,visited,pathVisited))return true;;
//     }
//     else if(pathVisited[it]==1)return true;
//   }
//   pathVisited[node]=0;
//   return false;
// }
// int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
//   vector<int> adj[n+1];
//   vector<int> visited(n+1,0);
//   vector<int> pathVisited(n+1,0);
//   for(int i=0;i<edges.size();i++){
//     int u=edges[i].first;
//     int v=edges[i].second;
//     adj[u].push_back(v);
//   }
//   for(int i=1;i<=n;i++){
//     if (!visited[i]) {
//       if (DFS(i, adj, visited,pathVisited))return true;
//     }
//   }
//   return false;
// }
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  vector<int> adj[n+1];
  vector<int> indeg(n+1,0);
  for(int i=0;i<edges.size();i++){
    int u=edges[i].first;
    int v=edges[i].second;
    indeg[v]++;
    adj[u].push_back(v);
  }
  queue<int> q;
  for(int i=1;i<=n;i++){
    if(indeg[i]==0)q.push(i);
  }
  int cnt=0;
  vector<int> topo;
  while(!q.empty()){
    int node=q.front();
    q.pop();
    // topo.push_back(node);
    cnt++;
    for(int it: adj[node]){
      indeg[it]--;
      if(indeg[it]==0)q.push(it);
    }
  }
  if(cnt!=n)return true;
  return false;
    
}