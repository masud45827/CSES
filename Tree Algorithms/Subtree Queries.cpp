#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef  unsigned long long ull;
typedef vector<int>vi;
typedef vector<long long>vl;
typedef pair<int, int>pi;
typedef pair<long long, long long>pl;
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
#define mem(a) memset(a,0,sizeof a)
#define memn(a) memset(a,-1,sizeof a)
#define setpr(x) cout<<setprecision(x)<<fixed
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
const int N = (int) 200005;
vector<ll>g[N+1];
ll st[N+1],ed[N+3];
ll tm1=0;
 void dfs(ll node,ll p){
    st[node]=++tm1;
    for(ll u:g[node]){
       if(p==u) continue;
       dfs(u,node);
    }
    ed[node]=++tm1;
 }
 ll bit[2*N+4];
 void update(ll i,ll x){
     while(i<=2*N){
       bit[i]+=x;
        i+=(i&(-i));
     }
 }
 ll query(ll i){
     ll res=0;
      while(i>0){
         res+=bit[i];
         i-=(i&(-i));
      }
       return res;
 }
int main() {
  //IOS;
  int test = 1, fac = 1;
  //cin>>test;
  while (test--) {
        ll n,i,j,x,y,q;
         cin>>n>>q;
         ll a[n+1];
         for(i=1;i<=n;i++){
          cin>>x;
          a[i]=x;
         }
          for(i=1;i<n;i++){
             cin>>x>>y;
              g[x].pb(y);
              g[y].pb(x);
          }
          dfs(1,0);
           for(i=1;i<=n;i++){
            x=a[i];
           update(ed[i],x);
         }
         while(q--){
           ll t;
           cin>>t;
           if(t==2){
                 ll node;
                 cin>>node;
             ll ans=query(ed[node])-query(st[node]);
             cout<<ans<<endl;
           }else{
             ll node,val;
                 cin>>node>>val;
                   update(ed[node],-a[node]);
                   update(ed[node],val); 
                   a[node]=val;          
           }
         }
  }
  return 0;
}


