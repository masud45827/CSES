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
ll segment[10000],a[200005],seg;
void update(ll pos,ll val){
  segment[pos/seg]-=a[pos];
  a[pos]=val;
  segment[pos/seg]+=a[pos];
}
ll query(ll l, ll r){
  ll s=0;
   while(l<r&&l%seg!=0) s+=a[l++];
       while(l+seg<=r){
          s+=segment[l/seg];
          l+=seg;
       }
       while(l<=r) s+=a[l++];
       return s;
}
int main()
{
  int t = 1, fac = 1;
  //scanf("%d", &t);
  while (t--)
  {
    ll n,i,j,x,y,cur_seg=-1,q;
    cin>>n>>q;
      for(i=0;i<n;i++) cin>>a[i];
    seg=sqrt(n);
    for(i=0;i<n;i++){
      if(i%seg==0) cur_seg++;
       segment[cur_seg]+=a[i];
    }
    ll l,r,s=0;
    while(q--){
        cin>>x>>l>>r;
        l--;r--;
         if(x==2) cout<<query(l,r)<<endl;
         else update(l,r+1);
    }
  }
}
