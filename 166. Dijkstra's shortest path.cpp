#include <bits/stdc++.h> 
// vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
//     vector<pair<int,int>> adj[vertices];
//     for(int i=0;i<edges;i++){
//         int u=vec[i][0];
//         int v=vec[i][1];
//         int wt=vec[i][2];
//         adj[u].push_back({v,wt});
//         adj[v].push_back({u,wt});
//     }
//     priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>> pq;
//     pq.push({0,source});
//     vector<int> dist(vertices,INT_MAX);
//     dist[source]=0;
//     while(!pq.empty()){
//         int node= pq.top().second;
//         int dis=pq.top().first;
//         pq.pop();
//         for(auto it: adj[node]){
//             int newnode=it.first;
//             int newdist=it.second;
//             if(newdist+dis<dist[newnode]){
//                 dist[newnode]=dis+newdist;
//                 pq.push({dist[newnode],newnode});
//             }
//         }
//     }
//     return dist;

// }
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<pair<int,int>> adj[vertices];
    for(int i=0;i<edges;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int wt=vec[i][2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    set<pair<int,int>> st;
    st.insert({0,source});
    vector<int> dist(vertices,INT_MAX);
    dist[source]=0;
    while(!st.empty()){
        auto i =*(st.begin());
        int node=i.second;
        int dis=i.first;
        st.erase(i);
        for(auto it: adj[node]){
            int newnode=it.first;
            int newdist=it.second;
            if(newdist+dis<dist[newnode]){
                if(dist[newnode]!=INT_MAX)st.erase({dist[newnode],newnode});
                dist[newnode]=dis+newdist;
                st.insert({dist[newnode],newnode});
            }
        }
    }
    return dist;

}
