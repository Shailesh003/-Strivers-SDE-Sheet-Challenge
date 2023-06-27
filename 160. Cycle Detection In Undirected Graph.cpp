#include<bits/stdc++.h>
bool cycleDetectBFS(int node,vector<int> adj[],vector<int> &visited){
    queue<pair<int,int>> q;
    q.push({node,-1});
    visited[node]=1;
    while(!q.empty()){
        int Node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(int it:adj[Node]){
            if(!visited[it]){
                visited[it]=1;
                q.push({it,Node});
            }
            else if(visited[it] &&it!=parent)return true;
        }
    }
    return false;
}
bool cycleDetectDFS(int node,int parent,vector<int> adj[],vector<int> &visited){
    visited[node]=1;
    for(auto it: adj[node]){
        if(!visited[it]){
            if(cycleDetectDFS(it, node,adj,visited))return true;;
        }
        else if(it!=parent)return true;
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> visited(n+1,0);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            // if(cycleDetectBFS(i,adj,visited))return "Yes";
            if(cycleDetectDFS(i,-1,adj,visited))return "Yes";
        }
    }
    return "No";
}
