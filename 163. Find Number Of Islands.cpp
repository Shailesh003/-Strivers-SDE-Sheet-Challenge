void DFS(int row,int col,int** arr,vector<vector<int>> &visited,int n,int m){
   visited[row][col]=1;
   for(int i=-1;i<=1;i++){
      for(int j=-1;j<=1;j++){
         int nrow=row+i;
         int ncol=col+j;
         if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && arr[nrow][ncol]==1
         && !visited[nrow][ncol]){
            DFS(nrow,ncol,arr,visited,n,m);
         }
      }
   }
}
int getTotalIslands(int** arr, int n, int m)
{
   int cnt=0;
   vector<vector<int>> visited(n,vector<int>(m,0));
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         if(!visited[i][j] && arr[i][j]==1){
            DFS(i,j,arr,visited,n,m);
            cnt++;
         }
      }
   }
   return cnt;
}
