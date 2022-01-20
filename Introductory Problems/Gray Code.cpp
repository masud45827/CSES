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
    int t=1;
   // scanf("%d",&t);
    while(t--)
    {
        int n,i,j;
        cin>>n;
         map<int,vector<int>>m;
        for(i=0;i<(1<<n);i++)
        {
            string s1;
            for(j=0;j<n;j++)
            {
                  if((i>>j)&1) m[i].pb(1);
                  else m[i].pb(0);
            }
            reverse(all(m[i]));
        }
        for(i=0;i<(1<<n);i++)
        {
            vi v;
            v.pb(m[i][0]);
            for(j=1;j<m[i].size();j++)
            {
                v.pb((m[i][j]^m[i][j-1]));
            }
            for(j=0;j<v.size();j++)
            {
                m[i][j]=v[j];
            }
            
        }
        for(i=0;i<(1<<n);i++)
        {
            for(j=0;j<m[i].size();j++)
            {
                cout<<m[i][j];
            }
            cout<<endl;
        }
    }
 
} 
