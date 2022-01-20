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
  int t = 1, f = 1;
// cin >> t;
  while (t--)
  {
    ll n, i, j, x, y, s = 0, ans = 0;
    cin >> n;
    ll a[n + 3];
    vector<int>v(n + 2);
    v[0]=1;
    for (i = 0; i < n; i++)
    {
      cin >> x;
      s += x;
      v[(s % n+n)%n]++;
    }
    for (i = 0; i < n; i++)
    {
      x=v[i];
      ans += (x * (x - 1)) / 2;
    }
    cout << ans << endl;
 
  }
 
}
