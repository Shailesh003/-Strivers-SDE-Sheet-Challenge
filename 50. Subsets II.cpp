#include <bits/stdc++.h>
void f(int i,vector<int> &arr,int n,vector<int> &ds,vector<vector<int>> &ans){
    ans.push_back(ds);
    for(int j=i;j<n;j++){
        if(j!=i && arr[j-1]==arr[j])continue;
        ds.push_back(arr[j]);
        f(j+1,arr,n,ds,ans);
        ds.pop_back();
    }
} 
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{  
   sort(arr.begin(),arr.end());  
   vector<int> ds;
   vector<vector<int>> ans;
   f(0,arr,n,ds,ans);
   return ans; 

}