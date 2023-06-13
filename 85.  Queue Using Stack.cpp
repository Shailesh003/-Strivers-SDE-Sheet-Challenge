#include<bits/stdc++.h>
class Queue {
    // Define the data members(if any) here.
    stack<int> input;
    stack<int> output;
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        input.push(val);
    }

    int deQueue() {
        if(input.empty() && output.empty())return -1;
        if(!output.empty()){
            int ans=output.top();
            output.pop();
            return ans;
        }
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        int ans=output.top();
        output.pop();
        return ans;
    }

    int peek() {
        if(input.empty() && output.empty())return -1;
        if(!output.empty()){
            return output.top();
        }
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        return output.top();
    }

    bool isEmpty() {
        return input.empty() && output.empty();
    }
};