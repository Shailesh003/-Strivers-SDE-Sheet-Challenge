#include<bits/stdc++.h>
int zAlgorithm(string s, string p, int n, int m)
{
	vector<int> z;
	int cnt=0;
	string new_string=p+"#"+s;
	for(int i=0;i<new_string.size();i++){
		if(i<=m)continue;
		else{
			int left=0,right=0;
			if(new_string[left]==new_string[i]){
				right=i;
				while(right<new_string.length() && new_string[left]==new_string[right]){
					left++;
					right++;
				}
			}
			z.push_back(left);
		}
	}
	for(int i=0;i<z.size();i++){
		if(z[i]==m)cnt++;
	}
	return cnt;

}