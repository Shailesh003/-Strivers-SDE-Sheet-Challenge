#include<bits/stdc++.h>
// int f(int i,int prev,int n,int arr[],vector<vector<int>> &dp){
//     if(i>=n|| prev>=n)return 0;
//     if(i==n-1){
//         if(arr[i]>arr[prev]){
//             return 1;
//         }
//         return 0;
//     }
//     if(dp[i][prev+1]!=-1)return dp[i][prev+1];
//     int nottake=f(i+1,prev,n,arr,dp);
//     int take=0;
//     if(prev==-1 || arr[i]>arr[prev]){
//         take=1+f(i+1,i,n,arr,dp);
//     }
//     return dp[i][prev+1]=max(take,nottake);
// }
// int longestIncreasingSubsequence(int arr[], int n)
// {  
//     vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
//     return f(0,-1,n,arr,dp);
// }
int longestIncreasingSubsequence(int arr[], int n)
{  
    vector<int> ans;
    ans.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]>ans.back())ans.push_back(arr[i]);
        else{
            int idx=lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
            ans[idx]=arr[i];
        }
    }
    return ans.size();
}
