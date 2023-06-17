#include<bits/stdc++.h>
#define d 256
vector<int> stringMatch(string &str, string &pat) {
int m=pat.size();
int n=str.size();
int h=(int)pow(d,m-1);
int hs=0,hp=0;
int q=INT_MAX;
vector<int> ans;
for(int i=0;i<m;i++){
    hp=(d*hp+pat[i])%q;
    hs=(d*hs+str[i])%q;
}
for(int i=0;i<=n-m;i++){
    if(hp=hs){
        int j=0;
        for(;j<m;j++){
            if(str[i+j]!=pat[j])break;
        }
        if(j==m)ans.push_back(i);
    }
    if(i<n-m){
        hs=(d*(hs-str[i]*h)+str[i+m])%q;
        if(hs<0)hs+q;
    }
}
return ans;
}
