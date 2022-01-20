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
#define       FOR(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long n, i, x, y, ans;
		cin >> x >> y;
		if (x < y)
		{
			if(y%2==0)
			{
			ans = (y - 1) * (y - 1)+x;
		        }else
		        {
                           ans=(y*y)-x+1;
		        }
			cout << ans << endl;
		} else
		{
			 if(x%2==0)
			 {
			 	ans=(x*x)-y+1;
			 }else	{ans = (x - 1) * (x - 1) + y;}
			cout << ans << endl;
		}
	}
}
