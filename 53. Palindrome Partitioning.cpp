#include <bits/stdc++.h> 
bool ispalindrome(int start,int end,string &s){
    while(start<=end){
        if(s[start]!=s[end])return false;
        start++;
        end--;
    }
    return true;
}
void f(int i,string &s,vector<string> &ds,vector<vector<string>> &ans){
    if(i==s.size()){
        ans.push_back(ds);
        return;
    }
    for(int j=i;j<s.size();j++){
        if(ispalindrome(i,j,s)){
            ds.push_back(s.substr(i,j-i+1));
            f(j+1,s,ds,ans);
            ds.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s) 
{
    vector<vector<string>> ans;
    vector<string> ds;
    f(0,s,ds,ans);
    return ans;
}