#include<bits/stdc++.h>
using namespace std;
int main(){
    int t=1;
    //cin>>t;
    while(t--)
    {
      long long i,x,y,n;
      cin>>n;
      if(n==1) cout<<1<<endl;
       else if(n<=3) cout<<"NO SOLUTION"<<endl;
       else if(n==4) cout<<"2 4 1 3"<<endl;
       else 
       {
        for(i=1;i<=n;i+=2) cout<<i<<" ";
         for(i=2;i<=n;i+=2) cout<<i<<" ";
       } 
       cout<<endl;
         
    }
}
