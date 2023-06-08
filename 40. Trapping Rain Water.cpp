#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
  // long lmax[n];
  // long rmax[n];
  // lmax[0]=arr[0];
  // rmax[n-1]=arr[n-1];
  // for(int i=1;i<n;i++){
  //     lmax[i]=max(lmax[i-1],arr[i]);
  //     rmax[n-i-1]=max(rmax[n-i],arr[n-i-1]);
  // }
  // long ans=0;
  // for(int i=0;i<n;i++){
  //     ans += min(lmax[i], rmax[i]) - arr[i];
  // }
  // return ans;
  //optimal 2 pointer approach
  long lmax=0;
  long rmax=0;
  long ans=0;
  long l=0,r=n-1;
  while(l<r){
    if(arr[l]>=arr[r]){
      if(arr[r]>=rmax)rmax=arr[r];
      else{
        ans+=rmax-arr[r];
      }
      r--;
    }
    else{
      if(arr[l]>=lmax)lmax=arr[l];
      else{
        ans+=lmax-arr[l];
      }
      l++;
    }
  }
   return ans;
}