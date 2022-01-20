#include<bits/stdc++.h>
using namespace std;
typedef     long long    ll;
typedef     vector<int> vi;
typedef     vector<long long> vl;
typedef     pair<int,int>pi;
typedef     pair<long long,long long>pl;
#define F   first
#define S   second
#define pb  push_back
#define     all(x)      x.begin() , x.end()
#define mp  make_pair
#define     REP(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
map<char,int>m;
int main()
{
	int t=1;
	//cin>>t;
	while(t--)
	{
           long long n,i,x,y,c=0;
           cin>>n;
           for(i=5;i<=n;i+=5)
           {
           	x=i;
             while(x%5==0)
             {
                c++;
                x=x/5;
             }
           }
           cout<<c<<endl;
 
	}
}
