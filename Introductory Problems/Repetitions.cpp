#include<bits/stdc++.h>
using namespace std;
int a[26+2];
int main(){
    int t=1;
    //cin>>t;
    while(t--)
    {
         string s;
         int mx=0;
         cin>>s;
         int i;
         int c=1;
         for(i=0;i<s.size()-1;i++)
         {
            if(s[i]==s[i+1]) c++;
            else
            {
              mx=max(c,mx);
              c=1;
            }
         }
         mx=max(c,mx);
         cout<<mx<<endl;
         
    }
}
