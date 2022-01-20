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
int dp[100003][101],a[100005],m,n;
int fun(int i,int x)
{
    if(i==n)   return 1;
    if(dp[i][x]!=-1) return dp[i][x];
    int res=0;
    if(a[i]==0)
    {
        if(i==0)
        {
            for(int j=1;j<=m;j++)
            {
                res+=fun(i+1,j)%mod;
                res%=mod;
            }
        }else
        {
          res+=fun(i+1,x)%mod;
          if(x-1>=1) 
            {
              res+=fun(i+1,x-1)%mod;
              res%=mod;
            }
          if(x+1<=m)
          {
           res+=fun(i+1,x+1)%mod;
           res%=mod;
         }
        }
    }else
    {
        if(abs(a[i]-x)>1) return 0;
        else 
          {
            res+=fun(i+1,a[i])%mod;
            res%=mod;
          }
    }
    dp[i][x]=res%mod;
return res;
 
}
int main()
{
  int t = 1, fac = 1;
  //cin >> t;
  while (t--)
  {
    memn(dp);
    int i,j,x,y;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    int res=fun(0,a[0]);
   printf("%d\n",res);
  }
}
