#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{       vector<pair<int,int>> adj[n+1];
       for(auto it: g){
           int u=it.first.first;
           int v=it.first.second;
           int wt=it.second;
           adj[u].push_back({v,wt});
           adj[v].push_back({u,wt});
       }
       vector<pair<pair<int, int>, int>> ans;
       int sum=0;
       priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>> pq;
       pq.push({{0,1},-1});
       vector<int> visited(n+1,0);
       while(!pq.empty()){
           int wt=pq.top().first.first;
           int node=pq.top().first.second;
           int parent=pq.top().second;
           pq.pop();
           if(visited[node])continue;
           visited[node]=1;
           if(parent!=-1)ans.push_back({{parent,node},wt});
           sum+=wt;
           for(auto it: adj[node]){
               int edgewt=it.second;
               int adjnode=it.first;
               if(!visited[adjnode]){
                   pq.push({{edgewt,adjnode},node});
               }
           }
       }
       return ans;
}
