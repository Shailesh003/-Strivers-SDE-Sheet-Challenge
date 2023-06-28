#include <bits/stdc++.h> 
class Node{
    Node* links[2];
    public:
    Node(){
        links[0]=links[1]=NULL;
    }
    void put(int bit,Node* node){
        links[bit]=node;
    }
    bool ContainsKey(int bit){
        return links[bit]!=NULL;
    }
    Node* get(int bit){
        return links[bit];
    }
};
class Trie{
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!node->ContainsKey(bit)){
                Node* temp=new Node();
                node->put(bit,temp);
            }
            node=node->get(bit);
        }
    }
    int getMax(int num){
        int maxi=0;
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->ContainsKey(!bit)){
                maxi=maxi| (1<<i);
                node=node->get(!bit);
            }
            else{
                node=node->get(bit);
            }

        }
        return maxi;
    }
};
int maximumXor(vector<int> nums)
{   Trie t;
    for(auto it: nums){
        t.insert(it);
    }
    int maxi=0;
    for(auto it: nums){
        maxi=max(maxi,t.getMax(it));
    }
    return maxi;
}