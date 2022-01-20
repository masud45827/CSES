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
//cout << fixed << setprecision(15);
#define     memn(a)     memset(a , -1 ,sizeof a)
int main()
{
  int t = 1;
// cin >> t;
  while (t--)
  {
    int n, i, x, y, l, r, mid, mx = 0, ans = 0;
    cin >> n;
    vector<pair<int, int>>p;
    for (i = 0; i < n; i++)
    {
      cin >> x >> y;
      p.pb({x, 1});
      p.pb({y, -1});
    }
    sort(all(p));
    // for(i=0;i<p.size();i++) cout<<p[i].second<<" ";
    //   cout<<endl;
    for (i = 0; i < p.size(); i++)
    {
      ans += p[i].second;
      mx = max(ans, mx);
    }
    cout << mx << endl;
  }
 
}
