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
#define     rall(x)      x.rbegin() , x.rend()
#define mp  make_pair
#define     REP(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
int main()
{
  int t = 1;
  //cin>>t;
  while (t--)
  {
    ll n, i, x, y, ans, c = 0,l,r,mid,j;
    cin >> n >> x;
    vl a;
    map<ll, ll>m;
    for (i = 0; i < n; i++)
    {
      cin >> y;
      a.pb(y);
    }
    sort(all(a));
    i=0;j=n-1;
    while(i<=j)
    {
      if(i==j)
      {
        c++; break;
      }
      if(a[i]+a[j]<=x) 
      {
        c++; i++; j--;
      }else
      {
        c++;
        j--;
      }
    }
    cout<<c<<endl;
  }
} 
