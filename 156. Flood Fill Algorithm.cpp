#include<bits/stdc++.h>
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
  queue<pair<int,int>> q;
  q.push({x,y});
  int n=image.size();
  int m=image[0].size();
  int old=image[x][y];
  vector<vector<int>> ans=image;
  int delrow[]={0,1,0,-1};
  int delcol[]={1,0,-1,0};
  while(!q.empty()){
      pair<int,int> front=q.front();
      q.pop();
      int row=front.first;
      int col=front.second;
      ans[row][col]=newColor;
      for(int i=0;i<4;i++){
          int nrow=row+delrow[i];
          int ncol=col+delcol[i];
          if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==old && ans[nrow][ncol]!=newColor){
              ans[nrow][ncol]=newColor;
              q.push({nrow,ncol});
          }
        }
    }
  return ans;
}