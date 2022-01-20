#include<bits/stdc++.h>
using namespace std;
long long bigmod(long long base,long long power,long long mod)
{
	if(power==0) return 1;
   if(power%2==1)
   {
   	long long a=bigmod(base,power-1,mod)%mod;
     return  ((a%mod)*(base%mod))%mod;
   }else
   {
   	long long  a=bigmod(base,power/2,mod)%mod;
   	return (a%mod*a%mod)%mod;
   }
 
}
int main()
{
	 long long mod,n,i,x;
	 mod=1e9+7;
	 cin>>n;
	 cout<<bigmod(2,n,mod)<<endl;
}
