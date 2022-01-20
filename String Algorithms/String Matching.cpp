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
//#define mp  make_pair
#define     REP(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
vector<int> lps1(string p)
{
    vector<int>lps(p.size());
    int index =0;
    for(int i=1;i<p.size();)
    {
      if(p[index]==p[i])
      {
        lps[i]=1+index;
        i++; index++;
      }else
      {
        if(index!=0) index=lps[index-1];
        else lps[i]=index, i++;
      }
 
    }
    return lps;
}
 void kmp(string s,string p)
 {
  int f=0,c=0;
     vector<int>lps=lps1(p);
     int i=0,j=0;
     while(i<s.size())
     {
      if(s[i]==p[j])
      {
        i++;j++;
      }else 
      {
        if(j!=0) j=lps[j-1];
        else i++;
      }
      if(j==p.size()) 
      {
        f=1;
        c++;
        j=lps[j-1];
      }
     }
    cout<<c<<endl;
 }
int main()
{
  int t = 1, fac = 1;
  //cin >> t;
  while (t--)
  {
    string  s,p;
   cin>>s>>p;
    kmp(s,p);
  }
}
