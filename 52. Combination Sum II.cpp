#include<bits/stdc++.h>
void f(int i,int n,vector<int> &arr,int target,vector<vector<int>> &ans,vector<int>&ds){
	if(target==0){
		ans.push_back(ds);
		return;
	}
	for(int j=i;j<n;j++){
		if(j!=i && arr[j]==arr[j-1])continue;
		if(arr[j]>target)break;
		ds.push_back(arr[j]);
		f(j+1,n,arr,target-arr[j],ans,ds);
		ds.pop_back();
	}
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{	vector<vector<int>> ans;
	sort(arr.begin(),arr.end());
	vector<int> ds;
	f(0,n,arr,target,ans,ds);
	return ans;
}
