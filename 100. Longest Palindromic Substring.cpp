string longestPalinSubstring(string str)
{  int start=0,end=1;
   for(int i=1;i<str.size()-1;i++){
       int low=i-1;
       int high=i;
       while(low>=0 && high<str.size() && str[low]==str[high]){
           if(high-low+1>end){
               start=low;
               end=high-low+1;
           }
           low--;
           high++;
       }
       low=i-1;
       high=i+1;
       while(low>=0 && high<str.size() && str[low]==str[high]){
           if(high-low+1>end){
               start=low;
               end=high-low+1;
           }
           low--;
           high++;
       }
   }
   string ans="";
   for(int i=start;i<start+end;i++){
       ans+=str[i];
   }
   return ans;
}