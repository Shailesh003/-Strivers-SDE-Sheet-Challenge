#include<bits/stdc++.h>
class LRUCache
{
public:
    class Node{
        public:
        Node* next;
        Node* prev;
        int key;
        int val;
        Node(int key,int val){
            this->key=key;
            this->val=val;
        }
    };
    unordered_map<int,Node*> mp;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int cap;
    
    LRUCache(int capacity)
    {
        head->next=tail;
        tail->prev=head;
        cap=capacity;
    }
    void addNode(Node* temp){
        Node* temp2=head->next;
        head->next=temp;
        temp2->prev=temp;
        temp->prev=head;
        temp->next=temp2;
    }
    void deletenode(Node* delNode){
        Node* delprev=delNode->prev;
        Node* delnext=delNode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    int get(int key)
    {
        if(mp.find(key)!=mp.end()){
            Node* temp=mp[key];
            int ans=mp[key]->val;
            mp.erase(key);
            deletenode(temp);
            addNode(temp);
            mp[key]=head->next;
            return ans;
        }
        return -1;
    }
    

    void put(int key, int value)
    {
        if(mp.find(key)!=mp.end()){
            Node* exisNode=mp[key];
            mp.erase(key);
            deletenode(exisNode);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addNode(new Node(key, value));
        mp[key]=head->next;
        return;
    }
};
