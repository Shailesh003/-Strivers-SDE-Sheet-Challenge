#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    sort(arr.begin(),arr.end());
    int element=arr[0];
    int cnt=1;
    int maxi=1;
    for(int i=1;i<n;i++){
       if(arr[i]==arr[i-1])continue;
       else if(arr[i-1]+1==arr[i]){
           cnt++;
       }
       else{
           maxi=max(maxi,cnt);
            cnt=1;
       }
    }
   return maxi=max(maxi,cnt);
}