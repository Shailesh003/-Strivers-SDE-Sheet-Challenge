#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{   int breakpoint=-1;
    for(int i=n-1;i>0;i--){
        if(permutation[i]>permutation[i-1]){
            breakpoint=i-1;
            break;
        }
    }
    if (breakpoint == -1) {
      reverse(permutation.begin(), permutation.end());
      return permutation;
    }
    for(int i=n-1;i>0;i--){
        if(permutation[i]>permutation[breakpoint]){
            swap(permutation[i],permutation[breakpoint]);
            reverse(permutation.begin()+breakpoint+1,permutation.end());
            return permutation;
        }
    }
   
}