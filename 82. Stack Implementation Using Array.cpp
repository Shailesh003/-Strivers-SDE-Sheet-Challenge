#include <bits/stdc++.h> 
// Stack class.
class Stack {
    
public:
    int* arr;
    int size;
    int maxsize;
    Stack(int capacity) {
        arr=new int[capacity];
        size=0;
        maxsize=capacity;
    }

    void push(int num) {
        if(size==maxsize)return;
        int ind=size;
        size++;
        arr[ind]=num;
    }

    int pop() {
        if(size==0)return -1;
        int ans=arr[size-1];
        size--;
        return ans;
    }
    
    int top() {
        if(size==0)return -1;
        return arr[size-1];
    }
    
    int isEmpty() {
        if(size==0)return true;
        return false;
    }
    
    int isFull() {
       if(size==maxsize)return true;
       return false;
    }
    
};