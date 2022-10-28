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
int vis[200005], subt[200003];
vector<int>g[200004];
int n;
void st(int node, int p) {
  subt[node] = 1;
  for (auto u : g[node]) {
    if (u == p ) continue;
    st(u, node);
    subt[node] += subt[u];
  }
}
int centroid(int node, int p) {
  for (auto u : g[node]) {
    if(u==p) continue;
    if (subt[u] > (n / 2)) {
      return centroid(u, node);
    }
  }
  return node;
}
int main() {
  int t = 1, fac = 1;
  //scanf("%d", &t);
  while (t--) {
    int  i, x, y, z, j, u, v;
    cin >> n;
    for (i = 1; i < n; i++) {
      cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    st(1, -1);
    u = centroid(1, -1);
    cout << u << endl;
  }

}
