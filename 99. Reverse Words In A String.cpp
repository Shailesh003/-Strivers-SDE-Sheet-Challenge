#include<bits/stdc++.h>
string reverseString(string &str){
string ans="";
str+=' ';
stack<string> st;
for(int i=0;i<str.size();i++){
	ans+=str[i];
	if(str[i]==' '){
		st.push(ans);
		ans="";
		while(str[i]==' ')i++;
		i--;
	}
	
	
}
ans="";
while(!st.empty()){
	ans+=st.top();
	st.pop();
	ans+=' ';
}
return ans;
}