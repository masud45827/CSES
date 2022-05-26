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
 
const int N          = (int)6e5 + 5 ;
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
map<int,  int >::iterator it;
int ar[N + 1];
int mp[N+2];
void update(int i, int x) {
  while (i <= N) {
    ar[i] += x;
    i += (i & (-i));
  }
}
int query(int x) {
  int sum = 0;
  while (x > 0) {
    sum += ar[x];
    x -= (x & (-x));
  }
  return sum;
}
struct Val {
  char c;
  int l, r;
};
int main() {
  IOS;
  int test = 1, fac = 1;
// cin >> test;
  while (test--) {
    int n, i, j, x, y, q;
    cin >> n >> q;
    struct Val p[q + 1];
    int a[n + 2];
    vi v;
    for (i = 1; i <= n; i++) {
      cin >> a[i];
      v.pb(a[i]);
    }
    char ch;
    int l, r;
    for (i = 1; i <= q; i++) {
      cin >> ch >> l >> r;
      p[i].c = ch; p[i].l = l; p[i].r = r;
      if (ch == '!') v.pb(r);
      else {
        v.pb(l); v.pb(r);
      }
    }
    sort( v.begin(), v.end());
    v.erase( unique( v.begin(), v.end() ), v.end());
     int cn=1;
    for (i = 1; i <= n; i++) {
       x=upper_bound(all(v),a[i])-v.begin();
      update(x, 1);
    }
    for (i = 1; i <= q; i++) {
      ch = p[i].c;
      l = p[i].l;  r = p[i].r;
      if (ch == '!') {
        x=upper_bound(all(v),a[l])-v.begin();
        update(x,-1);
        a[l] = r;
        x=upper_bound(all(v),a[l])-v.begin();
        update(x, 1);
      } else {
        //cout << query(mp[r]) - query(mp[l] - 1) << endl;
        x=upper_bound(all(v),l)-v.begin();
        y=upper_bound(all(v),r)-v.begin();
        x = query(y) - query(x- 1);
        cout << x << endl;
      }
    }
  }
  return 0;
}
