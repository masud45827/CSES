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
int n,q,seg,res=0;
int ans[200005],a[200005],cnt[200005];
struct query{
   int l,r,index;
}Q[200005];
bool cmp(query i,query j){
   if((i.l/seg)!=(j.l/seg))return (i.l/seg)<(j.l/seg);
   else return i.r<j.r; 
}
 void remove(int index){
    cnt[a[index]]--;
     if(cnt[a[index]]==0)  res--;
 }
 void add(int index){
    cnt[a[index]]++;
     if(cnt[a[index]]==1)  res++;
 }
int main()
{
  int t = 1, fac = 1;
  //scanf("%d", &t);
  while (t--)
  {
    int i,j,l,r;
      res=0;
     scanf("%d%d",&n,&q);
     seg=sqrt(n);
      vi v;
     for(i=0;i<n;i++) {
      scanf("%d",&a[i]);
       v.pb(a[i]);  
    }
    sort(all(v));
    for(i=0;i<n;i++){
        int x=upper_bound(all(v),a[i])-v.begin();
        a[i]=x;
    }
     for(i=0;i<q;i++){
         scanf("%d %d",&l,&r);
         Q[i].l=l-1; Q[i].r=r-1;  Q[i].index=i;
     }
     sort(Q,Q+q,cmp);
      int curl=0,curr=-1;
     for(i=0;i<q;i++){
       l=Q[i].l; r=Q[i].r;
       while(curl<l) remove(curl++);
       while(curl>l) {
        add(--curl);
      }
      while(curr<r) add(++curr);
       while(curr>r){
         remove(curr--);
       }
       ans[Q[i].index]=res;
   }
    for(i=0;i<q;i++) printf("%d\n",ans[i]);
 
  }
return 0;
}
