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
       cin>>n>>x;
       vector<ll>dp(x+2,1000000000);
        ll a[n+3];
        dp[0]=0;
       for(i=1;i<=n;i++) cin>>a[i];
        for(i=1;i<=n;i++){
           for(j=1;j<=x;j++){
             if(j-a[i]>=0){
                dp[j]=min(dp[j],dp[j-a[i]]+1);
             }
           }
        }
         if(dp[x]==1e9) dp[x]=-1;
        cout<<dp[x]<<endl;
 
  }
  return 0;
}
