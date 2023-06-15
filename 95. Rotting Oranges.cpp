#include<bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
        vector<vector<int>> visited(n,vector<int>(m,0));
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        int fresh=0;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=2;
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int cnt=0;
        int tm=0;
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            q.pop();
            tm=max(tm,time);
            for(int i=0;i<4;i++){
                int nrow= row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 
                && visited[nrow][ncol]!=2){
                    q.push({{nrow,ncol},time+1});
                    visited[nrow][ncol]=2;
                    cnt++;
                }
            }
        }
        if(cnt==fresh)return tm;
        return -1;
}