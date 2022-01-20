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
char ch[1004][1004];
void dfs(int i,int j)
{
     if(ch[i-1][j]=='.')
     {
        ch[i-1][j]='#';
        dfs(i-1,j);
     }
     if(ch[i+1][j]=='.')
     {
        ch[i+1][j]='#';
        dfs(i+1,j);
     }
     if(ch[i][j-1]=='.')
     {
        ch[i][j-1]='#';
        dfs(i,j-1);
     }
     if(ch[i][j+1]=='.')
     {
        ch[i][j+1]='#';
        dfs(i,j+1);
     }
 
}
int main()
{
    int t = 1, fac = 1;
    //  scanf("%d", &t);
    while (t--)
    {
        int n,m,i,x,y,c=0,j;
        cin>>n>>m;
        for(i=0;i<=m+1;i++) ch[0][i]='#';
         for(j=0;j<=n+1;j++) ch[j][i]='#';
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=m;j++) cin>>ch[i][j];
            }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(ch[i][j]=='.') 
                    {
                        c++;
                        dfs(i,j);
                    }
            }
        }
        cout<<c<<endl;
    }
}
