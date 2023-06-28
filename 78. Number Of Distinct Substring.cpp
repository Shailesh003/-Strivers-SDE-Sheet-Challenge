#include <bits/stdc++.h> 
class Node{
    Node* links[26];
    public:
    Node(){
        for(int i=0;i<26;i++){
            links[i]=NULL;
        }
    }
    bool ContainsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node* newNode){
        links[ch-'a']=newNode;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }

};
int distinctSubstring(string &word) {
  int cnt=0;
  Node* root=new Node();
  for(int i=0;i<word.size();i++){
      Node* node=root;
      for(int j=i;j<word.size();j++){
          if(!node->ContainsKey(word[j])){
              cnt++;
              Node* temp=new Node();
              node->put(word[j],temp);
          }
          node=node->get(word[j]);
      }
  }
  return cnt;
}
