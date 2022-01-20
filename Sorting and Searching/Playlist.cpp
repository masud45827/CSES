#include<bits/stdc++.h>
using namespace std;
typedef     long long    ll;
typedef     vector<int> vi;
typedef     vector<long long> vl;
typedef     pair<int, int>pi;
typedef     pair<long long, long long>pl;
#define F   first
#define S   second
#define pb  push_back
#define     all(x)      x.begin() , x.end()
#define mp  make_pair
#define     REP(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
int main() 
{
 int  t=1;
 //cin>>t;
 while(t--)
 {
  int n,i,j,x=0,c=0,mx=0;
  cin>>n;
  int a[n+2];
  j=0;
  map<int,int>m;
  for(i=1;i<=n;i++)
  {
    cin>>a[i];
  }
  for(i=1;i<=n;i++)
  {
    if(m[a[i]]==0)
    {
      c++;
      m[a[i]]++;
      mx=max(c,mx);
    }else
    {
      while(a[j]!=a[i])
      {
        m[a[j]]=0;
        j++;
      }
      c=(i-j);
      j++;
    }
  }
  mx=max(c,mx);
  cout<<mx<<endl;
 }
}
