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
int mx=0,lastnode;
vector<int>g[300005];
int  visit[300005];
void dfs(int node,int d)
{
  visit[node]=1;
  if(d>mx) 
    {
      mx=d;
      lastnode=node;
    }
   for(int u:g[node]){
       if(visit[u]==0) dfs(u,d+1);
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
      cin>>u>>v;
      g[u].pb(v);
      g[v].pb(u);
    }
    mx=-1;
  dfs(1,0);
   mem(visit);
   mx=-1;
    dfs(lastnode,0);
    cout<<mx<<endl;
  
}
  return 0;
}
