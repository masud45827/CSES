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
ll BigMod(ll base, ll power, ll mod)
{
    ll a, b;
    if (power == 0) return 1;
    if (power % 2 == 1)
    {
        a = base % mod;
        b = BigMod(base, power - 1, mod) % mod;
        return ((a % mod) * (b % mod)) % mod;
    } else
    {
        a = BigMod(base, power / 2, mod) % mod;
        return ((a % mod) *(a % mod)) % mod;
    }
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        ll a, b, c, x, y,mod=1e9+7;
 
        cin >> a >>b;
        if (a+b+c==-3) break;
      // x = BigMod(b, c, mod-1);
        x = BigMod(a,b, mod);
        cout << x << endl;
    }
}
 
