#include <bits/stdc++.h>
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.second==b.second)return a.first<b.first;
    return a.second<b.second;
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
   vector<pair<int,int>> v;
   for(int i=0;i<start.size();i++){
       v.push_back({start[i],finish[i]});
   }
   sort(v.begin(),v.end(),cmp);
   int Mend=v[0].second;
   int cnt=1;
   for(int i=1;i<start.size();i++){
       if(v[i].first>=Mend){
           cnt++;
           Mend=v[i].second;
       }
   }
   return cnt;
}