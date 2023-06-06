#include <bits/stdc++.h>
#include<map>
int subarraysXor(vector<int> &arr, int x)
{
    int Xor=0;
    int cnt=0;
    unordered_map<int,int> mp;
    mp[Xor]++;
    for(int i=0;i<arr.size();i++){
        Xor=Xor^arr[i];
        int a=Xor^x;
        cnt+=mp[a];
        mp[Xor]++;
    }
    return cnt;
}