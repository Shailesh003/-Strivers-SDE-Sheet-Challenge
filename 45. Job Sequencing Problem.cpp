#include <bits/stdc++.h> 
bool cmp(vector<int> a,vector<int> b){
    return a[1]>b[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{
   sort(jobs.begin(),jobs.end(),cmp);
   int profit=0;
   int maxi=0;
   for(int i=0;i<jobs.size();i++){
       maxi=max(maxi,jobs[i][0]);
   }
   vector<int> dead(maxi+1,-1);
   for(int i=0;i<jobs.size();i++){
       int currdead=jobs[i][0];
       int currprofit=jobs[i][1];
       for(int j=currdead;j>0;j--){
           if(dead[j]==-1){
               profit+=currprofit;
               dead[j]=1;
               break;
           }
       }
   }
   return profit;

}
