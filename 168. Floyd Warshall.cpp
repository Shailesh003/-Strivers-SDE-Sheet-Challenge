int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<vector<int>> cost(n+1,vector<int>(n+1,1e9));
    for(auto it: edges){
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        cost[u][v]=wt;
    }
    for(int i=0;i<=n;i++){
        cost[i][i]=0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
              if (cost[i][k] != 1e9 && cost[k][j] != 1e9) {
                cost[i][j] = min(cost[i][k] + cost[k][j], cost[i][j]);
              }
            }
        }
    }// for negative cycle detection
    for(int i=1;i<=n;i++){
        if(cost[i][i]<0)return -1;
    }
    return cost[src][dest];
}