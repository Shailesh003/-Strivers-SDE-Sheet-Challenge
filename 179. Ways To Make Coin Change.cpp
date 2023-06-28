#include<bits/stdc++.h>
long f(int i,int target,int *arr,vector<vector<long>> &dp){
    if(target==0)return 1;
    if(i==0){
        if(target %arr[0]==0)return 1;
        return 0;
    }
    if(dp[i][target]!=-1)return dp[i][target];
    long nottake=f(i-1,target,arr,dp);
    long take=0;
    if(target>=arr[i]){
        take=f(i,target-arr[i],arr,dp);
    }
    return dp[i][target]=take+nottake;

}
long countWaysToMakeChange(int *denominations, int n, int value)
{  
  vector<vector<long>> dp(n,vector<long>(value+1,-1));  
  return f(n-1,value,denominations,dp);
}