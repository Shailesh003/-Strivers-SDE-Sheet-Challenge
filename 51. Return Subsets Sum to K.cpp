void f(int i,int n,int k,vector<int> arr,vector<vector<int>> &ans,int sum,vector<int> ds){
    if(i==n){
        if(sum==k){
        ans.push_back(ds);
    }
        return;
    }
    
    sum+=arr[i];
      ds.push_back(arr[i]);
      f(i + 1, n, k, arr, ans, sum, ds);
      ds.pop_back();
    }
    sum-=arr[i];
     f(i+1,n,k,arr,ans,sum,ds);
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
   vector<vector<int>> ans;
   vector<int> ds;
   f(0,n,k,arr,ans,0,ds);
   return ans;
}