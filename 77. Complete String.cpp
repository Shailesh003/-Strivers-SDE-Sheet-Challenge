#include <bits/stdc++.h> 
class Node{
    Node* links[26];
    bool flag;
    public:
    Node(){
        for(int i=0;i<26;i++)links[i]=NULL;
        flag=false;
    }
    void put(char ch,Node* Newnode){
        links[ch-'a']=Newnode;
    }
    bool ContainsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void SetEnd(){
        flag=1;
    }
    int isEnd(){
        return flag;
    }
};
class Trie{
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(string word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->ContainsKey(word[i])){
                Node* temp=new Node();
                node->put(word[i],temp);
            }
            node=node->get(word[i]);
        }
        node->SetEnd();
    }
    bool checkPrefix(string word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->ContainsKey(word[i])){
                node=node->get(word[i]);
                if(node->isEnd()==false)return false;
            } 
            else {
              return false;
            }
        }
        return true;
    }

};
string completeString(int n, vector<string> &a){
    Trie t;
   for(auto it: a){
       t.insert(it);
   }
   string longest="";
   for(auto it: a){
       if(t.checkPrefix(it)){
           if(it.length()>longest.length()){
               longest=it;
           }
           else if(it.length()==longest.length() && it<longest){
               longest=it;
           }
       }
   }
   if(longest=="")return "None";
   return longest;
}