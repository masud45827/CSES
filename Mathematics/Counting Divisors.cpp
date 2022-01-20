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
int g[1000003];
int main()
{
  int t,i,j;
   for(i=1;i<=1000000;i++)
   {
    for(j=i;j<=1000000;j+=i)
    {
      g[j]++;
    }
   }
  cin>>t;
  while(t--)
  {
    int n,x,y;
    cin>>n;
    cout<<g[n]<<endl;
 
  }
}
