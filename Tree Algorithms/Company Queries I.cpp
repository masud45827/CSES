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
vector<int>g[200004];
 int dis[200005];
 int spt[200004][21];
 void dfs(int node ,int p){
 	 spt[node][0]=p;
 	 for(int i=1;i<20;i++){
 	 	 if(spt[node][i-1]!=-1){
 	 	 	spt[node][i]=spt[spt[node][i-1]][i-1];
 	 	 }
 	 }
 	 for(int u:g[node]) {
 	 	 if(u==p) continue;
 	 	 dfs(u,node);
 	 }
 }
 int query(int node,int k){
  if(node==-1||k==0) return node;
  for(int i=19;i>=0;i--){
  	 if(k>=(1<<i)){
  	 	return query(spt[node][i],k-=(1<<i));
  	 }
  }
 }
int main() {
  int t = 1, fac = 1;
 // scanf("%d", &t);
  while (t--) {
     int n,i,j,x,y,u,v,m,q;
     cin>>n>>q;
      for(i=2;i<=n;i++){
      	cin>>u;
      	 g[i].pb(u);
      	  g[u].pb(i);
      } 
      memn(spt);
      dfs(1,-1);
 
     while(q--){
     	  cin>>u>>v;
     	  x=query(u,v);
     	  cout<<x<<endl;
     }
 
  }
}
