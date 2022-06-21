#include<bits/stdc++.h>
using namespace std;
typedef     long long    ll;
//typedef     unsigned long long    ull;
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
ll hash1[1000001], inv[1000001], hash2[1000001];
ll p = 241;
ll bigmod ( ll a, ll p, ll m) {
  ll res = 1;
  ll x = a;
  while (p) {
    if (p & 1) {
      res = (res * x) % m;
    }
    x = (x * x) % m;
    p = p >> 1;
  }

  return res;
}
ll get_hash(ll l, ll r) {
  ll has = hash1[r];
  if (l > 0) has = (has + mod - hash1[l - 1]) % mod;
  has = (has * inv[l]) % mod;
  return has;
}
ll get_hash1(ll l, ll r) {
  ll has = hash2[r];
  if (l > 0) has = (has + mod - hash2[l - 1]) % mod;
  has = (has * inv[l]) % mod;
  return has;
}
int main() {
  int test = 1, fac = 1;
  //scanf("%d", &test);
  while (test--) {
    ll n, i, j, x, y, pp = 1;
    string s;
    cin >> s;
    n = s.size();
    inv[0] = 1;
    hash1[0] = (s[0] - 'a' + 1);
    for (i = 1; i < n; i++) {
      pp = (pp * p) % mod;
      inv[i] = bigmod(pp, mod - 2, mod);
      hash1[i] = (hash1[i - 1] + (s[i] - 'a' + 1) * pp) % mod;

    }
    reverse(all(s));
    pp = 1;
    hash2[0] = (s[0] - 'a' + 1);
    for (i = 1; i < n; i++) {
      pp = (pp * p) % mod;
      inv[i] = bigmod(pp, mod - 2, mod);
      hash2[i] = (hash2[i - 1] + (s[i] - 'a' + 1) * pp) % mod;
    }
    vi od, ev;
    for (i = 1; i <= n; i++) {
      if (i % 2) od.pb(i);
      else ev.pb(i);
    }
    ll l = 0, r = od.size() - 1, mid, ans=-1,in;
    while (l <= r) {
      mid = (l + r) / 2;
      x = od[mid];
      ll prev = 0;
      ll f=0;
      for (i = x - 1; i < n; i++) {
        ll x1= get_hash(prev, i);
          y = get_hash1(n-prev-x,n-1-prev);
          //error(prev,i);
         //error(x,n-1-prev,n-prev-x);
        if(x1==y){
          f=1; break;
        }
        prev++;
      }
     if(f){
      in=i;
     // error(x);
       ans=od[mid];
        l=mid+1;
     }else r=mid-1;
    }
    
     l = 0, r = ev.size() - 1;
     ll ans1=-1,in1;
    while (l <= r) {
      mid = (l + r) / 2;
      x = ev[mid];
      ll prev = 0;
      ll f=0;
      for (i = x - 1; i < n; i++) {
        ll x1= get_hash(prev, i);
          y = get_hash1(n-prev-x,n-1-prev);
         // error(prev,i);
         //error(x,n-1-prev,n-prev-x);
        if(x1==y){
          f=1; break;
        }
        prev++;
      }
     if(f){
      // error(x,i);
      in1=i;
       ans1=x;
        l=mid+1;
     }else r=mid-1;
    }
    if(ans1>ans) {
      in=in1;
      ans=ans1;
    }
    reverse(all(s));
    for(i=in-ans+1;i<=in;i++)cout<<s[i];
    cout<<endl;
    
  }
  return 0;
}

