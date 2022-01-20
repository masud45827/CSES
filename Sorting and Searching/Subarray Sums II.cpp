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
  int t = 1;
  //cin >> t;
  while (t--)
  {
     ll n,i,x,y,s=0,c=0;
    cin>>n>>x;
    ll a[n+4];
    map<ll,ll>m;
    for(i=0;i<n;i++) cin>>a[i];
    for(i=0;i<n;i++)
    {
      s+=a[i];
      if(s==x) c++;
      if(m[s-x]!=0) c+=m[s-x];
      m[s]++;
    }
   cout<<c<<endl;
 
  }
 
}
