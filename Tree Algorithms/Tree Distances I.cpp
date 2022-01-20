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
#define mp  make_pair
#define       FOR(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
int  d1[200004],d2[200004],mx=-1,mxn;
 vector<int>g[200004];
  void dfs(int node,int p,int d){
       if(mx<d){
           mx=d;
           mxn=node;
       }
      for(int u:g[node]){
         if(p==u) continue;
        dfs(u,node,d+1);
      }
  }
  void dfs1(int node,int p,int d){
       if(mx<d){
           mx=d;
           mxn=node;
       }
        d1[node]=d;
      for(int u:g[node]){
         if(p==u) continue;
        dfs1(u,node,d+1);
      }
  }
  void dfs2(int node,int p,int d){
        d2[node]=d;
      for(int u:g[node]){
         if(p==u) continue;
        dfs2(u,node,d+1);
      }
  }
int main() {
  int test = 1;
  //scanf("%d", &test);
  while (test--) {
        int  n,i,j,x,y;
        cin>>n;
         for(i=1;i<n;i++) {
           cin>>x>>y;
           g[x].pb(y);
            g[y].pb(x);
         }
       dfs(1,0,0);
       mx=-1;
        dfs1(mxn,0,0);
        dfs2(mxn,0,0);
        for(i=1;i<=n;i++){
          cout<<max(d1[i],d2[i])<<" "; 
       //   cout<<d1[i]<<" "<<d2[i]<<endl;
    }
     cout<<endl;
  return 0;
        }
}
