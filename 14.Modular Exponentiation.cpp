#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {

	long ans=1;
	long k=x;
	while(n>0){
		if(n%2!=0){
		   ans=((ans)%m*(k)%m)%m;		
		}
		k=((k)%m*(k)%m)%m;
		n=n/2;
	}
	return (int)(ans%m);

}