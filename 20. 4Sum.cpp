#include <bits/stdc++.h>

string fourSum(vector<int> nums, int target, int n) {
    sort(nums.begin(),nums.end());
    int cnt=0;
   for(int i=0;i<n-3;i++){
       for(int j=i+1;j<n-2;j++){
           int l=j+1;
           int r=n-1;
           while(l<r){
               if(nums[i]+nums[j]+nums[l]+nums[r]==target){
                   cnt++;
                   l++;
                   r--;
               }
               else if(nums[i]+nums[j]+nums[l]+nums[r]>target){
                   r--;
               }
               else if(nums[i]+nums[j]+nums[l]+nums[r] < target){
                   l++;
               }
           }
       }
    
   }
    if(cnt==0)return "No";
    return "Yes";
}