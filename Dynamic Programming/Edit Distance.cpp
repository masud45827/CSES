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
int main() {
  int test = 1, fac = 1;
  //scanf("%d", &test);
  while (test--) {
    int i,j,x,y,n,m;
    string s1,s2;
    cin>>s1>>s2;
     n=s1.size(); m=s2.size();
      int dp[n+4][m+3];
    for(i=0;i<=n;i++){
      for(j=0;j<=m;j++){
          if(i==0) dp[i][j]=j;
          else if(j==0) dp[i][j]=i;
          else if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
           else dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
      }
    }
    cout<<dp[n][m]<<endl;
  }
  return 0;
}

