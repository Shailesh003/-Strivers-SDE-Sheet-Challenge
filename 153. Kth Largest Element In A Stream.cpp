#include <bits/stdc++.h> 
class Kthlargest {
    priority_queue<int,vector<int>,greater<int>> pq;
    int size;
public:
    Kthlargest(int k, vector<int> &arr) {
        size=k;
       for(auto i: arr){
           pq.push(i);
           if(pq.size()>k)pq.pop();
       }
    }

    void add(int num) {
        pq.push(num);
        if(pq.size()>size)pq.pop();
    }

    int getKthLargest() {
       return pq.top();
    }

};