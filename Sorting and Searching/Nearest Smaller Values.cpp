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
    ll n, i, j, x, y;
    cin >> n;
    int a[n + 3];
    pair<int,int>p;
    vi v;
    stack < pair<int, int>>s;
    for (i = 1; i <= n; i++)
    {
       cin>>a[i];
       while(s.size()!=0)
       {
        p=s.top();
         if(p.first>=a[i])
         {
           s.pop();
         }else break;
       }
        if(s.size()==0) v.pb(0);
        else 
        {
          p=s.top();
          v.pb(p.second);
        }
        s.push({a[i],i});
    }
    for(i=0;i<v.size();i++) cout<<v[i]<<" ";
      cout<<endl;
  }
}
