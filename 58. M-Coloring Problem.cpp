#include<bits/stdc++.h>
bool isSafe(int node,int col,vector<vector<int>> &matrix,vector<int> &color){
    int n=matrix.size();
    for(int i=0;i<n;i++){
        if(node !=i && matrix[i][node]==1 && color[i]==col)return false;
    }
    return true;
}
bool f(int node,vector<vector<int>> &matrix,vector<int> &color,int m){
    if(node==matrix.size())return true;
    for(int i=1;i<=m;i++){
        if(isSafe(node,i,matrix,color)){
            color[node]=i;
            if(f(node+1,matrix,color,m))return true;
            color[node]=-1;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &matrix, int m) {
    int n=matrix.size();
    vector<int> color(n,-1);
    if(f(0,matrix,color,m))return "YES";
    return "NO";
}