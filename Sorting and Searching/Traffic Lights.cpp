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
    int t = 1;
    //cin >> t;
    while (t--)
    {
        int n,i,j,x,y,m,mx;
        cin>>n>>m;
      set<int>s;
      vi v;
       s.insert(ll(0)); s.insert(n);
        multiset<int>dis;
        dis.insert(n);
       for(i=0;i<m;i++){
        cin>>x;
    auto it1 = s.upper_bound(x),it2 = it1; --it2;
     dis.erase(dis.find(*it1-*it2));
     dis.insert(x-*it2); dis.insert(*it1-x);
     s.insert(x);
     auto ans = dis.end(); --ans;
     v.pb(*ans);
      
       }
       for(i=0;i<v.size();i++) cout<<v[i]<<" ";
        cout<<endl;
       
    }
 
}
