#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n)
{	int pre=1;
	int suf=1;
	int maxi=INT_MIN;
	for(int i=0;i<n;i++){
		if(pre==0)pre=1;
		if(suf==0)suf=1;
		pre=pre*arr[i];
		suf=suf*arr[n-1-i];
		maxi=max({maxi,pre,suf});
	}
	return maxi;
}
