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
ll dp[2005];
int main() {
  int test = 1;
  //scanf("%d", &test);
  while (test--) {
        ll n,i,x,y,j,m=1000000007;
        cin>>n>>x;
         ll a[n+3];
          for(i=1;i<=n;i++) cin>>a[i];
           vector<ll>dp(x+2,0);
         dp[0]=1;
         
           for(j=1;j<=n;j++){
            for(i=0;i<=x;i++){
             if(i-a[j]>=0){
              dp[i]+=dp[i-a[j]];
                dp[i]%=m;
             }
           }
         }
      cout<<dp[x]<<endl;
  }
  return 0;
}
