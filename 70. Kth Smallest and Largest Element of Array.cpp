#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// priority_queue<int> pq;
	// priority_queue<int,vector<int>,greater<int>> pq2;
	// vector<int> ans;
	// for(int i=0;i<k;i++){
	// 	pq.push(arr[i]);
	// 	pq2.push(arr[i]);
	// }
	// for(int i=k;i<n;i++){
	// 	if(pq.top()>arr[i]){
	// 		pq.pop();
	// 		pq.push(arr[i]);
	// 	}
	// 	if(pq2.top()<arr[i]){
	// 		pq2.pop();
	// 		pq2.push(arr[i]);
	// 	}
	// }
	// return {pq.top(),pq2.top()};
	sort(arr.begin(),arr.end());
	return {arr[k-1],arr[n-k]};
}