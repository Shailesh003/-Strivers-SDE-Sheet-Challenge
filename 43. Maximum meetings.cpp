#include <bits/stdc++.h> 
bool comp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    if(a.first.second==b.first.second)
      return a.second<b.second;
    return a.first.second<b.first.second;
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
   vector<pair<pair<int,int>,int>> v;
   int n=start.size();
   for(int i=0;i<n;i++){
     v.push_back({{start[i], end[i]}, i + 1});
   }
   sort(v.begin(),v.end(),comp);
   int Mend=v[0].first.second;
   vector<int> ans;
   ans.push_back(v[0].second);
   for(int i=1;i<n;i++){
       if(v[i].first.first>Mend){
           ans.push_back(v[i].second);
           Mend=v[i].first.second;
       }
   }
   return ans;

}