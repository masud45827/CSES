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
#define mod 1000000007
#define       FOR(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
int main()
{
  int t = 1, fac = 1, i, j;
  //scanf("%d", &t);
  while (t--)
  {
    int n,i,x,y;
    cin>>n;
    vector<int>dp(n+2,1e9);
    dp[0]=0;
    for(i=1;i<=n;i++)
    {
      for(char ch:to_string(i))
      {
         dp[i]=min(dp[i],dp[i-(ch-'0')]+1);
      }
    }
   cout<<dp[n]<<endl;
  }
  return 0; 
}
