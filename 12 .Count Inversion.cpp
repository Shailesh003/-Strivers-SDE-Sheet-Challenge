#include <bits/stdc++.h>
long long merge(long long *nums,int l,int mid,int r){
         int cnt = 0;
        int x = mid + 1;
        for(int i=l;i<=mid;i++){
            while(x<=r && nums[i]>nums[x])x++;
            cnt+=x-(mid+1);
        }
        int n1=mid-l+1;
        int n2=r-mid;
        int a[n1],b[n2];
        for(int i=0;i<n1;i++){
            a[i]=nums[l+i];
        }
        for(int i=0;i<n2;i++){
            b[i]=nums[mid+1+i];
        }
        int i=0,j=0,k=l;
        while(i<n1 && j<n2){
            if(a[i]<b[j]){
                nums[k++]=a[i++];
            }
            else{
                nums[k++]=b[j++];
            }
        }
        while(i<n1){
            nums[k++]=a[i++];
        }
        while(j<n2){
            nums[k++]=b[j++];
        }
        return cnt;
    }
long long mergesort(int l,int r,long long *arr){
    if(l<r){
        int mid=(l+r)/2;
        long long inv=mergesort(l,mid,arr);
        inv+=mergesort(mid+1,r,arr);
        inv+=merge(arr,l,mid,r);
        return inv;
    }
    return 0;
} 
long long getInversions(long long *arr, int n){
    return mergesort(0,n-1,arr);
}