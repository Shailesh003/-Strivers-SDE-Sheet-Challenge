#include <bits/stdc++.h> 
bool f(int i,vector<string> &arr,int n,string &target,vector<int> &dp){
    if(i==n)return true;
    if(dp[i]!=-1)return dp[i];
    for (auto word : arr) {
      if (target.substr(i, word.size()) == word &&
          f(i + word.size(), arr, n, target,dp))
        return dp[i]=true;
    }
    return dp[i]=false;
}
bool wordBreak(vector < string > & arr, int n, string & target) {
    vector<int> dp(target.size()+1,-1);
  return f(0,arr,target.size(),target,dp);
}