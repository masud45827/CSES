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
  //cin>>t;
  while (t--)
  {
    int n, i, x, y, l, r, mid, ans;
    cin >> n;
    vi v;
    for (i = 0; i < n; i++)
    {
      cin >> x;
       l=0; r=v.size()-1;
        mid=(l+r)/2;
         while(l<=r)
         {
          mid=(l+r)/2;
          if(v[mid]>x)  r=mid-1;
          else l=mid+1;
         }
         if(l==v.size()) v.pb(x);
         else v[l]=x;
 
    }
    cout << v.size() << endl;
  }
}
