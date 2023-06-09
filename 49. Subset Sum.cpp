#include <bits/stdc++.h> 
void f(int i,int n,vector<int> &num,vector<int> &ans,int sum){
  if (i >= n) {
    ans.push_back(sum);
    return;
  }
    f(i+1,n,num,ans,sum+num[i]);
    f(i+1,n,num,ans,sum);
}
vector<int> subsetSum(vector<int> &num)
{
   vector<int> ans;
   f(0,num.size(),num,ans,0);
   sort(ans.begin(),ans.end());
   return ans;
}