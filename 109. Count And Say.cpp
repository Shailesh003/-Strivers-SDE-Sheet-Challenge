#include <bits/stdc++.h> 
string writeAsYouSpeak(int n) 
{
	if(n==1)return"1";
	if(n==2)return "11";
	string s="11";
	for(int i=3;i<=n;i++){
		int cnt=1;
		s+='@';
		string t="";
		for(int j=1;j<s.length();j++){
			if(s[j-1]!=s[j]){
				t+=to_string(cnt);
				t+=s[j-1];
				cnt=1;
			}
			else cnt++;
		}
		s=t;
	}	
	return s;
}