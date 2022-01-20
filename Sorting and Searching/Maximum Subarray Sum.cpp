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
    ll n,i,x,y,k,s=0,mx=INT_MIN,cur;
    cin>>n;
    ll a[n+3];
    for(i=0;i<n;i++) cin>>a[i];
      cur=a[0];
    for(i=1;i<n;i++)
    {
      cur=max(a[i],cur+a[i]);
      mx=max(cur,mx);
 
    }
    mx=max(mx,cur);
    cout<<mx<<endl;
 
 
  }
}
