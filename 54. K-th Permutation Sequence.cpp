#include<bits/stdc++.h>
// void f(int i,string &s,vector<string> &res){
//   if (i == s.size()) {
//     res.push_back(s);
//     return;
//   }
//   for(int j=i;j<s.size();j++){
//       swap(s[i],s[j]);
//       f(i+1,s,res);
//       swap(s[i],s[j]);
//   }
// }
string kthPermutation(int n, int k) {
//     //brute force
//     string s="";
//     int cnt=1;
//    for(int i=1;i<=n;i++){
//        s+=to_string(cnt);
//        cnt++;
//    }
//    vector<string> ans;
//    f(0,s,ans);
//    sort(ans.begin(),ans.end());
//    return ans[k-1]; 
    vector<int> number;
    int fact=1;
    for(int i=1;i<n;i++){
        fact=fact*i;
        number.push_back(i);
    }
    number.push_back(n);
    k=k-1;
    string ans="";
    while(true){
        ans+=to_string(number[k/fact]);
        number.erase(number.begin()+k/fact);
        if(number.size()==0)break;
        k=k%fact;
        fact=fact/number.size();
    }
    return ans;
    
}
