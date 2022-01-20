#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,x,y,j,s1=0,s2=0;
	cin>>n;
	vector<int>v1,v2;
	if((n/2)%2==1&&n%2!=1||n==1)
	{
         cout<<"NO"<<endl;
        }
	else
	{
		if(n%2==1&&(n/2)%2==0) 
		{
			cout<<"NO"<<endl;
			return 0;
		}
		s1=n;s2=n-1;
		v1.push_back(n);
		v2.push_back(n-1);
	    for(i=n-2;i>=1;i-=2)
	    {
	    	if(i==1) 
	    	{
	    		if(s1<s2) v1.push_back(i);
	    		else v2.push_back(i);
	    		break;
	    	}
              if(s1<s2)
              {
              	v1.push_back(i);
              	v2.push_back(i-1);
              	s1+=i;
              	s2+=i-1;
              	
              }else 
              {
              	v2.push_back(i);
              	v1.push_back(i-1);
              	s1+=i-1;
              	s2+=i;
              }
             
	    }
	       sort(v1.begin(),v1.end());
	    sort(v2.begin(),v2.end());
	    cout<<"YES"<<endl;
	    cout<<v1.size()<<endl;
	    for(int k:v1) cout<<k<<" ";
	    	cout<<endl;
	    cout<<v2.size()<<endl;
	      for(int k:v2) cout<<k<<" ";
	    	cout<<endl;
	  
	}
	
 
}
