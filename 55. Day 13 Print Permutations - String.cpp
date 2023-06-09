#include <bits/stdc++.h> 
void f(int i,string &s,vector<string> &ans){
    if(i==s.size()){
        ans.push_back(s);
        return;
    }
    for(int j=i;j<s.size();j++){
        swap(s[j],s[i]);
        f(i+1,s,ans);
        swap(s[j],s[i]);
    }
}
vector<string> findPermutations(string &s) {
   vector<string> ans;
   f(0,s,ans);
    return ans;
}