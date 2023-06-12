#include<bits/stdc++.h>
int signum(int a,int b){
    if(a==b)return 0;
    if(a>b)return 1;
    return -1;
}
void calcMedian(int element,priority_queue<int> &maxHeap,
priority_queue<int,vector<int>,greater<int>> &minHeap,int &median){
   int x= signum(minHeap.size(),maxHeap.size());
   if(x==0){
       if(element>median){
           minHeap.push(element);
           median=minHeap.top();
       }
       else{
           maxHeap.push(element);
           median=maxHeap.top();
       }
   }
   else if(x==1){
       if(element>median){
           maxHeap.push(minHeap.top());
           minHeap.pop();
           minHeap.push(element);
           median=(maxHeap.top()+minHeap.top())/2;
       }
       else{
           maxHeap.push(element);
           median=(maxHeap.top()+minHeap.top())/2;
       }
   }
   else {
       if(element>median){
           minHeap.push(element);
           median=(maxHeap.top()+minHeap.top())/2;
       }
       else{
           minHeap.push(maxHeap.top());
           maxHeap.pop();
           maxHeap.push(element);
           median=(maxHeap.top()+minHeap.top())/2;
       }
   }
}
void findMedian(int *arr, int n)
{   priority_queue<int,vector<int>,greater<int>> minHeap;
    priority_queue<int> maxHeap;
    int median=-1;
    vector<int> ans;
    for(int i=0;i<n;i++){
        calcMedian(arr[i],maxHeap,minHeap,median);
        ans.push_back(median);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}