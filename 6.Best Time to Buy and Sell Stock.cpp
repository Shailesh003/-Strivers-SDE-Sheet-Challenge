#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
   int maxpro=INT_MIN;
   int mini=INT_MAX;
   for(int i=0;i<prices.size();i++){
       mini=min(mini,prices[i]);
       maxpro=max(maxpro,prices[i]-mini);
   }
   return maxpro;
}