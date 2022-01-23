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
int dp[1004][1004];
int main() {
  int test = 1, fac = 1;
  //scanf("%d", &test);
  while (test--) {
    int n, i, x, y, q, j;
    cin >> n >> q;
    string s;
    for (i = 1; i <= n; i++) {
      cin>>s;
      for (j = 1; j <= n; j++) {
        if (s[j-1]== '*') dp[i][j] = 1;
      }
    }
 
    for (i = 1; i <= n; i++) {
      for (j = 2; j <= n; j++) {
        dp[i][j] += dp[i][j - 1];
      }
    }
    for (j = 1; j <= n; j++) {
      for (i = 2; i <= n; i++) {
        dp[i][j] += dp[i - 1][j];
      }
    }
    while (q--) {
      int x1, x2, y1, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      int ans = dp[x2][y2]+dp[x1-1][y1-1] - dp[x2][y1 - 1] - dp[x1 - 1][y2];
      cout << ans << endl;
    }
  }
  return 0;
}

