#include<bits/stdc++.h>
int solve(int e,int f,vector<vector<int>> &dp){
        if(e==1)return f;
        if(f==1 || f==0)return f;
        if(dp[e][f]!=-1)return dp[e][f];
        int mini=INT_MAX;
        int low=1,high=f;
        while(low<=high){
          int mid=(low+high)/2;
          int down=solve(e - 1,mid-1, dp);
          int up=solve(e, f - mid, dp);
          int maxi = max(up,down);
          if(down<up)low=mid+1;
          else{
              high=mid-1;
          }
          mini = min(mini,1+ maxi);
        }
        return dp[e][f] = mini;
}
int cutLogs(int k, int n)
{
    vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
    return solve(k,n,dp);
}
