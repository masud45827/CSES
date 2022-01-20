#include<bits/stdc++.h>
using namespace std;
typedef     long long    ll;
typedef     unsigned long long   ull;
typedef     vector<int> vi;
typedef     vector<long long> vl;
typedef     pair<int, int>pi;
typedef     pair<long long, long long>pl;
#define F   first
#define S   second
#define pb  push_back
#define     all(x)      x.begin() , x.end()
#define mp  make_pair
#define mod 1000000007
#define       FOR(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
vector<ll>g[200004];
ll distanc[200005],subtre[200005],n;
void dfs(ll node, ll p,ll d){
  subtre[node]=1;
  distanc[1]+=d;
   for(ll u:g[node]){
     if(u==p) continue;
     dfs(u,node,d+1);
     subtre[node]+=subtre[u];
   }
}
void dfs1(ll node,ll p){
   for(ll u:g[node]){
     if(u==p) continue;
     distanc[u]=distanc[node]+n-2*subtre[u];
     dfs1(u,node);
     
   }
}
int main()
{
  int t = 1, fac = 1;
  //cin >> t;
  while (t--)
  {
     ll i,j,x,y;
     cin>>n;
     for(i=1;i<n;i++){
       cin>>x>>y;
       g[x].pb(y);
        g[y].pb(x);
     }
      dfs(1,0,0);
      dfs1(1,0);
      for(i=1;i<=n;i++) cout<<distanc[i]<<" ";
        cout<<endl;
 
  }
  return 0;
}
