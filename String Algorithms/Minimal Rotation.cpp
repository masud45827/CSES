
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
#define mod1 100000007
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
ll hash1[9000005],hash2[9000005], inv[9000005],inv1[9000005];
ll p = 31,p1=59;
ll bigmod ( ll a, ll p, ll m){
  ll res = 1;
  ll x = a;
  while ( p )
  {
    if ( p & 1 )
    {
      res = (res*x)%m;
    }
    x = (x*x)% m;
    p = p >> 1;
  }

  return res;
}
ll get_hash(ll l, ll r) {
  ll has = hash1[r];
   if(l>0) has=(has+mod-hash1[l-1])%mod;
  has=(has*inv[l])%mod;
  return has;
}
ll get_hash1(ll l, ll r) {
  ll has = hash2[r];
   if(l>0) has=(has+mod1-hash2[l-1])%mod1;
  has=(has*inv1[l])%mod1;
  return has;
}
int main() {
  int test = 1, fac = 1;
  //scanf("%d", &test);
  while (test--) {
    ll n, i, j, x, y, pp = 1;
    string s;
    cin >> s;
    ll n1=s.size();
    s+=s;
    n = s.size();
    inv[0] = 1;
    hash1[0] = (s[0] - 'a'+ 1);
    for (i = 1; i < n; i++) {
      pp = (pp*p)%mod;
      inv[i] = bigmod(pp,mod-2,mod);
      hash1[i] = (hash1[i - 1]+(s[i] - 'a' + 1) * pp)%mod;
    }
    inv1[0] = 1;
     pp=1;
    hash2[0] = (s[0] - 'a'+ 1);
    for (i = 1; i < n; i++) {
      pp = (pp*p1)%mod1;
      inv1[i] = bigmod(pp,mod1-2,mod1);
      hash2[i] = (hash2[i - 1]+(s[i] - 'a' + 1) * pp)%mod1;
    }
     ll k=0;
     for(i=1;i<n1;i++){
       ll l=0,r=n1-1,mid,ans=-1;
        while(l<=r){
           mid=(l+r)/2;
           if(get_hash(k,k+mid)==get_hash(i,i+mid)&&get_hash1(k,k+mid)==get_hash1(i,i+mid)){
             ans=mid;
             l=mid+1;
           }else r=mid-1;
        }
         ans++;
          if(s[i+ans]<s[k+ans]) k=i;
     }
     cout<<s.substr(k,n1)<<endl;
  }
  return 0;
}

