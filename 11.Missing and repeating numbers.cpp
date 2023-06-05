#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	pair<int,int> ans;
	vector<int> freq(n+1,0);
	freq[0]=1;
	for(int i=0;i<n;i++){
		freq[arr[i]]++;
	}
	for(int i=0;i<freq.size();i++){
		if(freq[i]>1)ans.second=i;
		if(freq[i]==0)ans.first=i;
	}
	return ans;
	
}
