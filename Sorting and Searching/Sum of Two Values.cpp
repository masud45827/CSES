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
    int n,x,i,j,y;
    cin>>n>>x;
    int a[n+2];
    map<int,int>m;
    for(i=1;i<=n;i++)
    {
      cin>>a[i];
      m[a[i]]=i;
    }
    for(i=1;i<=n;i++)
    {
    
      if(x>=a[i])
      {
        y=x-a[i];
        if(m[y]!=0&&i!=m[y])
        {
           cout<<i<<" "<<m[y]<<endl;
           return 0;
        }
      }
    }
    cout<<"IMPOSSIBLE"<<endl;
  }
 
}
