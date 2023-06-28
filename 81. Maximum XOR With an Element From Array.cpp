#include<bits/stdc++.h>
class Node{
        Node* links[2];
        public:
        Node(){
            for(int i=0;i<2;i++)links[i]=NULL;
        }
        bool ContainsKey(int bit){
            return links[bit]!=NULL;
        }
        void put(int bit,Node* newNode){
            links[bit]=newNode;
        }
        Node* get(int bit){
            return links[bit];
        }
    };
    class Trie{
        private:
        Node* root;
        public:
        Trie(){
            root=new Node();
        }
        void insert(int num){
            Node* node=root;
            for(int i=31;i>=0;i--){
                int bit =(num>>i)&1;
                if(!node->ContainsKey(bit)){
                    Node* temp=new Node();
                    node->put(bit,temp);
                }
                node=node->get(bit);
            }
        }
        int getMax(int num){
            Node* node=root;
            int maxi=0;
            for(int i=31;i>=0;i--){
                int bit=((num>>i)&1);
                if(node->ContainsKey(!bit)){
                    maxi=maxi|(1<<i);
                    node=node->get(!bit);
                }
                else{
                    node=node->get(bit);
                }   
            }
            return maxi;
        }
};
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	int q=queries.size();
	vector<int> ans(q);
	vector<pair<int,pair<int,int>>> Oq;
	for(int i=0;i<q;i++){
		Oq.push_back({queries[i][1],{queries[i][0],i}});
	}
	sort(Oq.begin(),Oq.end());
	sort(arr.begin(),arr.end());
	Trie t;
	int ind=0;
	int n=arr.size();
	for(int i=0;i<q;i++){
		int ai=Oq[i].first;
		int xi=Oq[i].second.first;
		int qind=Oq[i].second.second;
		while(ind<n && arr[ind]<=ai){
			t.insert(arr[ind]);
			ind++;
		}
		if(ind==0)ans[qind]=-1;
		else{
			ans[qind]=t.getMax(xi);
		}
	}
	return ans;

}