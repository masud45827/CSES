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
  //cin >> t;
  while (t--)
  {
    int n, i, x, y, j, l;
    cin >> n >> x;
    pair<int, int>p[n + 4];
    for (i = 1; i <= n; i++)
    {
      cin >> y;
      p[i].first = y;
      p[i].second = i;
    }
    sort(p+1, p + n+1);
    for (i = 1; i<= n; i++)
    {
      int l = 1, r = n;
   
      while (l != r)
      {
         y = x - p[i].first;
        ll k = (p[l].first + p[r].first);
        if (k == y && p[l].second != p[i].second && p[r].second != p[i].second)
        {
          cout << p[i].second << " " << p[l].second << " " <<p[r].second<< endl;
          return 0;
        }
        if (k < y) l++;
        else r--;
      }
    }
      cout << "IMPOSSIBLE" << endl;
    }
 
  }
