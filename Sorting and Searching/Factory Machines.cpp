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
ll a[2000000];
int n;
ll mx=1e18;
ll fun(ll t)
{
  ll s=0;
   for(int i=1;i<=n;i++)
   {
    if(t/a[i]>(mx-s)) return mx;
       s+=(t/a[i]);
   }
   return s;
}
int main()
{
  int t = 1,test=1;
  //cin >> t;
  while (t--)
  {
     ll i,j,l,r,mid,ans,x,k;
     cin>>n>>k;
     for(i=1;i<=n;i++) cin>>a[i];
     l=1;r=1e18;
     while(l<=r)
     {
      mid=(l+r)/2;
        x=fun(mid);
        if(x>=k)
        {
          ans=mid;
          r=mid-1;
        }else l=mid+1;
     }
     cout<<ans<<endl;
  }
}
