#include <bits/stdc++.h> 
// void DFS(int node,vector<int> adj[],vector<int> &visited,stack<int> &st){
//     visited[node]=1;
//     for(int it:adj[node]){
//         if(!visited[it]){
//             DFS(it,adj,visited,st);
//         }
//     }
//     st.push(node);
// }
// vector<int> topologicalSort(vector<vector<int>> &edges, int V, int e)  {
//    vector<int> ans;
//    vector<int> adj[V];
//    for(int i=0;i<edges.size();i++){
//        int u=edges[i][0];
//        int v=edges[i][1];
//        adj[u].push_back(v);
//    }
//    vector<int> visited(V,0);
//    stack<int> st;
//    for(int i=0;i<V;i++){
//        if(!visited[i]){
//            DFS(i,adj,visited,st);
//        }
//    }
 
//    while(!st.empty()){
//         //  cout<<st.top();
//        ans.push_back(st.top());
//        st.pop();
//    }
//    return ans;
// }
vector<int> topologicalSort(vector<vector<int>> &edges, int V, int e)  {
   vector<int> ans;
   vector<int> adj[V];
   vector<int> indeg(V,0);
   for(int i=0;i<edges.size();i++){
       int u=edges[i][0];
       int v=edges[i][1];
       indeg[v]++;
       adj[u].push_back(v);
   }
   queue<int> q;
   for(int i=0;i<V;i++){
       if(indeg[i]==0)q.push(i);
   }
   while(!q.empty()){
       int node=q.front();
       q.pop();
       ans.push_back(node);
       for(int it: adj[node]){
           indeg[it]--;
           if(indeg[it]==0)q.push(it);
       }
   }
   return ans;
}
