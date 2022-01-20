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
#define mp  make_pair
#define       FOR(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
int main() {
  int test = 1;
  //scanf("%d", &test);
  while (test--) {
       ll  n,i,j,x,y,m=1000000007;
       cin>>n;
         vector<ll>dp(n+2,0);
         dp[0]=1;
       for(i=1;i<=n;i++) {
        for(j=1;j<=6&(i-j)>=0;j++){
          dp[i]+=(dp[i-j]%m);
          dp[i]%=m;
        }
       }
       cout<<dp[n]<<endl;
 
  }
  return 0;
}
