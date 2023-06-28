#include <bits/stdc++.h> 
class DisjointSet{
private:
	vector<int> parent;
	vector<int> rank;
	public:
		DisjointSet(int n){
			parent.resize(n+1);
			rank.resize(n+1,0);
			for(int i=0;i<=n;i++){
				parent[i]=i;
			}
		}

		int findParent(int node){
			if(node==parent[node])return node;
			return parent[node]=findParent(parent[node]);
		}

		void unionByRank(int u,int v){
			int pu=findParent(u);
			int pv=findParent(v);
			if(rank[pu]==rank[pv]){
				parent[pv]=pu;
				rank[pu]++;
			}
			else if(rank[pu]>rank[pv]){
				parent[pv]=pu;
			}
			else{
				parent[pu]=pv;
			}
		}
};
bool compare(vector<int> a,vector<int> b){
	return a[2]<b[2];
}
int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	sort(graph.begin(),graph.end(),compare);
	DisjointSet ds(n);
	int sum=0;
	for(auto it: graph){
		int u=it[0];
		int v=it[1];
		int wt=it[2];
		if(ds.findParent(u)!=ds.findParent(v)){
			sum+=wt;
			ds.unionByRank(u,v);
		}
	}
	return sum;

}