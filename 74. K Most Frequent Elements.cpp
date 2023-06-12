#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
   map<int,int> mp;
   for(int i=0;i<n;i++){
       mp[arr[i]]++;
   }
   vector<int> ans;
   priority_queue<pair<int,int>> pq;
   for(auto it:mp){
       pq.push({it.second,it.first});
   }
   while(k--){
       ans.push_back(pq.top().second);
       pq.pop();
   }
   sort(ans.begin(),ans.end());
   return ans;
}