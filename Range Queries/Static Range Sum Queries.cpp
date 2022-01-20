#include<bits/stdc++.h>
using namespace std;
typedef     long long    ll;
typedef     unsigned long long    ull;
typedef     vector<int> vi;
typedef     vector<long long> vl;
typedef     pair<int, int>pi;
typedef     pair<long long, long long>pl;
#define F   first
#define S   second
#define pb  push_back
#define     all(x)      x.begin() , x.end()
#define mod 1000000007
#define       FOR(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
int main()
{
    int t = 1, fac = 1;
    //scanf("%d", &t);
    while (t--)
    {
        ll n,i,x,y,s=0,q;
        cin>>n>>q;
        ll a[n+3];
        a[0]=0;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
             a[i]+=a[i-1];
        }
        while(q--)
        {
            ll l,r;
            cin>>l>>r;
            cout<<a[r]-a[l-1]<<endl;
        }
 
 
    }
}
