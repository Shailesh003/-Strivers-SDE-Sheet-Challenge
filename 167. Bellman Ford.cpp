#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> dist(n+1,1e9);
    dist[src]=0;
    for(int i=1;i<n;i++){
        for(auto it: edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(dist[u]!=1e9 &&wt+dist[u]<dist[v]){
                dist[v]=wt+dist[u];
            }
        }
    }
    //if negative cycle run a loop again
    for(auto it: edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(dist[u]!=1e9 &&wt+dist[u]<dist[v]){
                return -1;
            }
        }
    return dist[dest];
    
}