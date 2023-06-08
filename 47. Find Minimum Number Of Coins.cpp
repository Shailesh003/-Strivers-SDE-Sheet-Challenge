#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
   int curr[]={1,2,5,10,20,50,100,500,1000};
   int cnt=0;
   int i=8;
   while(amount>0 && i>=0){
       if(amount<curr[i]){
           i--;
           continue;
       }
       cnt++;
       amount-=curr[i];
   }
   return cnt;
}
