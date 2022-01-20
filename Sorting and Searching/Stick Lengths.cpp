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
int main()
{
  int t = 1;
  //cin >> t;
  while (t--)
  {
    ll n,i,s1=0,s2=0,j,x,y,mn=1e18,f,l,s=0;
    cin>>n;
     ll a[n+3];
     for(i=1;i<=n;i++) 
      {
        cin>>a[i];
        s2+=a[i];
      }
      sort(a+1,a+n+1);
      for(i=1;i<=n;i++)
      {
        f=i-1; l=n-i;
        x=f*a[i]; y=l*a[i];
        s=(x-s1);
        s1+=a[i];
        s2-=a[i];
        s+=(s2-y);
        //   cout<<x<<" "<<y<<endl;
        // cout<<s1<<" "<<s2<<endl;
        // cout<<s<<endl;
        mn=min(mn,s);
 
      }
      cout<<mn<<endl;
 
  }
}
