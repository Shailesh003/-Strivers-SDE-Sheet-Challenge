#include <bits/stdc++.h> 
bool AllocationPossible(vector<int> time,int n,long long int mid){
	int stu=1;
	long long int chapter=0;
	for(int i=0;i<time.size();i++){
		if(time[i]>mid)return false;
		if(chapter+time[i]>mid){
			stu++;
			chapter=time[i];
		}
		else{
			chapter+=time[i];
		}
		
	}
	if(stu>n)return false;
	return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long int sum=0;
	sum=accumulate(time.begin(),time.end(),0LL);
	long long int low=0,high=sum;
	long long int res=-1;
	while(low<=high){
		long long int mid=(low+high)/2;
		if(AllocationPossible(time,n,mid)){
			res=mid;
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return low;
}

// 