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
  int t = 1;
  //scanf("%d", &t);
  while (t--)
  {
     ll n,i,x,y,m,k,l,r,mid,c=0,ans;
     cin>>n>>m>>k;
     vl v1,v2;
     for(i=0;i<n;i++) 
     {
        cin>>x; 
        v1.pb(x);
     }
      for(i=0;i<m;i++) 
     {
        cin>>x; 
        v2.pb(x);
     }
  sort(all(v1));
  sort(all(v2));
  l=0;
  for(i=0;i<v1.size();i++)
  {
   r=v2.size()-1;
    
    x=v1[i]-k; y=v1[i]+k;
    ans=-1;
    if(v2.size()==0) break;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(v2[mid]>=x&&v2[mid]<=y)
        {
           ans=mid;
            r=mid-1;
        }else if(v2[mid]>y) r=mid-1;
        else  l=mid+1;
    }
    if(ans!=-1) 
        {
           // cout<<i<<" ";
            c++;
            l=ans+1;
              
        }
  }
  cout<<c<<endl;
 
  return 0;
 
}
}
