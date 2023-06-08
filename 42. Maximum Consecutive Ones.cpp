int longestSubSeg(vector<int> &arr , int n, int k){
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            k--;
        }
        if(k<0 && arr[j++]==0){
            k++;
        }
    }
    return n-j;
}
