#include <bits/stdc++.h> 
class Stack {
	// Define the data members.
    queue<int> q;
   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return q.size();
    }

    bool isEmpty() {
        return q.empty();
    }

    void push(int element) {
        int n=q.size();
        q.push(element);
        for(int i=0;i<n;i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if(q.size()==0)return -1;
        int x=q.front();
        q.pop();
        return x;
    }

    int top() {
        if(q.size()==0)return -1;
       return q.front();
    }
};