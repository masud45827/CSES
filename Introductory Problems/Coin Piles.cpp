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
  int t=1;
  cin>>t;
  while(t--)
  {
     ll n,i,j,x,y,a,b;
     cin>>a>>b;
     if((2*a-b)>=0&&(2*a-b)%3==0&&(2*b-a)>=0&&(2*b-a)%3==0) cout<<"YES"<<endl;
     else cout<<"NO"<<endl;
 
 }
 return 0;
}
