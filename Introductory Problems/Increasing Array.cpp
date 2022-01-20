#include<bits/stdc++.h>
using namespace std;
int main(){
    int t=1;
    //cin>>t;
    while(t--)
    {
       long long n,i,x,y,j,mn,ans=0;
       cin>>n;
       int a[n+3];
       for(i=0;i<n;i++) cin>>a[i];
        for(i=1;i<n;i++)
        {
          if(a[i-1]>a[i])
          { ans+=(a[i-1]-a[i]);
           a[i]=a[i-1];
           }
        }
      cout<<ans<<endl;
         
    }
}
