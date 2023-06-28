#include <bits/stdc++.h> 
bool isPalindrome(int i,int j,string &str){
  while (i <= j) {
    if (str[i++] != str[j--])
      return false;
  }
    return true;
}
int f(int i,int n,string &str,vector<int> &dp){
    if(i==n)return 0;
    if(dp[i]!=-1)return dp[i];
    int mini=INT_MAX;
    for(int j=i;j<n;j++){
        if(isPalindrome(i,j,str)){
            int cost=1+f(j+1,n,str,dp);
            mini=min(mini,cost);
        }
    }
    return dp[i]=mini;
}
int palindromePartitioning(string str) {
  int n=str.size();
  vector<int> dp(n,-1);
  return f(0,n,str,dp)-1;//partinoning after last element
}
