#include<bits/stdc++.h>
using namespace std;
int main(){
    int t=1;
    //cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        cout<<n<<" ";
             while(n!=1)
             {
                if(n%2==1) n=n*3+1;
                else n=n/2;
                cout<<n<<" ";
             }
             cout<<endl;
    }
}
