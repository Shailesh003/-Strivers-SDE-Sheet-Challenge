#include <bits/stdc++.h> 
// brute force
// int minimumofSizek(vector<int> nums,int k){
//     deque<int> dq;
//     int ans=INT_MIN;
//     for(int i=0;i<nums.size();i++){
//         while(!dq.empty() && i-k==dq.front())dq.pop_front();
//         while(!dq.empty() && nums[dq.back()]>=nums[i]){
//             dq.pop_back();
//         }
//         dq.push_back(i);
//         if(i>=k-1){
//             ans=max(nums[dq.front()],ans);
//         }
//     }
//     return ans;
// }
// vector<int> maxMinWindow(vector<int> a, int n) {
//    vector<int> ans;
//    for(int i=1;i<=n;i++){
//        int res=minimumofSizek(a,i);
//        ans.push_back(res);
//    }
//    return ans;
// }
void NextSmallerElement(vector<int> nums,vector<int> &ans){
    int n=nums.size();
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()]>=nums[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i]=n;
        }
        else{
            ans[i]=st.top();
        }
        st.push(i);
    }
}
void PrevSmallerelemment(vector<int> nums,vector<int> &ans){
    int n=nums.size();
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[st.top()]>=nums[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i]=-1;
        }
        else{
            ans[i]=st.top();
        }
        st.push(i);
    }  
}
vector<int> maxMinWindow(vector<int> a, int n){
    vector<int> nextsmall(n);
    vector<int> prevsmall(n);
    NextSmallerElement(a,nextsmall);
    PrevSmallerelemment(a,prevsmall);
    vector<int> ans(n,INT_MIN);
    for(int i=0;i<n;i++){
        int len=nextsmall[i]-prevsmall[i]-1;
        ans[len-1]=max(ans[len-1],a[i]);
    }
    for (int i = n - 2; i >= 0; i--) {
        ans[i] = max(ans[i], ans[i + 1]);
    }
    return ans;

}