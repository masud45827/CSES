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
ull x;
vector<ull>g[300005];
ull  dp[300005];
void dfs(int node,int p)
{
  dp[node]=1;
   for(int u:g[node]){
    if(u==p) continue;
     dfs(u,node);
     dp[node]+=dp[u];
   }
}
int main()
{
  int t = 1, fac = 1;
  //cin >> t;
  while (t--)
  {
    int n,i,c=0,x,y,j,u,v;
    cin>>n;
    for(i=2;i<=n;i++)
    {
      cin>>u;
      g[u].pb(i);
      g[i].pb(u);
    }
  dfs(1,0);
  for(int i=1;i<=n;i++) cout<<dp[i]-1<<" ";
    cout<<endl;
}
  return 0;
}
