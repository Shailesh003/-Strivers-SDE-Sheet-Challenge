int search(int* arr, int n, int k) {
   int low=0,high=n-1;
   while(low<=high){
       int mid=(low+high)/2;
       if(arr[mid]==k)return mid;
       if(arr[mid]>=arr[low]){
           if(k>=arr[low] && k<=arr[mid]){
               high=mid-1;
           }
           else{
               low=mid+1;
           }
       }
       else{
           if(k>=arr[mid]&& k<=arr[high]){
               low=mid+1;
           }
           else{
               high=mid-1;
           }
       }
   }
   return -1;
}