#include <bits/stdc++.h> 
class Queue {
public:
    int arr[1000];
    int Front;
    int back;
    int size;
    Queue() {
        Front=-1;
        back=-1;

    }


    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
       if(Front==-1|| Front>back)return true;
       return false;
    }

    void enqueue(int data) {
        back++;
        arr[back]=data;
        if(Front==-1){
            Front++;
        }
    }

    int dequeue() {
        if(Front==-1|| Front>back)return -1;
        int ans=arr[Front];
        Front++;
        return ans;
    }

    int front() {
        if(Front==-1 ||Front>back)return -1;
       return arr[Front];
    }
};