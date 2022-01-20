#include<bits/stdc++.h>
using  namespace std;
int main()
{
  int n,i,x;
  cin>>n;
  int a[n+2];
  memset(a,0,sizeof(a));
  for(i=1;i<n;i++)
  {
    cin>>x;
    a[x]=1;
  }
  for(i=1;i<=n;i++)
  {
    if(a[i]==0) 
    {
      cout<<i<<endl;
      return 0;
    }
  }
}
