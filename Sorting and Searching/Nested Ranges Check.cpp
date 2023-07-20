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
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less_equal<T>,
                        rb_tree_tag, tree_order_statistics_node_update>;
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

const int N          = (int)1e6;
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
int main() {
  IOS;
  int test = 1, fac = 1;
  //cin >> test;
  while (test--) {
    ll n, i, j, x, y, l, r;
    cin >> n;
    pair<ll, pl>p[n + 2];
    p[0].F = -5;
    vector<ll>ans(n + 4, 0), ans1(n + 3, 0);
    set<ll>s;
    map<ll, vl>mp;
    for (i = 1; i <= n; i++) {
      cin >> p[i].F >> p[i].S.F;
      mp[p[i].F].pb(p[i].S.F);
      s.insert(p[i].F);
      p[i].S.S = i;
    }
    sort(p + 1, p + n + 1);
    oset<ll>st;
    for (ll x : s) sort(all(mp[x]));
    queue<ll>q;
    for (i = 1; i <= n; i++) {
      x = p[i].F; if (mp[x].size() == 1) continue;
      y = p[i].S.F;
      ll index = p[i].S.S;
      l = 0; r = mp[x].size() - 1;
      ll res = 0, mid;
      while (l <= r) {
        mid = (l + r) / 2;
        if (mp[x][mid] <= y) {
          res = mid;
          l = mid + 1;
        } else r = mid - 1;
      }
      ll val = mp[x].size() - res - 1;
      ans1[index] += val;
      ans[index] += res;
    }
    // for(int x:mp[1]) cout<<x<<" ";
    // cout<<endl;
    for (i = n; i >= 1; i--) {
      ll index = p[i].S.S;
      l = p[i].F; r = p[i].S.F;
      x = st.order_of_key(r + 1);
      ans[index] += x;
      if (p[i - 1].F != l) {
        st.insert(r);
        while (!q.empty()) {
          st.insert(q.front());
          q.pop();
        }
      } else q.push(r);
    }
    st.clear();
    for (i = 1; i <= n; i++) {
      ll index = p[i].S.S;
      l = p[i].F; r = p[i].S.F;
      x = st.size() - st.order_of_key(r);
      ans1[index] += x;
      if (p[i + 1 ].F != l) {
        st.insert(r);
        while (!q.empty()) {
          st.insert(q.front());
          q.pop();
        }
      } else q.push(r);
    }
    for (i = 1; i <= n; i++)cout << min(1LL,ans[i]) << " ";
    cout << endl;
    for (i = 1; i <= n; i++)cout << min(1LL,ans1[i]) << " ";
    cout << endl;
  }
  return 0;
}

