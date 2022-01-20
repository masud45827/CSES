#include<bits/stdc++.h>
using namespace std;
typedef     long long    ll;
typedef     unsigned long long    ull;
typedef     vector<int> vi;
typedef     vector<long long> vl;
typedef     pair<int, int>pi;
typedef     pair<long long, long long>pl;
#define F   first
#define S   second
#define pb  push_back
#define     all(x)      x.begin() , x.end()
#define mod 1000000007
#define       FOR(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
vector < pair <ll, ll> > g[100004];
ll n,m;
void fun()
{
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    vector<ll>dis(n+2,1e18);
    q.push({0,1});
    dis[1]=0;
    while(q.size())
    {
        ll di=q.top().F;
        ll nod=q.top().S;
        q.pop();
        if(di!=dis[nod]) continue;
        for(auto p:g[nod])
        {
            if(dis[nod]+p.S<dis[p.F])
            {
                dis[p.F]=dis[nod]+p.S;
                q.push({dis[p.F],p.F});
            }
        }
        
        
    }
   for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
    cout<<endl;
}
int main()
{
  int t = 1, fac = 1;
  //cin >> t;
  while (t--)
  {
    ll i,j,x,y,w;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
       cin>>x>>y>>w;
       g[x].pb({y,w});
      // g[y].pb({x,w});   
    }
    fun();
  }
}
