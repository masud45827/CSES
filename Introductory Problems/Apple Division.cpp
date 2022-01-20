#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long n,x,y,i,mn=INT_MAX,res=0,j;
  cin>>n;
  long long a[n+3];
  for(i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
  for (long long mask = 0; mask < (1 << n); ++mask) {
    long long res = 0;
    for (long long i = 0; i < n; ++i) {
      if ((mask >> i) & 1) res += a[i];
      else res -= a[i];
    }
    mn=min(abs(res),mn);
  }
  cout<<mn<<endl;
}
