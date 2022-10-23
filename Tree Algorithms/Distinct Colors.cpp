#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <iterator>
#include <bitset>
#include <assert.h>
#include <new>
#include <sstream>
#include <time.h>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define       FOR(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
#define setpr(x) cout<<setprecision(x)<<fixed
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
template <typename T> inline void Int(T &a) {
  bool minus = false; a = 0; char ch = getchar();
  while (true) { if (ch == '-' or (ch >= '0' && ch <= '9')) break; ch = getchar(); }
  if (ch == '-') minus = true; else a = ch - '0';
  while (true) { ch = getchar(); if (ch < '0' || ch > '9') break; a = a * 10 + (ch - '0'); }
  if (minus)a *= -1 ;
}
#ifdef LOCAL
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {cout << endl ;}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << ' ' ;
  err(++it, args...);
}
#else
#define error(args...)
#endif

const int N          = (int)4e5 + 5 ;
const int maxN       = (int)1e6 + 6 ;
const ll  Mod        = (ll)1e9 + 7 ;
const int inf        = (int)2e9 ;
const ll  Inf        = (ll)1e18 ;
const int mod        = (int)1e9 + 7 ;
const double EPS     = (double)1e-9 ;
const double PI      = (double)acos(-1.0) ;


inline int add(int a, int b, int mod) {a += b ; return a >= mod ? a - mod : a ;}
inline int sub(int a, int b, int mod) {a -= b ; return a < 0 ? a + mod : a ;}
inline int mul(int a, int b, int mod) {return (ll)a * b % mod ;}
vector<int>g[N + 2];
int start[N + 2], endd[N + 2], a[N + 3], dp[N + 3], cnt[N + 3],ans[N+3];
int tm1 = -1, n, seg, res = 0;
vi arr;
struct query {
  int l, r, i;
} Q[N];
void dfs(int node, int p){
  start[node] = ++tm1;
  arr.push_back(a[node]);
  for (int u : g[node]) {
    if (u == p) continue;
    dfs(u, node);
  }
  endd[node]=tm1;
}
void compress_arr(int a[]) {
  map<int, int>mp;
  int c, i;
  for (i = 1; i <= n; i++) mp[a[i]] = 0;
  c = 0;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    it->second = c;
    c++;
  }
  for (i = 1; i <= n; i++) a[i] = mp[a[i]];
}

bool cmp(query i, query j) {
  if ((i.l / seg) != (j.l / seg))return (i.l / seg) < (j.l / seg);
  else return i.r < j.r;
}
void remove(int index) {
  cnt[arr[index]]--;
  if (cnt[arr[index]] == 0)  res--;
}
void add(int index) {
  cnt[arr[index]]++;
  if (cnt[arr[index]] == 1)  res++;
}
int main() {
  int test = 1,fac=1;
  //cin>>test;
  while (test--) {
    cin >> n;
    int x,y,i,j;
    seg = sqrt(n);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    compress_arr(a);
    for (int i = 1; i < n; i++) {
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
      Q[i].l = start[i];
      Q[i].r = endd[i];
      Q[i].i = i;
    }
    sort(Q + 1, Q + 1 + n, cmp);
    int curl = 0, curr = 0;
    add(0);
    for (int i = 1; i <= n; i++) {
      int l = Q[i].l, r = Q[i].r;
      while (curl < l) remove(curl++);
      while (curl > l) add(--curl);
      while (curr < r) add(++curr);
      while (curr > r) remove(curr--);
      ans[Q[i].i] = res;
    }

    for (int i = 1; i <= n; i++){
      cout << ans[i] << " ";
    }
    cout<<endl;
  }
}
