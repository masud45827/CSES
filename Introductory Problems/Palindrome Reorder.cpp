#include<bits/stdc++.h>
using namespace std;
int a[29];
int main(){
    int t=1;
    //cin>>t;
    while(t--)
    {
       int n,i,j,x,c=0;
        string s;
        cin>>s;
        string s1="";
        for(i=0;i<s.size();i++)
        {
           a[s[i]-'A']++;
         if(a[s[i]-'A']==1) s1.push_back(s[i]);
        }
        
        for(i=0;i<27;i++)
        {
          if(a[i]%2==1) c++;
        }
        string ans1="";
        string ans2="";
        if(c>1) cout<<"NO SOLUTION"<<endl;
        else
        {
           char ch2;
           for(i=0;i<s1.size();i++)
           {
               if(a[s1[i]-'A']%2==1) ch2=s1[i];
               else 
               {
                for(j=1;j<=a[s1[i]-'A'];j++)
                {
                  if(j%2==1) ans1.push_back(s1[i]);
                  else ans2.push_back(s1[i]);
                }
               }
           }
            cout<<ans1;
           if(c==1)
           {
               for(j=1;j<=a[ch2-'A'];j++) cout<<ch2;
           }
           reverse(ans2.begin(),ans2.end());
           cout<<ans2<<endl;
        }
    }
}
