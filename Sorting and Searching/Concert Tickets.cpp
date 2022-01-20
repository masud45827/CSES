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
#define     rall(x)      x.rbegin() , x.rend()
#define mp  make_pair
#define     REP(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
int main()
{
  int t = 1;
  //cin>>t;
  while (t--)
  {
    ll n,i,j,x,y,m;
    cin>>n>>m;
    multiset<ll>s;
    for(i=0;i<n;i++)
      {
        cin>>x;
        s.insert(x);
      }
      for(i=0;i<m;i++)
      {
         cin>>x;
          auto it=s.upper_bound(x);
          if(it==s.begin()) cout<<"-1"<<endl;
          else
          {
            cout<<*(--it)<<endl;
            s.erase(it);
          }
      }
 
  }
}
