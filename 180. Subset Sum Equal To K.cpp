#include <bits/stdc++.h> 
bool f(int i,vector<int> &arr,int n,int k,vector<vector<int>> &dp){
    if(k==0)return true;
    if(i>=n)return false;
    if(dp[i][k]!=-1)return dp[i][k];
    bool nottake=f(i+1,arr,n,k,dp);
    bool take=false;
    if(k>=arr[i]){
        take=f(i+1,arr,n,k-arr[i],dp);
    }
    return dp[i][k]= take || nottake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
   return f(0,arr,n,k,dp);
}