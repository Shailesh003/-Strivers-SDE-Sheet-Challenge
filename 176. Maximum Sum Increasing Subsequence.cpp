#include <bits/stdc++.h> 
int f(int i,int prev,vector<int> &rack,vector<vector<int>> &dp){
	if(i==rack.size())return 0;
	if(dp[i][prev+1]!=-1)return dp[i][prev+1];
	int nottake=f(i+1,prev,rack,dp);
	int take=INT_MIN;
	if( prev==-1 || rack[prev]<rack[i]){
		take=rack[i]+f(i+1,i,rack,dp);
	}
	return dp[i][prev+1]=max(take,nottake);
}
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{	vector<vector<int>> dp(n,vector<int>(n,-1));
	return f(0,-1,rack,dp);
}