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
 
const int N          = (int)2e5 + 5 ;
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
ll a[N + 4];
int blockSize = 450;
ll lazy[450], blockSum[450];
int cnt[450];
void lazy_update(int in) {
  blockSum[in] = 0;
  ll sum = lazy[in];
  for (int i = in * blockSize; i < (in + 1)*blockSize; i++) {
    a[i] += sum;
    sum += cnt[in];
    blockSum[in] += a[i];
  }
  lazy[in] = 0; cnt[in] = 0;
}
void update(int l, int r) {
  int L = l / blockSize, R = r / blockSize, k = 1;
  if (L == R) {
    for (int i = l; i <= r; i++) {
      a[i] += k;
      blockSum[L] += k;
      k++;
    }
    return;
  }
  lazy_update(L);
  for (int i = l; i < (L + 1)*blockSize; i++) {
    a[i] += k;
    blockSum[L] += k;
    k++;
  }
  for (int i = L + 1; i < R; i++) {
    lazy[i] += k;
    cnt[i]++;
    k += blockSize;
  }
  lazy_update(R);
  for (int i = R * blockSize; i <= r; i++) {
    a[i] += k;
    blockSum[R] += k;
    k++;
  }
}
ll fun(ll s, int d) {
  int n = blockSize ;
  ll ans = n * s;
  ll x = ((n - 1) * n) / 2;
  x *= d;
  ans += x;
  return ans;
}
ll query(int l, int r) {
  int L = l / blockSize, R = r / blockSize;
  ll sum = 0;
  if (L == R) {
    lazy_update(L);
    for (int i = l; i <= r; i++) {
      sum += a[i];
    }
    return sum;
  }
  lazy_update(L);
  for (int i = l; i < (L + 1)*blockSize; i++) {
    sum += a[i];
  }
  for (int i = L + 1; i < R; i++) {
    sum += blockSum[i] + fun(lazy[i], cnt[i]);
  }
  lazy_update(R);
  for (int i = R * blockSize; i <= r; i++) {
    sum += a[i];
  }
  return sum;
}
 
int main() {
  int test = 1, fac = 1;
  //cin>>test;
  while (test--) {
    int n, i, j, x, y, q;
    cin >> n >> q;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      blockSum[i / blockSize] += a[i];
    }
    while (q--) {
      int t, l, r;
      cin >> t;
      cin >> l >> r;
      if (t == 1) {
        update(l - 1, r - 1);
      } else {
        ll ans = query(l - 1, r - 1);
        cout << ans << endl;
      }
    }
  }
  return 0;
}
