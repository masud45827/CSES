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
int ck[1000005];
int main()
{
  int t = 1;
  //cin>>t;
  while (t--)
  {
    int n, i, x, y, mx = 0, c,j;
    cin>>n;
    int a[n + 3];
    for (i = 0; i < n; i++)
    {
      cin >> a[i];
      ck[a[i]]++;
      mx = max(mx, a[i]);
    }
    for (i = mx; i >= 1; i--)
    {
      c = 0;
      j = i;
      while (j <= mx)
      {
        if (ck[j] >= 2)
        {
          cout << i << endl; return 0;
        } else if (ck[j] == 1) c++;
        if (c >= 2)
        {
          cout << i << endl; return 0;
        }
        j+=i;
      }
 
    }
  }
}
