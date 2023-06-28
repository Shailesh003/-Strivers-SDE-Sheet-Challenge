#include<bits/stdc++.h>
int f(int i,int w,vector<int> &weights,vector<int> &values,vector<vector<int>> &dp){
	if(w==0){
		return 0;
	}
	if(i==0){
		if(w>=weights[i])return values[i];
		return 0;
	}
	if(dp[i][w]!=-1)return dp[i][w];
	int nottake=f(i-1,w,weights,values,dp);
	int take=0;
	if(weights[i]<=w){
		take=values[i]+f(i-1,w-weights[i],weights,values,dp);
	}
	return dp[i][w]=max(take,nottake);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{	
	vector<vector<int>> dp(n,vector<int>(w+1,-1));
	return f(n-1,w,weights,values,dp);
}