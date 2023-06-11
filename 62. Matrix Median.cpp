int CountSmallerEqualto(vector<int> nums,int target){
    int low=0,high=nums.size()-1;
    int ans=nums.size();
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>target){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int getMedian(vector<vector<int>> &matrix)
{
   int low=1;
   int high=1e6;
   int n=matrix.size();
   int m=matrix[0].size();
   while(low<=high){
       int mid=(low+high)/2;
       int cnt=0;
       for(int i=0;i<matrix.size();i++){
           cnt+=CountSmallerEqualto(matrix[i],mid);//upper bound
       }
       if(cnt>(n*m)/2){
           high=mid-1;
       }
       else low=mid+1;
   }
   return low;
}