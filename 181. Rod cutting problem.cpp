int f(int i,int n,vector<int> &price,vector<vector<int>> &dp){
	if(i==0)return n*price[0];
	if(dp[i][n]!=-1)return dp[i][n];
	int nottake=f(i-1,n,price,dp);
	int take=0;
	int rodlen=i+1;
	if(rodlen<=n){
		take=price[i]+f(i,n-rodlen,price,dp);
	}
	return dp[i][n]=max(take,nottake);
}
int cutRod(vector<int> &price, int n)
{	int N=price.size();
	vector<vector<int>> dp(N,vector<int>(n+1,-1));
	return f(N-1,n,price,dp);
}
