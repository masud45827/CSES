#include<bits/stdc++.h>
using namespace std;
typedef     long long    ll;
typedef     vector<int> vi;
typedef     vector<long long> vl;
typedef     pair<int, int>pi;
typedef     pair<long long, long long>pl;
#define F   first
#define S   second
#define pb  push_back
#define     all(x)      x.begin() , x.end()
#define mp  make_pair
#define     REP(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
ll mod=1e9+7;
int dp[1002][1002];
int main() {
  int test = 1;
  //scanf("%d",&test) ;
  while (test--) 
  {
   int n,i,j,x,y,p,l,k;
   cin>>n;
    int  grid[n+2][n+2];
    char ch;
    for(i=1;i<=n;i++)
    {
      for(j=1;j<=n;j++)
      {
         cin>>ch;
         if(ch=='.') grid[i][j]=0;
         else grid[i][j]=1;
      }
    }
      for(i=1;i<=n;i++)
      {
        for(j=1;j<=n;j++)
        {
          if(i==1&&j==1)
          {
             dp[i][j]=1;
             if(grid[i][j]==1) dp[i][j]=0;
          }else
          {
             dp[i][j]=((dp[i-1][j]%mod)+(dp[i][j-1])%mod)%mod;
             if(grid[i][j]==1) dp[i][j]=0;
          }
        }
      }
      cout<<dp[n][n]<<endl;
  }
  return 0;
}
