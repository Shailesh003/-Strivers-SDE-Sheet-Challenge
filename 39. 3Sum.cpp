#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int target) {
	vector<vector<int>> ans;
	sort(arr.begin(),arr.end());
	for(int i=0;i<n-2;i++){
		int j=i+1;
		int k=n-1;
		while(j < k){
			if(arr[i]+arr[j]+arr[k]==target){

				ans.push_back({arr[i],arr[j],arr[k]});
				int lastlow=arr[j],lasthigh=arr[k];
				while(j<k && arr[j]==lastlow)j++;
				while(j<k && arr[k]==lasthigh)k--;
			}
			else if(arr[i]+arr[j]+arr[k]>target){
				k--;
            }
			else{
              j++;
            }
    	}
    }
	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());	
	return ans;
}
