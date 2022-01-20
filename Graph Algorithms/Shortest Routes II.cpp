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
int main()
{
  int t = 1, fac = 1;
  //cin >> t;
  while (t--)
  {
        ll n,m,i,j,x,y,u,v,k,q,w;
      cin>>n>>m>>q;
      ll dis[n+2][n+2];
      for(i=0;i<=n;i++)
      {
        for(j=0;j<=n;j++) dis[i][j]=1e18;
      }
      for(i=0;i<=n;i++) dis[i][i]=0;
       for(i=0;i<m;i++)
       {
        cin>>u>>v>>w;
        dis[u][v]=min(dis[u][v],w);
        dis[v][u]=min(dis[u][v],w);
       }
     for(int mid=1;mid<=n;mid++) 
      {
        for(u=1;u<=n;u++)
        {
            for(v=1;v<=n;v++)
            {
                 dis[u][v]=min(dis[u][v],dis[u][mid]+dis[mid][v]);
            }
        }
      }
      while(q--)
      {
        int l,r;
        cin>>l>>r;
        if(dis[l][r]==1e18) cout<<"-1"<<endl;
        else cout<<dis[l][r]<<endl;
      }
    
    
  }
}
