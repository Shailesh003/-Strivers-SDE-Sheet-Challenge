#include <bits/stdc++.h> 
bool canpossible(vector<int> &positions,int c,int mid){
	int cnt=1;
	int coord=positions[0];
	for(int i=1;i<positions.size();i++){
		if(positions[i]-coord>=mid){
			coord=positions[i];
			cnt++;
		}
		if(cnt==c)return true;
	}
	
	return false;
}

int chessTournament(vector<int> positions , int n ,  int c){
	sort(positions.begin(),positions.end());
	int low=1,high=positions[n-1]-positions[0];
	int res=0;
	while(low<=high){
		int mid=(low+high)/2;
		if(canpossible(positions,c,mid)){
			res=mid;
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
	return res;
}