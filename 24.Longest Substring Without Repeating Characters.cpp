#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
   vector<int> dict(256,-1);
   int n=input.size();
   int start=-1;
   int maxi=0;
   for(int i=0;i<n;i++){
       if(dict[input[i]]>start){
           start=dict[input[i]];
       }
       dict[input[i]]=i;
       maxi=max(maxi,i-start);
   }
   return maxi;
}